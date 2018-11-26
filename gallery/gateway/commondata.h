#ifndef COMMONDATA_H
#define COMMONDATA_H
#include "baseqtinclude.h"

class CommonData
{
public:
    CommonData();
       // user password fileName
     const static QString APP_LOGIN_VIEW_IS_ADDED ;
     const static QString APP_USER_PASSWORD_FILENAME ;


    // wiredzone，sparklighting，433 wireless zone 配置修改
     const static QString ACTION_DEV_MODIFYARMZONECONFIG ;
     const static QString ACTION_DEV_MODIFYTRIGGERRULECONFIG ;
     const static QString ACTION_DEV_MODIFYMUTEXRULECONFIG ;
     const static QString ACTION_DEV_MODIFYSCHEDULERULECONFIG ;

    // JSON协议解析：发送广播时，二进制JSON数据，对应的名字
     const static QString ACTION_SCHEDULE_SYSTEM_ALARM ;
     const static QString EXTRA_DATA_NAME ;
     const static QString EXTRA_DATA_LEN ;
    // The Json message comes from cloud or LAN
     const static QString EXTRA_DATA_FROM ;
     const static QString EXTRA_DATA_FROM_LAN ;
     const static QString EXTRA_DATA_FROM_CLOUD ;
     const static QString EXTRA_DATA_FROM_THIRDPARTY ;
     const static QString EXTRA_DATA_FROM_WIFIMODULE ;
     const static QString EXTRA_DATA_FROM_CONFIGSERVICE ;
     const static QString EXTRA_DATA_FROM_SECURITYSERVICE ;
     const static QString EXTRA_DATA_FROM_CONTROLSERVICE ;
     const static QString EXTRA_DATA_FROM_EXTENSIONTELSERVICE ;
     const static QString EXTRA_DATA_FROM_VOICERECGONIZE ;
     const static QString EXTRA_DATA_ID ;


    //Cube database info
     static const QString APPDATABASEFILE ;
     static const int APPDATABASEVersion ;


     static const int ONLINE ;
     static const int NOTONLINE ;

     static const int ARM_TYPE_DISABLE ;
     static const int ARM_TYPE_ENABLE ;

     static const int HASCONFIG ;
     static const int NOTCONFIG ;

     static const QString ARM_TYPE_DISABLE_STR ;
     static const QString ARM_TYPE_ENABLE_STR ;

     static const QString ARM_TYPE_ARM_STR ;
     static const QString ARM_TYPE_DISARM_STR ;

    /**
     * Field name for JSON Parser
     */
    //AppInfo Login responce
     static const QString JSON_LOGIN_RESPONCE_PHONEID ;
     static const QString JSON_HTTP_SET_USER_COOKIE ;

    //cookie for websocket
     static const QString JSON_WEBSOCKET_USER_COOKIE ;
     static const QString JSON_WEBSOCKET_USER_ORIGIN ;


    //Login get bind cube
     static const QString JSON_LOGIN_GET_CUBE_RESPONCE_DEVICES ;
     static const QString JSON_LOGIN_GET_CUBE_RESPONCE_DEVICEID ;
     static const QString JSON_LOGIN_GET_CUBE_RESPONCE_DEVICEINFO ;
     static const QString JSON_LOGIN_GET_CUBE_RESPONCE_DEVICE_CUBE_SERIAL_NUMBER ;


     static const QString JSON_COMMAND_MSGID ;
     static const QString JSON_COMMAND_ACTION ;
     static const QString JSON_COMMAND_ACTIONINFO ;
     static const QString JSON_COMMAND_SUBACTION ;
     static const QString JSON_COMMAND_CUBEID ;
     static const QString JSON_COMMAND_CUBEPWD ;
     static const QString JSON_COMMAND_CUBEOLDPWD ;
     static const QString JSON_COMMAND_CLOUDID ;
     static const QString JSON_COMMAND_CLOUDPWD ;
     static const QString JSON_COMMAND_MODULETYPE ;
     static const QString JSON_COMMAND_MODULEMACADDR ;
     static const QString JSON_COMMAND_MODULEIPADDR ;
     static const QString JSON_COMMAND_MODULEPORT ;
     static const QString JSON_COMMAND_DEVICETYPE ;
     static const QString JSON_COMMAND_ALIAS ;
     static const QString JSON_COMMAND_ROOMNAME ;
     static const QString JSON_COMMAND_ROOMID ;

