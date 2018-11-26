#include "respondercontroller.h"
#include "utility.h"
#include "commondata.h"
#include "appinfo.h"
#include "appinfofunc.h"

ResponderController* ResponderController::m_instance = NULL;
const QString ResponderController::TAG="ResponderController:";
ResponderController::ResponderController(QObject *parent) : QObject(parent)
{

}

void ResponderController::dealNetData(QJsonObject object)
{

}
void ResponderController::dealWithWebSocketResponce(QString jsonStr) {
    QJsonObject object = Utility::getJsonObjectFromString(jsonStr);
    qDebug()<<TAG<<"11111111-ssd start deal json object"<<QThread::currentThread();
    QString type = object[CommonData::JSON_COMMAND_TYPE].toString();
    if(type.compare("Opaque",Qt::CaseInsensitive))
    {
        //透传
        dealNetData(object.value("cubemessage").toObject());
    }
    else if(type.compare("OnlineStatus",Qt::CaseInsensitive))
    {
        //boolean state = object.optBoolean("online");
        boolean state = object.contains("online");
        int online = state ? 1 : 0;
        //Loger.print(TAG, "ssd online : " + online, Thread.currentThread());
        qDebug()<<TAG<<"ssd online:"<<online<<QThread::currentThread();
        //AppInfo info = AppInfoFunc.getCurrentUser(mContext);
        AppInfo *info = AppInfoFunc::getCurrentUser();
        if (info->online != online) {
            info->online = online;
           // new AppInfoFunc(ConfigCubeDatabaseHelper::getIn(mContext)).updateAppInfoByUserName(info.username, info);
            //不在线状态转到在线状态
            if (online == 1) {
                //SocketController.newInstance(mContext).setRequestAfterLogin();
            }
                        }
    }
    else
    {

    }

//        try {
//            JSONObject object = new JSONObject(jsonStr);
//            Loger.print(TAG, "11111111-ssd start deal json object", Thread.currentThread());
//            String type = object.getString(CommonData.JSON_COMMAND_TYPE);
//            if (type.equals("Opaque")) {
//                //透传
//                dealNetData(object.get("cubemessage"));
//            } else if ("OnlineStatus".equalsIgnoreCase(type)) {
//                boolean state = object.optBoolean("online");
//                int online = state ? 1 : 0;
//                Loger.print(TAG, "ssd online : " + online, Thread.currentThread());
//                AppInfo info = AppInfoFunc.getCurrentUser(mContext);
//                if (info.online != online) {
//                    info.online = online;
//                    new AppInfoFunc(ConfigCubeDatabaseHelper.getInstance(mContext)).updateAppInfoByUserName(info.username, info);
//                    //不在线状态转到在线状态
//                    if (online == 1) {
//                        SocketController.newInstance(mContext).setRequestAfterLogin();
//                    }
//                }
//            } else {
//                if (object.has(CommonData.JSON_COMMAND_DATA)) {
//                    JSONObject data = (JSONObject) object.get(CommonData.JSON_COMMAND_DATA);
//                    JSONObject content = (JSONObject) data.get("content");
//                    Loger.print(TAG, "ssd start write SQL", Thread.currentThread());
//                    dealNetData(content);
//                } else {
//                    Loger.print(TAG, "ssd dealWithWebSocketResponce error", Thread.currentThread());
//                    EventBus.getDefault().post(new CubeBasicEvent(CubeEvents.CubeBasicEventType.WEBSOCKET_EVENT, false, "响应数据格式错误，请重试"));
//                }
//            }
//        } catch (JSONException e) {
//            Loger.print(TAG, "ssd dealWithWebSocketResponce jSON error", Thread.currentThread());
//            e.printStackTrace();
//            return;
//        }
}

QString ResponderController::getTAG()
{
              return TAG;
}
