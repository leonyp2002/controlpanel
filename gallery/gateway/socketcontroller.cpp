#include "socketcontroller.h"
#include "messagemanager.h"
#include "commandqueuemanager.h"
#include "receiverqueuemanager.h"
#include "netconstant.h"
#include "appinfo.h"
#include "appinfofunc.h"

SocketController* SocketController::m_instance=NULL;
const QString SocketController::TAG="SocketController";
const int SocketController::TIME_OUT = 15000;
const int SocketController::CONNECTION_TIME_OUT =8000;
SocketController::SocketController(QObject *parent) : QObject(parent)
{
    cubeIp = "";
    cubePort =500;
    init();
}

bool SocketController::getIsProcessRun() const
{
    return isProcessRun;
}

void SocketController::setIsProcessRun(bool value)
{
    isProcessRun = value;
}

bool SocketController::getIsSendPing() const
{
    return isSendPing;
}

void SocketController::setIsSendPing(bool value)
{
    isSendPing = value;
}

void SocketController::init()
{
    socketClient = new QTcpSocket(this);
    //bool result= socketClient->bind(cubePort);
    connect(socketClient,SIGNAL(readyRead()),this,SLOT(hasConnectingToCube));
    connect(socketClient,SIGNAL(readyRead()),this,SLOT(hasPendingToRead()));
}

void SocketController::destroy()
{
    //cubeIp="";
    disconnect(socketClient,SIGNAL(readyRead()),this,SLOT(hasPendingToRead()));
    delete socketClient;
    socketClient= NULL;
}

void SocketController::hasPendingToRead()
{
    qDebug()<<"has data to recieve from CUBE";
    QByteArray data= socketClient->readAll();
    if(data.count()!=0)
    {
        dealSocketReceiveData(data);
    }
}
//SLOT for trigger has been connected to CUBE
void SocketController::hasConnectingToCube()
{
    qDebug()<<"SUCCESS:"<<" the client has been conencted to CUBE";
}
//SLOT for trigger has been disconnected to CUBE
void SocketController::hasDisconnectedToCube()
{
    qDebug()<<"WARNING:"<<" the client has been disconnected to CUBE, 10S later for reconnect";
}

void SocketController::controllerTimerOut()
{
    qDebug()<<"rcv timeout signal";
    QTimer *signalSender = (QTimer*)sender();
//    switch(signalSender->objectName())
//    case HEAT_PING_TIMER:
//        {
//            QString pingMsg = MessageManager::getInstance()->heartPing();
//            if(socketClient!=null && socketClient->state()==QAbstractSocket::ConnectedState)
//            {
//                qDebug()<<"add heart ping: "<<pingMsg;
//                //TODO: CommandQueueManager

//            }
//        }
//        break;
//    default:
//        break;
    QString senderName= signalSender->objectName();
    if(senderName == HEAT_PING_TIMER)
    {
        QString pingMsg = MessageManager::getInstance()->heartPing();
        if(socketClient!=null && socketClient->state()==QAbstractSocket::ConnectedState)
        {
            qDebug()<<"add heart ping: "<<pingMsg;
            //TODO: CommandQueueManager
            //Loger.print(TAG + "12345", "ssd add ping to socket  pingMsg = " + pingMsg, Thread.currentThread());
            qDebug()<<TAG<<"12345"<<"ssd add ping to socket  pingMsg = "<<pingMsg<<QThread::currentThread();
            //isSendPing = true;
            //CommandQueueManager.getInstance(mContext).addPingCommandToQueue(pingMsg);
            CommandQueueManager::getInstance()->addPingCommandToQueue(pingMsg);
        }
    }
}

void SocketController::setCubeIp(const QString &value)
{
    cubeIp = value;
}

int SocketController::getCubePort() const
{
    return cubePort;
}

void SocketController::setCubePort(int value)
{
    cubePort = value;
}

QString SocketController::getCubeIp() const
{
    return cubeIp;
}

QString SocketController::getTAG()
{
    return TAG;
}

//boolean SocketController::dealSocketReceiveData(QByteArray &readyData)
//{
//    qDebug()<<"recieve data:"<<readyData<<" length: "<<readyData.length();
//    //TODO:

//    return true;
//}

