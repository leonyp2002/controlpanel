#include "netconstant.h"
//服务请求超时时间
  const int MsgTimeOut = 18000;

//心跳包请求事件间隔
  const int NetConstant::PingInteval = 20000;
  const QString NetConstant::TCP_HEAD = "PHONE_CUBE_PROTOCOL";
/**
 * 服务器地址
 */
//#define IP_ALL @"qa.acscloud.honeywell.com.cn" // QA测试
//总IP 用于网络请求
//      const String IP_ALL = "115.159.221.25:80";
//      const String IP_ALL = "115.159.150.115:80";
//      const String IP_ALL = "dev.acscloud.honeywell.com.cn";
//      const String IP_ALL = "qa.acscloud.honeywell.com.cn";
  const QString NetConstant::IP_ALL = "acscloud.honeywell.com.cn";

//Origin 用于Websocket
//      const QString NetConstant::URI_WEBSOCKET_ORIGIN = "http://115.159.221.25";
  const QString NetConstant::URI_WEBSOCKET_ORIGIN = "https://" + IP_ALL;

//总地址
  const QString NetConstant::URI_ALL = "https://" + IP_ALL + "/v1/00100001";

//用户列表
  const QString NetConstant::URI_USER_LIST = URI_ALL + "/user/list";

// CUBE天气
  const QString NetConstant::URI_CUBE_WEATHER = URI_ALL + "/user/device/weather";
  const QString NetConstant::URI_CUBE_ONLINE_STATE = URI_ALL + "/user/device/online";

//天气列表
  const QString NetConstant::URI_WEATHER_LIST = URI_ALL + "/weather/list";

//用户
  const QString NetConstant::URI_USER = URI_ALL + "/user";

//位置列表
  const QString NetConstant::URI_LOCATION_LIST = URI_ALL + "/location/list";

//cube 位置
  const QString NetConstant::URI_CUBE_LOCATION = URI_ALL + "/user/device/location";
//手机设备列表
  const QString NetConstant::URI_PHONE_LIST = URI_ALL + "/phone/list";

//已绑定Cube 设备列表
  const QString NetConstant::URI_DEVICE_LIST = URI_ALL + "/user/device/list";

//报警记录
  const QString NetConstant::URI_ALARMHISTORY = URI_ALL + "/user/alarm/history";

//报警数量
  const QString NetConstant::URI_ALARM_COUNT = URI_ALL + "/user/alarm/count";
//CUBE 相关
  const QString NetConstant::URI_CUBE = URI_ALL + "/user/device";

//webSocket 地址信息
  const QString NetConstant::URI_WEBSOCKET = "wss://" + IP_ALL + "/v1/00100001/phone/connect";

//Socket
  const QString NetConstant::TCP_IP_ADRESS = "192.168.31.243";
  const int NetConstant::TCP_IP_PORT = 9000;

// CUBE 编码
  const QString NetConstant::TestDeviceSerial = "001000015555";


// IPC 端口
  const int NetConstant::IPC_PORT = 554;

//Backaudio Type Int
  const int NetConstant::BackaudioTypeInt = 10;

// 主码流
  const QString NetConstant::IPC_MAIN_STREAM = "ch01.264?ptype=udp";
  const QString NetConstant::IPC_STREAM_PHOENIX = "h264";

// 辅码流
  const QString NetConstant::IPC_SUB_STREAM = "ch01_sub.264?ptype=udp";
  const QString NetConstant::IPC_SUB_STREAM_PHOENIX = "h264_2";

//默认的IPVDP密码
  const QString NetConstant::MAIN_IPVDP_PASSWORD = "1123445";
//默认场景密码
  const QString NetConstant::MAIN_SCENARIO_PASSWORD = "123456";


/**
 * easy link 相关
 */
  int NetConstant::EASY_LINK_GROUP_LISTENER_TIME_INTEVAL = 2000;//组播监听线程暂停时间
  int NetConstant::EASY_LINK_SEND_GROUP = 9999;
  int NetConstant::EASY_LINK_GROUP_LISTENER_PORT = 5350;//组播监听端口 原demo是6767 iOS端是5350 到时候需要确认下
NetConstant::NetConstant()
{

}
