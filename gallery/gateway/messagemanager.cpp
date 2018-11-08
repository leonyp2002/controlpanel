#include "messagemanager.h"

#include "appinfofunc.h"
const QString MessageManager::TAG ="MessageManager: ";
ulong MessageManager::sequenceId = 0;
MessageManager::MessageManager(QObject *parent) : QObject(parent)
{

}

QString MessageManager::getTAG()
{
    return TAG;
}

ulong MessageManager::getSequenceId()
{
    return sequenceId;
}

void MessageManager::setSequenceId(ulong value)
{
    sequenceId = value;
}


/********************************************* private method *********************************/
/**
 * 用于组织最后发送的数据
 *
 * @param items
 * @return
 */
QString MessageManager::sendStrWithBody(QHash<QString, QVariant> items) {
    //if (LoginController.getInstance(mContext).getLoginType() == LoginController.LOGIN_TYPE_CONNECT_WIFI) {
//    if(1){
//        Gson gson = new Gson();
//        String result = gson.toJson(items);
//        return result;
//    }
    /* cloud part, no need for control pannel
    else {
        String deviceid = getDeviceId();
        if (!deviceid.equals("") && !deviceid.equals("0")) {
            Map<String, Object> send = new HashMap<String, Object>();
            send.put("type", "Opaque");
            send.put("deviceId", deviceid);
            send.put("cubemessage", items);
            Gson gson = new Gson();
            String result = gson.toJson(send);

            return result;
        } else {
            return null;
        }
    }*/
    if(1)
    {
        QString result = QJsonDocument::fromVariant(items).toJson();
        qDebug()<<TAG<<result;
        return result;
    }

}
/**
 * 获取绑定设备的device id
 *
 * @return
 */
QString MessageManager::getDeviceId() {
    AppInfo *info = AppInfoFunc::getCurrentUser();
    if (info != NULL) {
        return "" + info->deviceId;
    }
    return "0";
}
QHash<QString, QVariant> MessageManager::AddToSequenceMsg(QHash<QString, QVariant> &item)
{
        if (sequenceId == 0xffffffff) {
            sequenceId = 0x00000000;
        }
        sequenceId += 1;

        QString msgid = "" + sequenceId;

        //添加到现有队列中
        //type:   QHash<QString, QHash<QString, QVariant> > mainSequence;
        mainSequence.insert(msgid,item);
        item.insert("msgid",msgid);
        return item;
}

/**
 * 获取 485 配置信息
 *
 * @return
 */
