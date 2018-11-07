#ifndef APPINFO_H
#define APPINFO_H

#include <QObject>
#include "baseqtinclude.h"
class AppInfo : public QObject
{
    Q_OBJECT
public:
    explicit AppInfo(QObject *parent = 0);

signals:

public slots:
public:
    //系统
    QString deviceToken;
    QString version; //App 版本
    QString database_version;//数据库版本
    QString router_ssid_password;
    QString all_header_fields_cookie;

    // 用户
    QString phone_prefix;
    QString username;
    QString password;
    QString nickname;
    int phoneId;
    int deviceId;

    // Cube
    QString cube_location;// city
    QString user_image_path;
    int current_scenario_id;
    QString cube_ip;
    QString cube_mac;//新增
    int cube_port;
    QString cube_local_nickname;
    QString cube_local_id;
    QString cube_local_password;

    //后加的
    int current_security_status;//当前安全状态
    int cube_voice_recognize;//语音识别
    QString cube_version;//Cube 版本

    QString last_read_time;
    int online;

private:
    void init();
};

#endif // APPINFO_H
