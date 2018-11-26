#include "receiverqueuemanager.h"
#include "utility.h"
#include "respondercontroller.h"
ReceiverQueueManager* ReceiverQueueManager::m_instance = NULL;
boolean ReceiverQueueManager::runFlag = false;
const QString ReceiverQueueManager::TAG="ReceiverQueueManager:";
ReceiverQueueManager::ReceiverQueueManager()
{

}


/*
* 是否运行
*
* @return
*/
boolean ReceiverQueueManager::isRunFlag() {
   return runFlag;
}

void ReceiverQueueManager::run()
{
//    Looper.prepare();
    while (runFlag) {
        isDealCommandSucceed("receiver", receiverCommandCollection);
        //Utility.threadSleep(10);
        QThread::msleep(10);//sleep 10ms
    }
//    Looper.loop();
}

void ReceiverQueueManager::startRun() {
       // Loger.print(TAG, "Start Run ", Thread.currentThread());
     qDebug()<<TAG<<"Start Run:"<<QThread::currentThread();
        if (!runFlag) {
            runFlag = true;
            //new Thread(this).start();
            this->start();
        } else {
            //Loger.print(TAG, "[] <warn> Thread already run !", Thread.currentThread());
            qDebug()<<TAG<<"[] <warn> Thread already run !"<<QThread::currentThread();
        }
}

QString ReceiverQueueManager::getTAG()
{
                return TAG;
}


/**
 * 停止
 */
void ReceiverQueueManager::stopRun() {
    //Loger.print(TAG, "Stop Run", Thread.currentThread());
    qDebug()<<TAG<<"Stop Run:"<<QThread::currentThread();
    if (runFlag) {
        runFlag = false;
        //Loger.print(TAG, "Thread queue receiver command size:" + receiverCommandCollection.count(), Thread.currentThread());
        receiverCommandCollection.clear();
        qDebug()<<TAG<<"Stop Run:"<<QThread::currentThread();
        //Loger.print(TAG, "[] <info> Thread stop !", Thread.currentThread());
    }
}

/**
 * 添加普通命令
 *
 * @param cmd
 */
void ReceiverQueueManager::addRecevierToQueue(QString &cmd) {
    if (cmd == null || cmd.compare("",Qt::CaseInsensitive))
        return;
    receiverCommandCollection.append(cmd);
}

/**************
  * private method
  ********************/
boolean ReceiverQueueManager::isDealCommandSucceed(QString tag, QList<QVariant> &commandList) {
     boolean result = false;
     QVariant command;

//     synchronized (commandList) {
//         if (!commandList.isEmpty()) {
//             command = commandList.removeCommand(0);
//         }
//     }
     if(!commandList.isEmpty())
     {
         command = commandList.takeFirst();
     }
     if (command.isValid()) {
//         if (LoginController.getInstance(mContext).getLoginType() == LoginController.LOGIN_TYPE_CONNECT_CLOUD) {
//             //处理
//             ResponderController.newInstance(mContext).dealWithWebSocketResponce((String) command);
//             return true;
//         } else
             //if (LoginController.getInstance(mContext).getLoginType() == LoginController.LOGIN_TYPE_CONNECT_WIFI) {
             if(1){
             //Loger.print(TAG, "ssd local socket deal command " + command, Thread.currentThread());
                 qDebug()<<TAG<<"ssd local socket deal command "<<command<<QThread::currentThread();
//             try {
//                 JSONObject object = new JSONObject((String) command);
//                 //socket
//                 ResponderController.newInstance(mContext).dealNetData(object);
//                 result = true;
//             } catch (Exception e) {
//                 e.printStackTrace();
//             }
            QJsonObject object = Utility::getJsonObjectFromString((QString)command.toString());
            //ResponderController::GetInstance()->dealNetData(object);
            ResponderController::getInstance()->dealNetData(object);
         } else {
             result = false;
         }
     }
     return result;

 }