     static const QString JSON_COMMAND_ERRORCODE ;
     static const QString JSON_COMMAND_DEVLOOPMAP ;
     static const QString JSON_COMMAND_DEVID ;
     static const QString JSON_COMMAND_LOOPID ;
     static const QString JSON_COMMAND_LOOPTYPE ;
     static const QString JSON_COMMAND_MASKID ;
     static const QString JSON_COMMAND_SPARKLIGHTINGDEVMAP ;
     static const QString JSON_COMMAND_PORTID ;
     static const QString JSON_COMMAND_PORTRATE ;
     static const QString JSON_COMMAND_CUBEBACNETID ;// 对应于Cube配置表的BACNET_ID
     static const QString JSON_COMMAND_BACNETDEVID ;// 对应于peripheral device的bacnetid
     static const QString JSON_COMMAND_BRANDNAME ;// 对应于peripheral device的brandname
     static const QString JSON_COMMAND_SETTEMP ;
     static const QString JSON_COMMAND_CURRTEMP ;
     static const QString JSON_COMMAND_AIRCONMODE ;
     static const QString JSON_COMMAND_FANSPEED ;
     static const QString JSON_COMMAND_SWITCHSTATUS ;
     static const QString JSON_COMMAND_PERCENT ;
     static const QString JSON_COMMAND_ZONETYPE ;
     static const QString JSON_COMMAND_ALARMTIMER ;
     static const QString JSON_COMMAND_ALARMTYPE ;
     static const QString JSON_COMMAND_ALARMTIMESTAMP ; // time that alarm happens
     static const QString JSON_COMMAND_ARMTYPE ;
     static const QString JSON_COMMAND_RTSPURL ;
     static const QString JSON_COMMAND_AIR ;
     static const QString JSON_COMMAND_CURRTIME ;
     static const QString JSON_COMMAND_CURRCO2 ;
     static const QString JSON_COMMAND_CURRPM25 ;
     static const QString JSON_COMMAND_CURRHUMID ;
     static const QString JSON_COMMAND_CURRAIRQUAL ;
     static const QString JSON_COMMAND_CURRAIRLUMI ;
     static const QString JSON_COMMAND_HNSADDR ;
     static const QString JSON_COMMAND_CALLMSG ;
     static const QString JSON_COMMAND_CALLTYPE ;
     static const QString JSON_COMMAND_RESPONSECMD ;
     static const QString JSON_COMMAND_VIDEOPORT ;
     static const QString JSON_COMMAND_AUDIOPORT ;
     static const QString JSON_COMMAND_VIDEOCODECTYPE ;
     static const QString JSON_COMMAND_AUDIOCODECTYPE ;
     static const QString JSON_COMMAND_VIDEORATIO ;
     static const QString JSON_COMMAND_TAKECALLIPADDR ;
     static const QString JSON_COMMAND_DOOROPENTYPE ;
     static const QString JSON_COMMAND_DOOROPENWAY ;
     static const QString JSON_COMMAND_DOOROPENROLE ;
     static const QString JSON_COMMAND_DOOROPENID ;
     static const QString JSON_COMMAND_IPCTYPE ;
     static const QString JSON_COMMAND_IPCURL ;
     static const QString JSON_COMMAND_IPCUSERNAME ;
     static const QString JSON_COMMAND_IPCPWD ;
     static const QString JSON_COMMAND_DISTURBTYPE ;
     static const QString JSON_COMMAND_KEYID ;
     static const QString JSON_COMMAND_VERSION ;
     static const QString JSON_COMMAND_URL ;
     static const QString JSON_COMMAND_UPGRADECMD ;
     static const QString JSON_COMMAND_UPGRADETYPE ;
     static const QString JSON_COMMAND_CONTROLTYPE ;
     static const QString JSON_COMMAND_CONFIGDATA ;
     static const QString JSON_COMMAND_CONFIGTYPE ;
     static const QString JSON_COMMAND_PORT ;
     static const QString JSON_COMMAND_TIMER ;
     static const QString JSON_COMMAND_SUBDEVTYPE ;
     static const QString JSON_COMMAND_MODULELOOPMAP ;
     static const QString JSON_COMMAND_ISCONFIG ;
     static const QString JSON_COMMAND_ISONLINE ;
     static const QString JSON_COMMAND_ISENABLE ;
     static const QString JSON_COMMAND_SERIALNO ;
     static const QString JSON_COMMAND_SCENARIOID ;
     static const QString JSON_COMMAND_SECURITY_PWD ;
     static const QString JSON_COMMAND_ISARM ;
     static const QString JSON_COMMAND_MODULESERIALNUM ;
     static const QString JSON_COMMAND_MACHINETYPE ;
     static const QString JSON_COMMAND_LOOPNUM ;
     static const QString JSON_COMMAND_KEYTYPE ;
     static const QString JSON_COMMAND_KEYVALUE ;
     static const QString JSON_COMMAND_KEYTYPELOOP ;
     static const QString JSON_COMMAND_BACKAUDIODEVMAP ;
     static const QString JSON_COMMAND_POWER ;
     static const QString JSON_COMMAND_VOLUME ;
     static const QString JSON_COMMAND_MUTE ;
     static const QString JSON_COMMAND_PLAYSTATUS ;
     static const QString JSON_COMMAND_SINGLECYCLE ;
     static const QString JSON_COMMAND_SOURCE ;
     static const QString JSON_COMMAND_SWITCHSONG ;
     static const QString JSON_COMMAND_SONGNAME ;
     static const QString JSON_COMMAND_PLAYTIME ;
     static const QString JSON_COMMAND_ALLPLAYTIME ;

