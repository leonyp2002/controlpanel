#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include <QObject>
#include "baseqtinclude.h"
#include "backaudiodevice.h"
#include "backaudioloop.h"
#include "scenariotriggerinfo.h"
class MessageManager : public QObject
{
    Q_OBJECT
public:
    explicit MessageManager(QObject *parent = 0);
    static MessageManager* getInstance()
    {
        if(!m_instance)
        {
            m_instance = new MessageManager();
        }
        return m_instance;
    }
signals:

public slots:
private:
    static MessageManager* m_instance;
    const static QString TAG;
    QString sendStrWithBody(QHash<QString, QVariant> items);
    QString getDeviceId();
public:

    static QString getTAG();
    static ulong sequenceId;
    static ulong getSequenceId();
    static void setSequenceId(ulong value);
    QHash<QString, QVariant> mainSequence;
    QHash<QString, QVariant > AddToSequenceMsg(QHash<QString, QVariant> &item);
    QString get485configtype();
    QString sendIPCVideoButton(QString ip_addr, QString time);
    QString loginCubeFromLocal();
    QString getCubeInfoFromLocal();
    QString getCubeInfo();
    QString enableScenarioWithId(int scenarioId, QString pwd);
    QString heartPing();
    QString checkOutDeviceListStatus(QList<QVariant> deviceLoopList, QString moduleType, QHash<QString, QVariant> subItem);
    QString checkoutCommonDeviceStatus(QList<QVariant> deviceLoopMapList);
    QString checkRoomStatus(QList<QVariant> roomLoopMap);
    QString checkoutBackAudioStatus(QString serialnum, int loopId);
    QString sendDeviceStatus(QList<QVariant> deviceloopmap, QString moduleType, QHash<QString, QVariant> subItem);
    QString sendBackAudioLoopStatus(QList<QVariant> control, BackaudioDevice device, BackaudioLoop loop);
    QString sendIRCode(QString imageName, QString macAddr, QList<QVariant> irData);
    QString findNewModule();
    QString sendRuleStatus(boolean isOn, ScenarioTriggerInfo info);
    QString deleteRule(ScenarioTriggerInfo info);
    QString addRule(QHash<QString, QVariant> availableTime, int delayTime, QString aliasName, QList<QVariant> conditionArray, QList<QVariant> actionArray);
    QString readVentilationDeviceStatus(long primaryId);
    QString read485VentilationDeviceStatus(long primaryId);

    QString sendControlVentilation485(QVariant controlMap);
    QString sendControlVentilation(QVariant controlMap);
    QString enableSchedule(int primaryId, boolean ison);
    QString deleteSchedule(int primaryId);
    QString modifySchedule(QVariant map);
};

//Q_DECLARE_METATYPE(QHash<QString, QVariant>)
#endif // MESSAGEMANAGER_H
