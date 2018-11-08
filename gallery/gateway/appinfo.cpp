#include "appinfo.h"

AppInfo::AppInfo(QObject *parent) : QObject(parent)
{
    init();
}

void AppInfo::init()
{
    //系统
    deviceToken = "";
    version = ""; //App 版本
    database_version = "";//数据库版本
    router_ssid_password = "";
    all_header_fields_cookie = "";

    // 用户
    phone_prefix = "";
    username = "";
    password = "";
    nickname = "";
    phoneId = -1;
    deviceId = -1;

    // Cube
    cube_location = "";// city
    user_image_path = "";
    current_scenario_id=0;
    cube_ip = "";
    cube_mac = "";//新增
    cube_port = -1;
    cube_local_nickname = "";
    cube_local_id = "";
    cube_local_password = "";

    //后加的
    current_security_status = 0;//当前安全状态
    cube_voice_recognize = 0;//语音识别
    cube_version = "";//Cube 版本

    last_read_time = "";
    online = -1;
}