     static const QString JSON_COMMAND_ALARMENABLE ;
     static const QString JSON_COMMAND_SLAVEADDR ;
     static const QString JSON_COMMAND_PWD_VERIFY ;
     static const QString JSON_COMMAND_SCENARIOLOOMAP ;
     static const QString JSON_COMMAND_ROOMLOOPMAP ;
     static const QString JSON_COMMAND_WIFIIRCMD ;
     static const QString JSON_COMMAND_IRCODE ;
     static const QString JSON_COMMAND_UUID ;
     static const QString JSON_COMMAND_CALLSESSIONID ;
     static const QString JSON_COMMAND_PUSHEXCLUDES ;
     static const QString JSON_COMMAND_DESCRITPION ;
     static const QString JSON_COMMAND_CONDITION ;
     static const QString JSON_COMMAND_VALUE ;

    /* ACTION maybe values */
     static const QString JSON_COMMAND_ACTION_REQUEST ;
     static const QString JSON_COMMAND_ACTION_RESPONSE ;
     static const QString JSON_COMMAND_ACTION_EVENT ;

    /* SUBACTION maybe values */
     static const QString JSON_COMMAND_SUBACTION_UNKNOWN ;
     static const QString JSON_COMMAND_SUBACTION_SETDEV ;
     static const QString JSON_COMMAND_SUBACTION_READDEV ;
     static const QString JSON_COMMAND_SUBACTION_RELAYINFO ;
     static const QString JSON_COMMAND_SUBACTION_CONFIGDEV ;
     static const QString JSON_COMMAND_SUBACTION_DEVICEINFO ;
     static const QString JSON_COMMAND_SUBACTION_CONFIGMODULE ;
     static const QString JSON_COMMAND_SUBACTION_GETDEVCONF ;
     static const QString JSON_COMMAND_SUBACTION_GETDEVCONFIPVDP ;
     static const QString JSON_COMMAND_SUBACTION_DELDEV ;
     static const QString JSON_COMMAND_SUBACTION_ALARMINFO ;
     static const QString JSON_COMMAND_SUBACTION_EVIROINFO ;
     static const QString JSON_COMMAND_SUBACTION_ARM ;
     static const QString JSON_COMMAND_SUBACTION_IPCMONITOR ;
     static const QString JSON_COMMAND_SUBACTION_CALL ;
     static const QString JSON_COMMAND_SUBACTION_BACKUPCONF ;
     static const QString JSON_COMMAND_SUBACTION_REVERTCONF ;
     static const QString JSON_COMMAND_SUBACTION_DISTURB ;
     static const QString JSON_COMMAND_SUBACTION_SCENARIOCTRL ;
     static const QString JSON_COMMAND_SUBACTION_TRIGGER ;
     static const QString JSON_COMMAND_SUBACTION_HDMICTRL ;
     static const QString JSON_COMMAND_SUBACTION_REGISTER ;
     static const QString JSON_COMMAND_SUBACTION_HEARTBEAT ;
     static const QString JSON_COMMAND_SUBACTION_GETNEWMODULELIST ;
     static const QString JSON_COMMAND_SUBACTION_DISCOVERMODULE ;
     static const QString JSON_COMMAND_SUBACTION_BACKAUDIOINFO ;
     static const QString JSON_COMMAND_SUBACTION_CONFIGSECURITY ;


