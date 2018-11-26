#ifndef NETCONSTANT_H
#define NETCONSTANT_H
#include <QString>

class NetConstant
{
public:
    NetConstant();
    //服务请求超时时间
    static const int MsgTimeOut ;

    //心跳包请求事件间隔
    static const int PingInteval;
    static const QString TCP_HEAD ;
    /**
     * 服务器地址
     */
    //#define IP_ALL @"qa.acscloud.honeywell.com.cn" // QA测试
    //总IP 用于网络请求
//    static const QString IP_ALL = "115.159.221.25:80";
    //    static const QString IP_ALL = "115.159.150.115:80";
//    static const QString IP_ALL = "dev.acscloud.honeywell.com.cn";
//    static const QString IP_ALL = "qa.acscloud.honeywell.com.cn";
    static const QString IP_ALL;

    //Origin 用于Websocket
//    static const QString URI_WEBSOCKET_ORIGIN = "http://115.159.221.25";
    static const QString URI_WEBSOCKET_ORIGIN;

    //总地址
    static const QString URI_ALL;

    //用户列表
    static const QString URI_USER_LIST;

    // CUBE天气
    static const QString URI_CUBE_WEATHER;
    static const QString URI_CUBE_ONLINE_STATE;

    //天气列表
    static const QString URI_WEATHER_LIST;

    //用户
    static const QString URI_USER;

    //位置列表
    static const QString URI_LOCATION_LIST;

    //cube 位置
    static const QString URI_CUBE_LOCATION;
    //手机设备列表
    static const QString URI_PHONE_LIST;

    //已绑定Cube 设备列表
    static const QString URI_DEVICE_LIST;

    //报警记录
    static const QString URI_ALARMHISTORY;

    //报警数量
    static const QString URI_ALARM_COUNT;
    //CUBE 相关
    static const QString URI_CUBE;

    //webSocket 地址信息
    static const QString URI_WEBSOCKET;

    //Socket
    static const QString TCP_IP_ADRESS;
    static const int TCP_IP_PORT;

    // CUBE 编码
    static const QString TestDeviceSerial;


    // IPC 端口
    static const int IPC_PORT;

    //Backaudio Type Int
    static const int BackaudioTypeInt;

    // 主码流
    static const QString IPC_MAIN_STREAM;
    static const QString IPC_STREAM_PHOENIX;

    // 辅码流
    static const QString IPC_SUB_STREAM;
    static const QString IPC_SUB_STREAM_PHOENIX;

    //默认的IPVDP密码
    static const QString MAIN_IPVDP_PASSWORD;
    //默认场景密码
    static const QString MAIN_SCENARIO_PASSWORD;


    /**
     * easy link 相关
     */
    static  int EASY_LINK_GROUP_LISTENER_TIME_INTEVAL;//组播监听线程暂停时间
    static  int EASY_LINK_SEND_GROUP;
    static  int EASY_LINK_GROUP_LISTENER_PORT;//组播监听端口 原demo是6767 iOS端是5350 到时候需要确认下
};

#endif // NETCONSTANT_H