QString MessageManager::get485configtype() {
    //Map<String, Object> items = new HashMap<String, Object>();
    QHash<QString, QVariant> items;
    items.insert("action", "request");
    items.insert("subaction", "get485configtype");
    items.insert("moduletype", "cube");
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
 * 发送 通知 -- IPC 视频
 *
 * @param ip_addr
 * @param time
 * @return
 */
QString MessageManager::sendIPCVideoButton(QString ip_addr, QString time) {
    QHash<QString, QVariant> items;
    items.insert("action", "request");
    items.insert("subaction", "playipc");
    items.insert("moduletype", "ipc");
    items.insert("moduleipaddr", ip_addr);
    items.insert("timestamp", time);
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
 * local 登陆
 *
 * @param context
 * @return
 */
QString MessageManager::loginCubeFromLocal() {
    //AppInfo info = AppInfoFunc.getCurrentUser();
    AppInfo *info = AppInfoFunc::getCurrentUser();
    QString cubeid = info->username;
    QString cubepassword = info->password;
//    if (info == null) {
//        info = AppInfoFunc.getGuestUser(context);
//    }
    QHash<QString, QVariant> items;
    items.insert("action", "request");
    items.insert("subaction", "register");
    items.insert("cubeid", cubeid.toLatin1().data());
    items.insert("cubepwd", cubepassword.toLatin1().data());
    items = AddToSequenceMsg(items);

    return sendStrWithBody(items);
}

/**
 * local 获取本地数据
 *
 * @param context
 * @return
 */

QString MessageManager::getCubeInfoFromLocal() {
    AppInfo *info = AppInfoFunc::getCurrentUser();
//    if (LoginController.getInstance(context).getLoginType() == LoginController.LOGIN_TYPE_CONNECT_CLOUD) {
//        info = AppInfoFunc.getCurrentUser(context);
//    } else if (LoginController.getInstance(context).getLoginType() == LoginController.LOGIN_TYPE_CONNECT_WIFI) {
//        info = AppInfoFunc.getGuestUser(context);
//    }
    //QString curVersion = (info == null ? "0" : ("".equalsIgnoreCase(info.database_version) ? "0" : "" + info.database_version));
    QString curVersion = (info ==NULL ?"0":info->version);
    //Loger.print(TAG, "ssd send current version : " + curVersion, Thread.currentThread());
    //body
    QHash<QString, QVariant> items;
    items.insert("action", "request");
    items.insert("subaction", "getdeviceconfig");
    items.insert("moduletype", "cube");
    items.insert("version", info->version.toLatin1().data());
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
 * local 查询升级
 *
 * @param context
 * @return
 */
//public String checkCubeUpdateFromLocal(Context context) {
//    Map<String, Object> items = new HashMap<String, Object>();
//    items.put("action", "request");
//    items.put("subaction", "upgrade");
//    items.put("moduletype", "cube");
//    items.put("upgradecmd", "newversion");
//    items = AddToSequenceMsg(items);
//    return sendStrWithBody(items);
//}
/**
 * 通过websocket 发送命令
 *
 * @return
 */
QString MessageManager::getCubeInfo() {
    //body
    AppInfo *info = AppInfoFunc::getCurrentUser();
    QHash<QString, QVariant> items;
    items.insert("action", "request");
    items.insert("subaction", "getdeviceconfig");
    items.insert("moduletype", "cube");
    items.insert("version", (info == NULL?0:info->database_version.toLatin1().data()));
    items = AddToSequenceMsg(items);
    QString deviceid = getDeviceId();
    if (deviceid!="0") {
        QHash<QString, QVariant> send;
        send.insert("type", "Opaque");
        send.insert("deviceId", deviceid);
        send.insert("cubemessage", items);
        QString result = "";
//        Gson gson = new Gson();
//        result = gson.toJson(send);
        result = QJsonDocument::fromVariant(send).toJson();
        return result;
    } else {
        //Loger.print(TAG, "ssd getCubeInfo : error no deviceid", Thread.currentThread());
        qDebug()<<TAG<<"ssd getCubeInfo: error no deviceid";
        return null;
    }

}

/**
     * 设置安防密码
     *
     * @param oldpwd
     * @param newpwd
     * @return
     */
//    public String setAlarmPwd(String oldpwd, String newpwd) {
//        Map<String, Object> items = new HashMap<String, Object>();
//        items.put("action", "request");
//        items.put("subaction", "configsecurity");
//        items.put("moduletype", "cube");
//        items.put("oldpwd", oldpwd);
//        items.put("newpwd", newpwd);
//        items = AddToSequenceMsg(items);

//        return sendStrWithBody(items);
//    }

    /**
     * 通过websocket 发送scenario命令
     *
     * @param scenarioId
     * @return
     */
QString MessageManager::enableScenarioWithId(int scenarioId, QString pwd) {
        if (pwd.length()==0) {
            pwd = "123456";
        }
        QHash<QString, QVariant> items;
        items.insert("action", "request");
        items.insert("subaction", "setdevice");
        items.insert("moduletype", "scenario");
        items.insert("scenarioid", scenarioId);
        items.insert("securitypwd", pwd.toLatin1().data());
        items = AddToSequenceMsg(items);

        return sendStrWithBody(items);
    }

/**
 * 组织心跳包
 */
QString MessageManager::heartPing() {
    QHash<QString, QVariant> items;
    items.insert("action", "request");
    items.insert("subaction", "heartbeat");
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}