     static const QString JSON_COMMAND_SUBACTION_GETARMZONECONFIG ;
     static const QString JSON_COMMAND_SUBACTION_MODIFYARMZONECONFIG ;
     static const QString JSON_COMMAND_SUBACTION_GETGETSCENARIOCONFIG ;
     static const QString JSON_COMMAND_SUBACTION_GETTRIGGERRULECONFIG ;
     static const QString JSON_COMMAND_SUBACTION_GETALLTRIGGERRULECONFIG ;
     static const QString JSON_COMMAND_SUBACTION_GETALLMUTEXRULECONFIG ;
     static const QString JSON_COMMAND_SUBACTION_GETMUTEXRULECONFIG ;
     static const QString JSON_COMMAND_SUBACTION_GETSCHEDULERULECONFIG ;
     static const QString JSON_COMMAND_SUBACTION_SUBPHONEINFO ;
     static const QString JSON_COMMAND_SUBACTION_CUBEDEVEVENT ;
     static const QString JSON_COMMAND_SUBACTION_UPGRADE ;
     static const QString JSON_COMMAND_SUBACTION_SYSTEMSECURITYSTATE ;

     static const QString JSON_COMMAND_MESSAGEID ;
     static const QString JSON_COMMAND_PWDVERIFY ;

    /* WIFI IR Specific command (sub-action) */
     static const QString JSON_COMMAND_ACTION_IRCMD ;
    //  static const QString JSON_COMMAND_ACTION_IRDATA ;
     static const QString JSON_COMMAND_ACTION_WIFIIR_SND ;
     static const QString JSON_COMMAND_ACTION_WIFIIR_STDY ;
     static const QString JSON_COMMAND_ACTION_WIFIIR_WICFG ;
     static const QString JSON_COMMAND_WIFIIRTYPE ;
     static const QString JSON_COMMAND_WIFIIRNAME ;
     static const QString JSON_COMMAND_WIFIIRLOCK ;
     static const QString JSON_COMMAND_WIFIIRPWD ;
     static const QString JSON_COMMAND_WIFIIRID ;
     static const QString JSON_COMMAND_WIFIIRSUBDEVICE ;
     static const QString JSON_COMMAND_WIFIIRKEY ;
     static const QString JSON_COMMAND_TYPE ;
     static const QString JSON_COMMAND_NAME ;
     static const QString JSON_COMMAND_IMAGENAME ;
     static const QString JSON_COMMAND_WIFIIRDATA ;
     static const QString JSON_COMMAND_DATA ;
     static const QString JSON_COMMAND_WIFI_SSID ;
     static const QString JSON_COMMAND_WIFI_PWD ;
     static const QString JSON_COMMAND_THRD_IR_SUBSERVICE ;
     static const QString JSON_COMMAND_THRD_IR_CONTROL ;
     static const QString JSON_COMMAND_REMOTECONTROL_ID ;

