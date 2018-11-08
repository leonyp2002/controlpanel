#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include <QObject>
#include "baseqtinclude.h"

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
};

//Q_DECLARE_METATYPE(QHash<QString, QVariant>)
#endif // MESSAGEMANAGER_H
