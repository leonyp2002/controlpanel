#ifndef RECEIVERQUEUEMANAGER_H
#define RECEIVERQUEUEMANAGER_H

#include <QObject>
#include "baseqtinclude.h"

class ReceiverQueueManager : public QThread
{
Q_OBJECT
public:
    ReceiverQueueManager();
    static ReceiverQueueManager* getInstance()
    {
        if(!m_instance)
        {
            m_instance = new ReceiverQueueManager;
        }
        return m_instance;
    }
    //void addRecevierToQueue(QString &bodyStr);

    bool isRunFlag();
    void startRun();
    static QString getTAG();

    void stopRun();
    void addRecevierToQueue(QString &cmd);
private:
    static ReceiverQueueManager* m_instance;
    static const QString TAG;
    static bool runFlag;
    QList<QVariant> receiverCommandCollection;
    bool isDealCommandSucceed(QString tag, QList<QVariant> &commandList);
protected:
    void run();
};

#endif // RECEIVERQUEUEMANAGER_H