    /* IPC Specific command */
     static const QString JSON_COMMAND_ACTION_IPCCMD ;
     static const QString JSON_COMMAND_ACTION_IPCREC_START ;
     static const QString JSON_COMMAND_ACTION_IPCREC_STOP ;
     static const QString JSON_COMMAND_ACTION_IPCDISP_START ;
     static const QString JSON_COMMAND_ACTION_IPCDISP_STOP ;
     static const QString JSON_COMMAND_ACTION_IPC_GETINFO ;
     static const QString JSON_COMMAND_DATA_IPC_IP ;
     static const QString JSON_COMMAND_DATA_IPC_PORT ;
     static const QString JSON_COMMAND_DATA_IPC_URL ;
     static const QString JSON_COMMAND_DATA_IPC_RTTYPE ;
     static const QString JSON_COMMAND_DATA_P2P_UUID ;
     static const QString JSON_COMMAND_DATA_P2P_IP ;
     static const QString JSON_COMMAND_DATA_IPC_VWIDTH ;
     static const QString JSON_COMMAND_DATA_IPC_VHEIGHT ;
     static const QString JSON_COMMAND_DATA_IPC_VCODEC ;
     static const QString JSON_COMMAND_DATA_IPC_RECTIME ;
     static const QString JSON_COMMAND_MAINSTREAM ;
     static const QString JSON_COMMAND_SUBSTREAM ;
     static const QString JSON_COMMAND_AVAILABLETIME ;
     static const QString JSON_COMMAND_DELAYTIME ;
     static const QString JSON_COMMAND_STARTTIME ;
     static const QString JSON_COMMAND_ENDTIME ;
     static const QString JSON_COMMAND_FREQUENCY ;
     static const QString JSON_COMMAND_TRIGGERTYPE ;
     static const QString JSON_COMMAND_CUSTOMIZEDAYS ;
     static const QString JSON_COMMAND_TRIGGERNAME ;
     static const QString JSON_COMMAND_TRIGGERDESCRIPTION ;
     static const QString JSON_COMMAND_TRIGGERCONDITION ;
     static const QString JSON_COMMAND_SCHEDULEACTION ;
     static const QString JSON_COMMAND_TRIGGERACTION ;
     static const QString JSON_COMMAND_TRIGGERID ;
     static const QString JSON_COMMAND_SCHEDULEID ;
     static const QString JSON_COMMAND_MUTEXID ;

    // upgrade commands
     static const QString JSON_COMMAND_UPGRADE_GETPACK ;
     static const QString JSON_COMMAND_UPGRADE_NEWVER ;
     static const QString JSON_COMMAND_UPGRADE_START ;
     static const QString JSON_COMMAND_UPGRADE_QUERY ;
     static const QString JSON_COMMAND_UPGRADE_GETVER ;

    // backup
    //  static const QString JSON_COMMON_DATABASE_FILE ;
     static const QString JSON_COMMAND_BACKUP_RETENTION ;
     static const QString JSON_COMMAND_BACKUP_CREATE ;
     static const QString JSON_COMMAND_BACKUP_ID ;

     static const QString JSON_COMMAND_CONTROLMAP ;

     static const QString JSON_COMMAND_PRIMARYID ;
     static const QString JSON_COMMAND_RESPONSEPRIMARYID ;
     static const QString JSON_COMMAND_SUBRESPONSEPRIMARYID ;

