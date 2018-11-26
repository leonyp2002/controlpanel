#ifndef SOCKETCONTROLLER_H
#define SOCKETCONTROLLER_H

#include <QObject>
#include "baseqtinclude.h"
class SocketController : public QObject
{
    Q_OBJECT
public:
    explicit SocketController(QObject *parent = 0);
    QTcpSocket* socketClient;
    QThread* SocketReceiverThread;
    static SocketController* getInstance()
    {
        if(!m_instance)
        {
            m_instance = new SocketController;
        }
        return m_instance;
    }
    bool getIsProcessRun() const;
    void setIsProcessRun(bool value);

    bool getIsSendPing() const;
    void setIsSendPing(bool value);
    void init();
    void destroy();

    bool dealSocketReceiveData(QByteArray &readyData);
    boolean isConnectToCube();
    boolean connectToServer();
    void pingRunnable();
    boolean sendSocketCommand(QString cmd);
    static QByteArray transferDecimalToByte(int source);
    static char transferOneByte(int source);
    void dealWithPackageData(QByteArray &data);
    static long lBytesToIntNoChange(QByteArray data);
    QByteArray resultData;
    void loginCube();
private:
    //private functions
    QString getCubeIpAddress();
signals:

public slots:
    void hasPendingToRead();
    void hasConnectingToCube();
    void hasDisconnectedToCube();
    //common timer slot
    void controllerTimerOut();
private:
    static SocketController* m_instance;
    bool isProcessRun;
    bool isSendPing;
    static const QString TAG;
    static const int TIME_OUT;
    static const int CONNECTION_TIME_OUT;
    QString cubeIp;
    int cubePort;
public:
   void loginToTCPSocket();
   void checkIfLogin();
   static QString getTAG();
   QString getCubeIp() const;
   int getCubePort() const;
   void setCubePort(int value);
   void setCubeIp(const QString &value);
};

//inside class
class PingRunnable: public QObject,  public QRunnable
{
    Q_OBJECT
public:
    void run();
};

class ConnectRunnable: public QObject, public QRunnable
{
    Q_OBJECT
public:
    void run();
};
#endif // SOCKETCONTROLLER_H
