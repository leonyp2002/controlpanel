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
    QString cubeid = AppInfoFunc::getCurrentUser()->username;
    QString cubepassword = AppInfoFunc::getCurrentUser()->password;
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