     static const QString JSON_COMMAND_CURRAIRQUAL_INVALID ;
     static const QString JSON_COMMAND_CURRAIRQUAL_CLEAN ;
     static const QString JSON_COMMAND_CURRAIRQUAL_SLIGHT ;
     static const QString JSON_COMMAND_CURRAIRQUAL_MODERATE ;
     static const QString JSON_COMMAND_CURRAIRQUAL_SERIOUS ;

     static const QString JSON_COMMAND_PORTMAP ;
     static const QString JSON_COMMAND_CUBEDEV_EVENT_TYPE ;
     static const QString JSON_COMMAND_DATA_SDCARD_IN ;   //sd
     static const QString JSON_COMMAND_DATA_SDCARD_OUT ;
     static const QString JSON_COMMAND_DATA_SDCARD_ERR ;
     static const QString JSON_COMMAND_DATA_USBDISK_IN ; //usb disk
     static const QString JSON_COMMAND_DATA_USBDISK_OUT ;
     static const QString JSON_COMMAND_DATA_RECORD_FAIL ;  //录像失败，例如无卡/卡损坏
     static const QString JSON_COMMAND_RECORDTIME ;

    /* alarm history specified keys for cloud */
     static const QString ALARM_MESSAGE_SENSORTYPE ;
     static const QString ALARM_MESSAGE_ALARMTYPE ;
     static const QString ALARM_MESSAGE_ALARMTIMESTAMP ; // time that alarm happens
     static const QString ALARM_MESSAGE_ALARMMSGID ;
     static const QString ALARM_MESSAGE_LOOPNAME ;
     static const QString ALARM_MESSAGE_ROOMNAME ;
     static const QString ALARM_MESSAGE_MODULEADDR ;
     static const QString ALARM_MESSAGE_MODULETYPE ;
     static const QString ALARM_MESSAGE_LOOPID ;
    /* frequency */
     static const QString FREQUENCY_SINGLE ;
     static const QString FREQUENCY_EVERYDAY ;
     static const QString FREQUENCY_EVERYWORKDAY ;
     static const QString FREQUENCY_EVERYWEEKEND ;
     static const QString FREQUENCY_CUSTOMIZE ;
     static const QString FREQUENCY_CUSTOMIZE_DAY ;
     static const QString FREQUENCY_CUSTOMIZE_SUNDAY ;
     static const QString FREQUENCY_CUSTOMIZE_MONDAY ;
     static const QString FREQUENCY_CUSTOMIZE_TUESDAY ;
     static const QString FREQUENCY_CUSTOMIZE_WEDNESDAY ;
     static const QString FREQUENCY_CUSTOMIZE_THURSDAY ;
     static const QString FREQUENCY_CUSTOMIZE_FRIDAY ;
     static const QString FREQUENCY_CUSTOMIZE_SATURDAY ;

    /* loop type */
     static const QString LOOP_TYPE_LIGHT ;
     static const QString LOOP_TYPE_CURTAIN ;
     static const QString LOOP_TYPE_RELAY ;
     static const QString LOOP_TYPE_SWITCH ;// maia分light和 switch
     static const QString LOOP_TYPE_SENSOR ;

    /* 433 type */
     static const QString SENSOR_TYPE_433_INFRADE ;
     static const QString SENSOR_TYPE_433_KEYFOB ;
     static const QString SENSOR_TYPE_433_DOORMAGNETI ;

     static const int LOOP_TYPE_LIGHT_INT ;
     static const int LOOP_TYPE_CURTAIN_INT ;
     static const int LOOP_TYPE_RELAY_INT ;
     static const int LOOP_TYPE_SWITCH_INT ;
     static const int LOOP_TYPE_SENSOR_INT ;
     static const int LOOP_TYPE_5800PIRAP_INT ;
     static const int LOOP_TYPE_5804EU_INT ;
     static const int LOOP_TYPE_5816EU_INT ;

