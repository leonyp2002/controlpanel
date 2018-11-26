#include "commandqueuemanager.h"
#include "socketcontroller.h"

const QString CommandQueueManager::TAG="CommandQueueManager:";
boolean CommandQueueManager::runFlag = false;
CommandQueueManager* CommandQueueManager::m_instance=NULL;
CommandQueueManager::CommandQueueManager(QObject *parent)
{
    //queueThread = new QThread;
}

void CommandQueueManager::startRun()
{
    if (!runFlag) {
        //Loger.print(TAG, "receiver queue start run", Thread.currentThread());
        qDebug()<<TAG<<" recieve queue start run"<< QThread::currentThread();
        runFlag = true;

        //new Thread(this).start();
    } else {
       // Loger.print(TAG, "[] <warn> Thread already run !", Thread.currentThread());
    }
}

void CommandQueueManager::stopRun()
{
    qDebug()<<TAG<<"Stop Run"<<QThread::currentThread();
    if (runFlag) {
        runFlag = false;
        //Loger.print(TAG, "Thread queue normal command size:" + normalCommandCollection.count(), Thread.currentThread());
        //normalCommandCollection.clearCommand();
        normalCommandCollection.clear();
        pingCommandCollection.clear();
        qDebug()<<TAG<<": all command queue has been clear";
        //Loger.print(TAG, "Thread queue ping count size:" + pingCommandCollection.count(), Thread.currentThread());
        //pingCommandCollection.clearCommand();
       // Loger.print(TAG, "[] <info> Thread stop !", Thread.currentThread());
        //timeoutMonitor = null;
    }
}

bool CommandQueueManager::isSendCommandSucceed(QString tag, QList<QVariant> &commandList)
{
    boolean result = false;
    QVariant command;

//    synchronized (commandList) {
//        if (!commandList.isEmpty()) {
//            command = commandList.removeCommand(0);
//        }
//    }
    if(!commandList.isEmpty())
    {
        command = commandList.takeFirst();
    }

    if (command.isValid()) {
//        if (LoginController.getInstance(mContext).getLoginType() == LoginController.LOGIN_TYPE_CONNECT_CLOUD) {
//            //WebSocket
//            result = WebsocketMessageController.getInstance(mContext).sendMessageWithInfo(mContext, (String) command, tag);
//            if (result && tag.equalsIgnoreCase("normal")) {
//                timeoutMonitor = new TimeoutMonitor(command);
//            }
//            result = true;
//        } else
            //if (LoginController.getInstance(mContext).getLoginType() == LoginController.LOGIN_TYPE_CONNECT_WIFI) {
        if(1)
        {
            //socket
            //printf(TAG, "ssd socket send str :" + command, Thread.currentThread());
            qDebug()<<TAG<<"ssd socket send str :"<<command<< QThread::currentThread();
            //result = SocketController.newInstance(mContext).sendSocketCommand((String) command);
            result = SocketController::getInstance()->sendSocketCommand(command.toString());
            if (result && tag.compare("normal",Qt::CaseInsensitive)) {
                //timeoutMonitor = new TimeoutMonitor(command);
                qDebug()<<TAG<<"send success:"<<command;
            } else if (!result) {
                //发送失败，发送Event事件
                //EventBus.getDefault().post(new CubeBasicEvent(CubeEvents.CubeBasicEventType.CONNECTING_LOST, false, mContext.getString(R.string.error_time_out)));
                qDebug()<<TAG<<"send filed:"<<command;
            }
            result = true;
        } else {
            result = false;
        }
    }
    return result;
}

void CommandQueueManager::run()
{
    //Loger.print(TAG, "[] <info> Start new thread ... ", Thread.currentThread());
    qDebug()<<TAG<<"[] <info> Start new thread ... "<<QThread::currentThread();
    while (runFlag) {
        /**
         * 测试
         */
        boolean sendCommand = isSendCommandSucceed("normal", normalCommandCollection);
        if (!sendCommand) {
            boolean sendOccupty = isSendCommandSucceed("ping", pingCommandCollection);
            if (!sendOccupty) {
                //Utility.threadSleep(50);
                QThread::msleep(50);
            }
        }
        //Utility.threadSleep(10);
        QThread::msleep(50);
    }
}

/**
 * 添加普通命令
 *
 * @param cmd
 */
void CommandQueueManager::addNormalCommandToQueue(QString &cmd) {
    if (cmd == null || cmd.compare("",Qt::CaseInsensitive))
        return;
    //normalCommandCollection.addCommand(cmd);
    normalCommandCollection.append(cmd);
}

/**
 * 添加心跳包
 *
 * @param cmd
 */
void CommandQueueManager::addPingCommandToQueue(QString &cmd) {
    if (cmd == null || cmd.compare("",Qt::CaseInsensitive))
        return;
    pingCommandCollection.append(cmd);
}

void CommandQueueManager::checkIfTimeOut() {

//    if (timeoutMonitor == null) {
//        return;
//    } else {
//        //lock.lock();
//        if (timeoutMonitor != null && timeoutMonitor.getWaitMillis() > timeoutMonitor.getTimeOutValue()) {
//            //已经超时
//            Loger.print(TAG, "ssd time out : " + timeoutMonitor.toString(), Thread.currentThread());
//            timeoutMonitor = null;

//            //清空发送队列
//            normalCommandCollection.clearCommand();
//            pingCommandCollection.clearCommand();
//            //发送超时Event
//            EventBus.getDefault().post(new CubeBasicEvent(CubeEvents.CubeBasicEventType.TIME_OUT, true, ""));
//        }
//        //lock.unlock();
//    }
}