bool SocketController::isConnectToCube()
{
    if(!socketClient)
    {
        return false;
    }
    if(socketClient->state()==QAbstractSocket::ConnectedState)
    {
        return true;
    }
    return false;
}
//setup connection to cube
bool SocketController::connectToServer()
{
    //bool connectResult=false;

//    if(!socketClient || socketClient->state()!=QAbstractSocket::ConnectedState)
//    {

//    }
    cubeIp = getCubeIpAddress();
    QHostAddress address = QHostAddress(cubeIp);
    if(!socketClient)
    {
        if(cubeIp.count()==0||QHostAddress(cubeIp)==QHostAddress::AnyIPv4)
        {
            qDebug()<<"ERROR:"<<" no valid cube ip";
            return false;
        }
        socketClient = new QTcpSocket(this);
        connect(socketClient,SIGNAL(readyRead()),this,SLOT(hasPendingToRead()));
        socketClient->connectToHost(address,cubePort);
        if(socketClient->waitForConnected(CONNECTION_TIME_OUT))
        {
            return true;
        }
        else
        {
//            disconnect(socketClient,SIGNAL(readyRead()),this,SLOT(hasPendingToRead()));
//            delete socketClient;
//            socketClient = null;
            return false;
        }
    }
    else
    {
        if(socketClient->state()!=QAbstractSocket::ConnectedState)
        {
            socketClient->connectToHost(address,cubePort);
            if(socketClient->waitForConnected(CONNECTION_TIME_OUT))
            {
                return true;
            }
            else
            {
    //            disconnect(socketClient,SIGNAL(readyRead()),this,SLOT(hasPendingToRead()));
    //            delete socketClient;
    //            socketClient = null;
                return false;
            }
        }
        return true;
    }


}

void SocketController::pingRunnable()
{
    qDebug()<<"add ping Msg to CommandQueueMessager";
    QTimer *pingTimer = new QTimer(this);
    pingTimer->setObjectName(HEAT_PING_TIMER);
    connect(pingTimer,SIGNAL(timeout()),this,SLOT(controllerTimerOut()));
    pingTimer->start(10000);
}

/**
 * 登陆 SOCKET 主要入口
 */
void SocketController::loginToTCPSocket() {
    if(!isProcessRun)
    {
        ConnectRunnable *connectRunnable = new ConnectRunnable;
        // QThreadPool取得所有权，并自动删除 hello
        QThreadPool::globalInstance()->start(connectRunnable);
    }
    else
    {
        loginCube();
    }
    if(!ReceiverQueueManager::getInstance()->isRunFlag())
    {
        ReceiverQueueManager::getInstance();
    }
//    if (!isProcessRun) {
//        connectThread = new Thread(connectRunnable);
//        connectThread.start();
//        isProcessRun = true;
//    } else {
//        loginCube();
//    }
//    if (!ReceiverQueueManager::getInstance()->isRunFlag()) {
//        ReceiverQueueManager::getInstance()->startRun();
//    }
}

void SocketController::checkIfLogin() {
//    if (!isProcessRun) {
//        connectThread = new Thread(connectRunnable);
//        connectThread.start();
//        isProcessRun = true;
//    }
//    if (!ReceiverQueueManager::getInstance()->isRunFlag()) {
//        ReceiverQueueManager::getInstance()->startRun();
//    }
}

bool SocketController::sendSocketCommand(QString cmd)
{
    return true;
}
//return the cube address from database
QString SocketController::getCubeIpAddress()
{
    QString cubeaddress;
    qDebug()<<"the cube address is: "<<cubeaddress;
    return cubeaddress;
}

//QHostAddress SocketController::getCubeIpAddress()
//{
//    QHostAddress cubeAddress;
//    return cubeAddress;
//}

///**
// * Socket 发送数据
// *
// * @param cmd
// */
//boolean SocketController::sendSocketCommand(QString cmd) {
//    //判断登陆
//    checkIfLogin();