    /* switch status type */
     static const QString SWITCHSTATUS_TYPE_ON ;
     static const QString SWITCHSTATUS_TYPE_OFF ;
     static const QString SWITCHSTATUS_TYPE_OPEN ;
     static const QString SWITCHSTATUS_TYPE_CLOSE ;
     static const QString SWITCHSTATUS_TYPE_STOP ;

     static const QString MODE_TYPE_COOL ;
     static const QString MODE_TYPE_HEAT ;
     static const QString MODE_TYPE_VENLITATION ;
     static const QString MODE_TYPE_AUTO ;
     static const QString MODE_TYPE_DEHUMIDIFY ;

     static const QString AC_FAN_SPPED_LOW ;
     static const QString AC_FAN_SPPED_MIDDLE ;
     static const QString AC_FAN_SPPED_HIGH ;
     static const QString AC_FAN_SPPED_AUTO ;


    // for wifi module type value(5~10为wifi module)
     static const int MODULE_TYPE_SPARKLIGHTING ;
     static const int MODULE_TYPE_BACNET ;
     static const int MODULE_TYPE_IPC ;
     static const int MODULE_TYPE_WIFIIR ;
     static const int MODULE_TYPE_WIFIAIR ;
     static const int MODULE_TYPE_WIFIRELAY ;
     static const int MODULE_TYPE_WIFI485 ;
     static const int MODULE_TYPE_WIREDZONE ;
     static const int MODULE_TYPE_WIFI315M433M ;
     static const int MODULE_TYPE_BACKAUDIO ;
     static const int MODULE_TYPE_ALARMZONE ;
     static const int MODULE_TYPE_IPVDP ;
     static const int MODULE_TYPE_SCENARIO ;
     static const int MODULE_TYPE_SCENARIOTRIGGER ;
     static const int MODULE_TYPE_MUTEXRULE ;
     static const int MODULE_TYPE_SCHEDULERULE ;
     static const int MODULE_TYPE_ROOM ;

    /* module type maybe values */
     static const QString JSON_COMMAND_MODULETYPE_485 ;
     static const QString JSON_COMMAND_MODULETYPE_BACNET ;
     static const QString JSON_COMMAND_MODULETYPE_SPARKLIGHT ;
     static const QString JSON_COMMAND_MODULETYPE_WIREDZONE ;
     static const QString JSON_COMMAND_MODULETYPE_315M433 ;
     static const QString JSON_COMMAND_MODULETYPE_IPC ;
     static const QString JSON_COMMAND_MODULETYPE_IR ;
     static const QString JSON_COMMAND_MODULETYPE_RELAY ;
     static const QString JSON_COMMAND_MODULETYPE_AIR ;
     static const QString JSON_COMMAND_MODULETYPE_IPVDP ;
     static const QString JSON_COMMAND_MODULETYPE_NFC ;
     static const QString JSON_COMMAND_MODULETYPE_BACKAUDIO ;
     static const QString JSON_COMMAND_MODULETYPE_CUBE ;
     static const QString JSON_COMMAND_MODULETYPE_DIGITALLOCK ;
     static const QString JSON_COMMAND_MODULETYPE_ELEVATOR ;
     static const QString JSON_COMMAND_MODULETYPE_SCENARIO ;
     static const QString JSON_COMMAND_MODULETYPE_ALARMZONE ;
     static const QString JSON_COMMAND_MODULETYPE_SCENARIOTRIGGER ;
     static const QString JSON_COMMAND_MODULETYPE_MUTEXRULE ;
     static const QString JSON_COMMAND_MODULETYPE_SCHEDULERULE ;
     static const QString JSON_COMMAND_MODULETYPE_ROOM ;
     static const QString JSON_COMMAND_MODULETYPE_VENTILATION ;
     static const QString JSON_COMMAND_MODULETYPE_COMMON_DEVICE ;


