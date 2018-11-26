#include "messagemanager.h"

#include "appinfofunc.h"
const QString MessageManager::TAG ="MessageManager: ";
ulong MessageManager::sequenceId = 0;
MessageManager* MessageManager::m_instance = NULL;

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
//        QString result = gson.toJson(items);
//        return result;
//    }
    /* cloud part, no need for control pannel
    else {
        QString deviceid = getDeviceId();
        if (!deviceid.equals("") && !deviceid.equals("0")) {
            QHash<QString, QVariant> send = new HashQHash<QString, QVariant>();
            send.insert("type", "Opaque");
            send.insert("deviceId", deviceid);
            send.insert("cubemessage", items);
            Gson gson = new Gson();
            QString result = gson.toJson(send);

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
    //QHash<QString, QVariant> items = new HashQHash<QString, QVariant>();
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
// QString checkCubeUpdateFromLocal(Context context) {
//    QHash<QString, QVariant> items = new HashQHash<QString, QVariant>();
//    items.insert("action", "request");
//    items.insert("subaction", "upgrade");
//    items.insert("moduletype", "cube");
//    items.insert("upgradecmd", "newversion");
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
//     QString setAlarmPwd(QString oldpwd, QString newpwd) {
//        QHash<QString, QVariant> items = new HashQHash<QString, QVariant>();
//        items.insert("action", "request");
//        items.insert("subaction", "configsecurity");
//        items.insert("moduletype", "cube");
//        items.insert("oldpwd", oldpwd);
//        items.insert("newpwd", newpwd);
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

/**
     * 组织查询设备状态的字段   用到了SparkLighting relay wireless315_433
     *
     * @param deviceLoopMap  QList< QVariant >  the QVariant is QHash<QString,QVariant>
     * @param moduleType
     * @return
     */

QString MessageManager::checkOutDeviceListStatus(QList< QVariant > deviceLoopMapList, QString moduleType, QHash<QString, QVariant> subItem) {
        QHash<QString, QVariant> items;
        items.insert("action", "request");
        items.insert("subaction", "readdevice");
        items.insert("moduletype", moduleType.toLatin1().data());
        items.insert("deviceloopmap", deviceLoopMapList);
        if (subItem.count()!=0) {
            items.unite(subItem);
        }
        items = AddToSequenceMsg(items);

        return sendStrWithBody(items);

    }
/**
 * 查询 Commondevice的状态
 *
 * @param deviceLoopMap
 * @return
 */
QString MessageManager::checkoutCommonDeviceStatus(QList<QVariant> deviceLoopMapList) {
    QHash<QString, QVariant> items;
    items.insert("action", "request");
    items.insert("subaction", "readdevice");
    items.insert("deviceloopmap", deviceLoopMapList);
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
 * 请求房间的状态
 *
 * @param roomLoopMap QList<QVariant>
 * @return
 */
QString MessageManager::checkRoomStatus(QList<QVariant> roomLoopMap) {
    QHash<QString, QVariant> items;
    items.insert("action", "request");
    items.insert("subaction", "readdevice");
    items.insert("moduletype", "room");
    items.insert("roomloopmap", roomLoopMap);
    items = AddToSequenceMsg(items);

    return sendStrWithBody(items);
}

/**
 * 组织查询BackAudio的状态，因为比较特殊，所以单独组织
 *
 * @param serialnum
 * @param loopId
 * @return
 */
 QString MessageManager::checkoutBackAudioStatus(QString serialnum, int loopId) {
    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "readdevice");
    items.insert("moduletype", "backaudio");
    items.insert("moduleserialnum", serialnum);
    items.insert("loopid", loopId);
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
 * 组织控制device的命令，
 *
 * @param deviceloopmap－－loop QList<QVariant>
 * @param moduleType－－类型
 * @param subItem－－其他的头
 * @return
 */
 QString MessageManager::sendDeviceStatus(QList<QVariant> deviceloopmap, QString moduleType, QHash<QString, QVariant> subItem) {
    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "setdevice");
    if (moduleType.count()!=0) {
        items.insert("moduletype", moduleType);
    }
    items.insert("deviceloopmap", deviceloopmap);
    if (subItem.count()!=0) {
        items.unite(subItem);
    }
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}
/**
 * 组织发送控制 BackAudioLoop状态的命令
 *
 * @param control
 * @param device
 * @param loop
 * @return
 */
 QString MessageManager::sendBackAudioLoopStatus(QList<QVariant> control, BackaudioDevice device, BackaudioLoop loop) {
    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "setdevice");
    items.insert("moduletype", "backaudio");
    items.insert("moduleserialnum", device.mSerialNumber);
    items.insert("loopid", loop.mLoopId);
    items.insert("keytypeloop", control);

    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
 * 组织发送IR Code
 *
 * @param imageName
 * @param macAddr
 * @param irData
 * @return
 */
 QString MessageManager::sendIRCode(QString imageName, QString macAddr, QList<QVariant> irData) {
    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "setdevice");
    items.insert("moduletype", "ir");
    items.insert("ircommand", "send");
    items.insert("name", imageName);
    items.insert("imagename", imageName);
    items.insert("modulemacaddr", macAddr);
    items.insert("wifiirdata", irData);

    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}
