#ifndef COMMANDQUEUEMANAGER_H
#define COMMANDQUEUEMANAGER_H

#include <QObject>
#include "baseqtinclude.h"

class CommandQueueManager : public QThread
{
    Q_OBJECT
public:
    explicit CommandQueueManager(QObject *parent = 0);
    static CommandQueueManager* getInstance()
    {
        if(!m_instance)
        {
            m_instance = new CommandQueueManager();
        }
        return m_instance;
    }
    void startRun();
    void stopRun();


    void addNormalCommandToQueue(QString &cmd);
    void addPingCommandToQueue(QString &cmd);
signals:
public slots:

private:
    static const QString TAG;
    static CommandQueueManager* m_instance;
    QList<QVariant> normalCommandCollection;
    QList<QVariant> pingCommandCollection;
    QTimer *timer;
    static boolean runFlag;
    boolean isSendCommandSucceed(QString tag, QList<QVariant> &commandList);
    void checkIfTimeOut();
protected:
    void run();
};

#endif // COMMANDQUEUEMANAGER_H