    // for all sparklighting sub_dev_type
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSD0403 ;// QString,
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSD0602 ;// QString,
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSD0610DC ;// QString,
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSD0605_LED ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSC02 ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSR0410 ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSR0810 ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSR1210 ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSI04LED ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSI08 ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSSIR ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSSTLA ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSGW ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSP750 ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSP2400 ;
     const static QString SPARKLIGHT_SUBDEVTYPE_HBLSSoftware ;


    // ALARMS from ipvdp system
     static const QString ZONE_ALARM_STATUS_GAS ;
     static const QString ZONE_ALARM_STATUS_FIRE ;
     static const QString ZONE_ALARM_STATUS_HELP ;
     static const QString ZONE_ALARM_STATUS_THIEF ;
     static const QString ZONE_ALARM_STATUS_EMERGENCY ;


     static const QString ZONE_TYPE_SECURITY_INSTANT ;
     static const QString ZONE_TYPE_SECURITY_24HOURS ;
     static const QString ZONE_TYPE_SECURITY_DELAY ;

     static const QString IPCAMERA_TYPE_PHOENIX ;
     static const QString IPCAMERA_TYPE_SUPER_HD ;

     static const QString WIFI485_AC_TYPE_ECC_O1 ;
     static const QString WIFI485_AC_TYPE_HTC ;
     static const QString WIFI485_AC_TYPE_ECC_DT300 ;
     static const QString WIFI485_AC_TYPE_SIMENS_RDF302 ;

     static const QString WIFI485_AC_TYPE_DAKIN_DTA ;
     static const QString WIFI485_AC_TYPE_Dakin_R4R5 ;
     static const QString WIFI485_AC_TYPE_TOSHIBA_TCB ;
     static const QString WIFI485_AC_TYPE_YORK_YVOH_A ;
     static const QString WIFI485_AC_TYPE_YORK_4_IN_1 ;
     static const QString WIFI485_AC_TYPE_HUANGPUWAN ;


     const static QString DEVICETYPE_MAIA2 ;
     const static QString DEVICETYPE_SENSOR ;
     const static QString DEVICETYPE_AIRCONDITION ;
     const static QString DEVICETYPE_THERMOSTAT ;
     const static QString DEVICETYPE_VENTILATION ;
     const static QString DEVICETYPE_CURTAIN ;

     static const QString FIRST_SEPARATOR ;
     static const QString SECOND_SEPARATOR ;
     static const QString DAY_SEPARATOR ;
     static const QString CONTROLMAP_SEPARATOR ;

     const static int SCENARIO_ID_HOME ;
     const static int SCENARIO_ID_LEAVE ;
     const static int SCENARIO_ID_ARMALL ;
     const static int SCENARIO_ID_DISARMALL ;

     const static QString SCENARIO_HOME_NAME ;
     const static QString SCENARIO_LEAVE_NAME ;
     const static QString SCENARIO_ARMALL_NAME ;
     const static QString SCENARIO_DISARMALL_NAME ;

     const static QString IRLOOPTYPE_DVD ;
     const static QString IRLOOPTYPE_TV ;
     const static QString IRLOOPTYPE_FAN ;
     const static QString IRLOOPTYPE_AIR ;
     const static int SCENARIO_ID_BASIC ;

     const static QString DEFAULTSECURITYPWD ;
     const static QString DEFAULT_DEV_SERIAL_NUMBER ;
     const static QString DEFAULTIPCUSER ;
     const static QString DEFAULTIPCPWD ;
     const static int DEFAULTIPCSTREAMPORT ;

    /**
     * upgrade info
     */
     const static QString UPGRADE_RELEASEDATE ;
     const static QString UPGRADE_UPGRADECMD ;
     const static QString UPGRADE_DESCRIPTION ;
     const static QString UPGRADE_VERSION ;

    /**
     * Scenario 部分，三级页面获取设备列表和Zone列表，用于Event返回数据
     */
     const static QString SCENARIO_EDIT_GET_DEVICES ;
     const static QString SCENARIO_EDIT_GET_ZONES ;
};

#endif // COMMONDATA_H