//    //组装数据
//    byte[] header = NetConstant.TCP_HEAD.getBytes();
//    byte[] body = cmd.getBytes();
//    int length = header.length + 1 + 4 + body.length;
//    byte[] msg = new byte[length];
//    int i = 0;
//    for (; i < header.length; i++) {
//        msg[i] = header[i];
//    }
//    msg[i] = transferOneByte(0);
//    i++;
//    int j = 0;
//    byte[] bodyLength = transferDecimalToByte(body.length);
//    for (; i < header.length + 1 + 4; i++) {
//        msg[i] = bodyLength[j++];
//    }
//    j = 0;
//    for (; i < header.length + 1 + 4 + body.length; i++) {
//        msg[i] = body[j++];
//    }
//    return socketClient.postRequestCommand(mContext, "ssd", msg);
//}

/**
 * 获取Config
 */
void SocketController::loginCube() {
//    String message = MessageManager.getInstance(mContext).loginCubeFromLocal(mContext);
//    CommandQueueManager.getInstance(mContext).addNormalCommandToQueue(message);
    QString message = MessageManager::getInstance()->loginCubeFromLocal();
    CommandQueueManager::getInstance()->addNormalCommandToQueue(message);
}

bool SocketController::dealSocketReceiveData(QByteArray &data) {
        //byte[] header = NetConstant.TCP_HEAD.getBytes();
    QByteArray header = NetConstant::TCP_HEAD.toLatin1();
    boolean ifCheckedHead = true;
    if (data.isNull())
        return ifCheckedHead;
    for (int i = 0; i < data.length() - header.length(); i++) {
        if (data.length() < i + header.length()) break;
//        if (checkByteisEqual(subDataWithInfo(data, i, header.length), header)) {
//            ifCheckedHead = true;
//            if (data.length < i + header.length + data.length - i - header.length) break;
//            resultData = subDataWithInfo(data, i + header.length, data.length - i - header.length);
//            break;
//        }
        if(data.mid(i, header.length())==header)
        {
            ifCheckedHead = true;
            if(data.length()<i+header.length()+data.length()-i-header.length())
                break;
            resultData = data.mid(i+header.length(),data.length()-i-header.length());
            break;
        }
    }

    //是否读取完
    if (resultData.isNull() || resultData.length() < 5)
        return ifCheckedHead;
    //byte[] lengthData = subDataWithInfo(resultData, 1, 4);
    QByteArray lengthData = resultData.mid(1,4);
    long length = lBytesToIntNoChange(lengthData);

    //处理数据包
    if (resultData.length() - 5 >= length) {
        //带上是否加密
        //byte[] packageData = subDataWithInfo(resultData, 4, length + 1);
        QByteArray packageData = resultData.mid(4,length+1);
        //处理一个完整的包
        dealWithPackageData(packageData);
        //沾包处理
        if (resultData.length() > length + 5) {
            //resultData = subDataWithInfo(resultData, (int) length + 5, resultData.length - length - 5);
            resultData = resultData.mid((int) length + 5, resultData.length() - length - 5);
            //继续处理
            dealSocketReceiveData(resultData);
        } else {
            resultData = null;
        }
    }
    return ifCheckedHead;
}


//处理包内容
void SocketController::dealWithPackageData(QByteArray &data) {
    if (data == null || data.length() < 2) return;
    //byte[] body = subDataWithInfo(data, 1, data.length - 1);
    QByteArray body = data.mid(1,data.length()-1);
    QString bodyStr = QString::fromUtf8(body);
    qDebug()<<TAG<<"ssd **********onSocket recever ******"<<bodyStr<<QThread::currentThread();
    if(bodyStr.count()!=0 && bodyStr.compare("",Qt::CaseInsensitive))
    {
        ReceiverQueueManager::getInstance()->addRecevierToQueue(bodyStr);
    }
}

//Bytes 转Int
long SocketController::lBytesToIntNoChange(QByteArray data) {
    //return (data[3] & 0xff) + ((data[2] & 0xff) << 8) + ((data[1] & 0xff) << 16) + ((data[0] & 0xff) << 24);
    return (data.at(3) & 0xff) +((data.at(2) & 0xff) <<8) + ((data.at(1) & 0xff) <<16) +((data.at(0) & 0xff)<<24);
}

//数据转换
char SocketController::transferOneByte(int source) {
        if (source == 0) {
            return 0;
        } else {
            return 1;
        }
    }
/**
 * 将int 十进制转换为byte数据
 *
 * @param source
 * @return
 */