/**
 * 添加新模块 发现新版本
 *
 * @return
 */
 QString MessageManager::findNewModule() {
    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "getnewmodulelist");

    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
     * 发送Rule开关命令
     *
     * @param isOn
     * @param info
     * @return
     */
     QString MessageManager::sendRuleStatus(boolean isOn, ScenarioTriggerInfo info) {
        QHash<QString, QVariant> items;;
        items.insert("action", "request");
        items.insert("subaction", "configdevice");
        items.insert("moduletype", "scenariotrigger");
        items.insert("configtype", "modify");
        items.insert("status", isOn ? "on" : "off");
        items.insert("primaryid", info.mPrimaryId);
        items = AddToSequenceMsg(items);
        return sendStrWithBody(items);
    }

    /**
     * 删除 Rule命令
     *
     * @param info
     * @return
     */
     QString MessageManager::deleteRule(ScenarioTriggerInfo info) {
        QHash<QString, QVariant> items;;
        items.insert("action", "request");
        items.insert("subaction", "configdevice");
        items.insert("moduletype", "scenariotrigger");
        items.insert("configtype", "delete");
        items.insert("primaryid", info.mPrimaryId);
        items = AddToSequenceMsg(items);
        return sendStrWithBody(items);
    }

    /**
     * 添加 rule
     *
     * @param availableTime
     * @param delayTime
     * @param aliasName
     * @param conditionArray
     * @param actionArray
     * @return
     */
     QString MessageManager::addRule(QHash<QString, QVariant> availableTime, int delayTime, QString aliasName, QList<QVariant> conditionArray, QList<QVariant> actionArray) {
        QHash<QString, QVariant> items;;
        items.insert("action", "request");
        items.insert("subaction", "configdevice");
        items.insert("moduletype", "scenariotrigger");
        items.insert("configtype", "add");
        items.insert("status", "on");
        items.insert("availabletime", availableTime);
        items.insert("triggertype", "trigger");
        items.insert("delaytime", delayTime);
        items.insert("aliasname", aliasName);
        items.insert("description", aliasName);
        items.insert("condition", conditionArray);
        items.insert("triggeraction", actionArray);

        items = AddToSequenceMsg(items);
        return sendStrWithBody(items);
    }

/**
 * 查询新风系统的状态
 */
 QString MessageManager::readVentilationDeviceStatus(long primaryId) {
    QHash<QString, QVariant> controlDic;
    controlDic.insert("primaryid", "" + primaryId);
    QList<QVariant> controlList;
    controlList.append(controlDic);

    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "readdevice");
    items.insert("moduletype", "ventilation");
    items.insert("deviceloopmap", controlList);
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
 * 查询 485 新风 设备的状态
 */
 QString MessageManager::read485VentilationDeviceStatus(long primaryId) {
    QHash<QString, QVariant> controlDic;
    controlDic.insert("primaryid", "" + primaryId);
    QList<QVariant> controlList;
    controlList.append(controlDic);

    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "readdevice");
    items.insert("moduletype", "ventilation");
    items.insert("controltype", "485");
    items.insert("deviceloopmap", controlList);
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}


/**
 * 控制新风系统 QVariant controlMap
 */
 QString MessageManager::sendControlVentilation(QVariant controlMap) {
    QList<QVariant> controlList;
    controlList.append(controlMap);
    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "setdevice");
    items.insert("moduletype", "ventilation");
    items.insert("deviceloopmap", controlList);
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}
/**
 * 控制新风系统
 */
 QString MessageManager::sendControlVentilation485(QVariant controlMap) {
    QList<QVariant> controlList;
    controlList.append(controlMap);
    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "setdevice");
    items.insert("moduletype", "ventilation");
    items.insert("controltype", "485");
    items.insert("deviceloopmap", controlList);
    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}
/************************ 计划 Schedule ***************************/

/**
 * 执行计划 打开或者关闭
 *
 * @param primaryId
 * @param ison
 * @return
 */
 QString MessageManager::enableSchedule(int primaryId, boolean ison) {
    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "configdevice");
    items.insert("configtype", "modify");
    items.insert("moduletype", "schedulerule");
    items.insert("status", ison ? "on" : "off");
    items.insert("primaryid", primaryId);

    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
 * 删除 计划 Schedule
 *
 * @param primaryId
 * @return
 */
 QString MessageManager::deleteSchedule(int primaryId) {
    QHash<QString, QVariant> items;;
    items.insert("action", "request");
    items.insert("subaction", "configdevice");
    items.insert("configtype", "delete");
    items.insert("moduletype", "schedulerule");
    items.insert("primaryid", primaryId);

    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}

/**
 * 编辑 计划
 *
 * @param map
 * @return
 */
 QString MessageManager::modifySchedule(QVariant map) {
    QHash<QString, QVariant> items = map.toHash();

    items = AddToSequenceMsg(items);
    return sendStrWithBody(items);
}