QByteArray SocketController::transferDecimalToByte(int source) {
    //byte[] returnValue = new byte[4];
    QByteArray returnValue;
//    returnValue[0] = (byte) ((source >> 24) & 0xFF);
//    returnValue[1] = (byte) ((source >> 16) & 0xFF);
//    returnValue[2] = (byte) ((source >> 8) & 0xFF);
//    returnValue[3] = (byte) ((source) & 0xFF);
    returnValue.append((char) ((source >> 24) & 0xFF));
    returnValue.append((char)((source >> 16) & 0xFF));
    returnValue.append((char)((source >> 8) & 0xFF));
    returnValue.append((char)((source) & 0xFF));
    return returnValue;
}

//void SocketController::PingRunnable::run()
//{
//    while (isProcessRun) {
//        QThread::sleep(10);
//        QString pingMsg = MessageManager::getInstance()->heartPing();
//        if (socketClient != null && socketClient.isConnectToCube()) {
//            //Loger.print(TAG + "12345", "ssd add ping to socket  pingMsg = " + pingMsg, Thread.currentThread());
//            qDebug()<<TAG<<"12345"<<"ssd add ping to socket  pingMsg = "<<pingMsg<<QThread::currentThread();
//            isSendPing = true;
//            CommandQueueManager::getInstance()->addPingCommandToQueue(pingMsg);
//        }
//        try {
//            Thread.sleep(5000);
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
//    }
//    isSendPing = false;
//}

void PingRunnable::run()
{
    SocketController* sktctrllerHandle = SocketController::getInstance();
        while (sktctrllerHandle->getIsProcessRun()) {
            QThread::sleep(10);
            QString pingMsg = MessageManager::getInstance()->heartPing();
            if (sktctrllerHandle != null && sktctrllerHandle->isConnectToCube()) {
                //Loger.print(TAG + "12345", "ssd add ping to socket  pingMsg = " + pingMsg, Thread.currentThread());
                qDebug()<<SocketController::getTAG()<<"12345"<<"ssd add ping to socket  pingMsg = "<<pingMsg<<QThread::currentThread();
                //isSendPing = true;
                sktctrllerHandle->setIsSendPing(true);

                CommandQueueManager::getInstance()->addPingCommandToQueue(pingMsg);
            }
            QThread::sleep(5);
        }
        sktctrllerHandle->setIsSendPing(false);
        //isSendPing = false;
}

void ConnectRunnable::run()
{
    //Loger.print(TAG, "ssd start login socket", Thread.currentThread());
    SocketController* sktCtrllerHandle = SocketController::getInstance();
    AppInfo *info = AppInfoFunc::getCurrentUser();
    if (info == null || info->cube_local_id.length() <= 0 || info->cube_local_password.length() <= 0) {
        //Loger.print(TAG, "ssd Cloud 未登陆 无法进行本地登陆", Thread.currentThread());
        qDebug()<<SocketController::getTAG()<<"ssd Cloud 未登陆 尝试本地登陆 ";
        //弹出登陆界面
        //return;
    }
    if ( !sktCtrllerHandle->isConnectToCube()) {
        //socketClient = SocketClient.newInstance();
        //获取Cube网络接口
        QString host = info->cube_ip;
        int port = info->cube_port;
        if (port <= 0)
            port = NetConstant::TCP_IP_PORT;
        //Loger.print(TAG, "ssd connect socket host : " + host + "; port : " + port, Thread.currentThread());
        qDebug()<<SocketController::getTAG()<<"ssd connect socket host :"<<host<<";port"<<port<<QThread::currentThread();
//        socketClient.cube_ip = host;
//        socketClient.cube_port = port;
        sktCtrllerHandle->setCubeIp(host);
        sktCtrllerHandle->setCubePort(port);
//        socketClient.connectToServer(mContext);
        sktCtrllerHandle->connectToServer();//using slot for recieve msg
//        if (receiverThread == null) {
//            receiverThread = new SocketReceiverThread(mContext, socketClient);
//            receiverThread.startRun();
//        }
        CommandQueueManager::getInstance()->startRun();
        //LoginController.getInstance(mContext).setLoginType(LoginController.LOGIN_TYPE_CONNECT_WIFI);
        sktCtrllerHandle->loginCube();
    } else {
        sktCtrllerHandle->loginCube();
    }
}
