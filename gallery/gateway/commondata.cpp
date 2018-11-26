#include "commondata.h"

CommonData::CommonData()
{

}

// user password fileName
const   QString CommonData::APP_LOGIN_VIEW_IS_ADDED = "app_login_view_is_added";
const   QString CommonData::APP_USER_PASSWORD_FILENAME = "app_user_password_file";


 // wiredzone，sparklighting，433 wireless zone 配置修改
const   QString CommonData::ACTION_DEV_MODIFYARMZONECONFIG = "com.honeywell.cubebase.broadcast.configservice.modifyarmzoneconfig";
const   QString CommonData::ACTION_DEV_MODIFYTRIGGERRULECONFIG = "com.honeywell.cubebase.broadcast.configservice.modifytriggerruleconfig";
const   QString CommonData::ACTION_DEV_MODIFYMUTEXRULECONFIG = "com.honeywell.cubebase.broadcast.configservice.modifymutexruleconfig";
const   QString CommonData::ACTION_DEV_MODIFYSCHEDULERULECONFIG = "com.honeywell.cubebase.broadcast.configservice.modifyscheduleruleconfig";

 // JSON协议解析：发送广播时，二进制JSON数据，对应的名字
const   QString CommonData::ACTION_SCHEDULE_SYSTEM_ALARM = "com.honeywell.cubebase.configcenter.schedule";
const   QString CommonData::EXTRA_DATA_NAME = "JSONDATA";
const   QString CommonData::EXTRA_DATA_LEN = "JSONDATALEN";
 // The Json message comes from cloud or LAN
const   QString CommonData::EXTRA_DATA_FROM = "JSONDATAFROM";
const   QString CommonData::EXTRA_DATA_FROM_LAN = "DATAFROMLAN";
const   QString CommonData::EXTRA_DATA_FROM_CLOUD = "DATAFROMCLOUD";
const   QString CommonData::EXTRA_DATA_FROM_THIRDPARTY = "DATAFROMTHIRDPARTY";
const   QString CommonData::EXTRA_DATA_FROM_WIFIMODULE = "DATAFROMWIFIMODULE";
const   QString CommonData::EXTRA_DATA_FROM_CONFIGSERVICE = "DATAFROMCONFIGSERVICE";
const   QString CommonData::EXTRA_DATA_FROM_SECURITYSERVICE = "DATAFROMSECURITYSERVICE";
const   QString CommonData::EXTRA_DATA_FROM_CONTROLSERVICE = "DATAFROMCONTROLSERVICE";
const   QString CommonData::EXTRA_DATA_FROM_EXTENSIONTELSERVICE = "DATAFROMEXTENSIONTELSERVICE";
const   QString CommonData::EXTRA_DATA_FROM_VOICERECGONIZE = "DATAFROMVOICERECGONIZE";
const   QString CommonData::EXTRA_DATA_ID = "JSONCLIENTID";


 //Cube database info
const QString CommonData::APPDATABASEFILE = "cube_database_file";
const int CommonData::APPDATABASEVersion = 1;


const int CommonData::ONLINE = 1;
const int CommonData::NOTONLINE = 0;

const int CommonData::ARM_TYPE_DISABLE = 0;
const int CommonData::ARM_TYPE_ENABLE = 1;

const int CommonData::HASCONFIG = 1;
const int CommonData::NOTCONFIG = 0;

const QString CommonData::ARM_TYPE_DISABLE_STR = "off";
const QString CommonData::ARM_TYPE_ENABLE_STR = "on";

const QString CommonData::ARM_TYPE_ARM_STR = "arm";
const QString CommonData::ARM_TYPE_DISARM_STR = "disarm";

 /**
  * Field name for JSON Parser
  */
 //AppInfo Login responce
const QString CommonData::JSON_LOGIN_RESPONCE_PHONEID = "phoneId";
const QString CommonData::JSON_HTTP_SET_USER_COOKIE = "Set-Cookie";

 //cookie for websocket
const QString CommonData::JSON_WEBSOCKET_USER_COOKIE = "Cookie";
const QString CommonData::JSON_WEBSOCKET_USER_ORIGIN = "Origin";


 //Login get bind cube
const QString CommonData::JSON_LOGIN_GET_CUBE_RESPONCE_DEVICES = "devices";
const QString CommonData::JSON_LOGIN_GET_CUBE_RESPONCE_DEVICEID = "deviceId";
const QString CommonData::JSON_LOGIN_GET_CUBE_RESPONCE_DEVICEINFO = "deviceInfo";
const QString CommonData::JSON_LOGIN_GET_CUBE_RESPONCE_DEVICE_CUBE_SERIAL_NUMBER = "serialnumber";


const QString CommonData::JSON_COMMAND_MSGID = "msgid";
const QString CommonData::JSON_COMMAND_ACTION = "action";
const QString CommonData::JSON_COMMAND_ACTIONINFO = "actioninfo";
const QString CommonData::JSON_COMMAND_SUBACTION = "subaction";
const QString CommonData::JSON_COMMAND_CUBEID = "cubeid";
const QString CommonData::JSON_COMMAND_CUBEPWD = "cubepwd";
const QString CommonData::JSON_COMMAND_CUBEOLDPWD = "cubeoldpwd";
const QString CommonData::JSON_COMMAND_CLOUDID = "cloudid";
const QString CommonData::JSON_COMMAND_CLOUDPWD = "cloudpwd";
const QString CommonData::JSON_COMMAND_MODULETYPE = "moduletype";
const QString CommonData::JSON_COMMAND_MODULEMACADDR = "modulemacaddr";
const QString CommonData::JSON_COMMAND_MODULEIPADDR = "moduleipaddr";
const QString CommonData::JSON_COMMAND_MODULEPORT = "moduleport";
const QString CommonData::JSON_COMMAND_DEVICETYPE = "devicetype";
const QString CommonData::JSON_COMMAND_ALIAS = "aliasname";
const QString CommonData::JSON_COMMAND_ROOMNAME = "roomname";
const QString CommonData::JSON_COMMAND_ROOMID = "roomid";

const QString CommonData::JSON_COMMAND_ERRORCODE = "errorcode";
const QString CommonData::JSON_COMMAND_DEVLOOPMAP = "deviceloopmap";
const QString CommonData::JSON_COMMAND_DEVID = "deviceid";
const QString CommonData::JSON_COMMAND_LOOPID = "loopid";
const QString CommonData::JSON_COMMAND_LOOPTYPE = "looptype";
const QString CommonData::JSON_COMMAND_MASKID = "maskid";
const QString CommonData::JSON_COMMAND_SPARKLIGHTINGDEVMAP = "sparklightingdevmap";
const QString CommonData::JSON_COMMAND_PORTID = "portid";
const QString CommonData::JSON_COMMAND_PORTRATE = "portrate";
const QString CommonData::JSON_COMMAND_CUBEBACNETID = "cubebacnetid";// 对应于Cube配置表的BACNET_ID
const QString CommonData::JSON_COMMAND_BACNETDEVID = "bacnetdeviceid";// 对应于peripheral device的bacnetid
const QString CommonData::JSON_COMMAND_BRANDNAME = "brandname";// 对应于peripheral device的brandname
const QString CommonData::JSON_COMMAND_SETTEMP = "settemp";
const QString CommonData::JSON_COMMAND_CURRTEMP = "currenttemp";
const QString CommonData::JSON_COMMAND_AIRCONMODE = "mode";
const QString CommonData::JSON_COMMAND_FANSPEED = "fanspeed";
const QString CommonData::JSON_COMMAND_SWITCHSTATUS = "status";
const QString CommonData::JSON_COMMAND_PERCENT = "openclosepercent";
const QString CommonData::JSON_COMMAND_ZONETYPE = "zonetype";
const QString CommonData::JSON_COMMAND_ALARMTIMER = "alarmtimer";
const QString CommonData::JSON_COMMAND_ALARMTYPE = "alarmtype";
const QString CommonData::JSON_COMMAND_ALARMTIMESTAMP = "timestamp"; // time that alarm happens
const QString CommonData::JSON_COMMAND_ARMTYPE = "armtype";
const QString CommonData::JSON_COMMAND_RTSPURL = "rtspurl";
const QString CommonData::JSON_COMMAND_AIR = "airtype";
const QString CommonData::JSON_COMMAND_CURRTIME = "currenttime";
const QString CommonData::JSON_COMMAND_CURRCO2 = "currentco2";
const QString CommonData::JSON_COMMAND_CURRPM25 = "currentpm2_5";
const QString CommonData::JSON_COMMAND_CURRHUMID = "currenthumid";
const QString CommonData::JSON_COMMAND_CURRAIRQUAL = "currentairqual";
const QString CommonData::JSON_COMMAND_CURRAIRLUMI = "currentluminance";
const QString CommonData::JSON_COMMAND_HNSADDR = "hnsserveraddr";
const QString CommonData::JSON_COMMAND_CALLMSG = "callmsg";
const QString CommonData::JSON_COMMAND_CALLTYPE = "calltype";
const QString CommonData::JSON_COMMAND_RESPONSECMD = "responsecmd";
const QString CommonData::JSON_COMMAND_VIDEOPORT = "videoport";
const QString CommonData::JSON_COMMAND_AUDIOPORT = "audioport";
const QString CommonData::JSON_COMMAND_VIDEOCODECTYPE = "videocodectype";
const QString CommonData::JSON_COMMAND_AUDIOCODECTYPE = "audiocodectype";
const QString CommonData::JSON_COMMAND_VIDEORATIO = "videoratio";
const QString CommonData::JSON_COMMAND_TAKECALLIPADDR = "takecallipaddr";
const QString CommonData::JSON_COMMAND_DOOROPENTYPE = "dooropentype";
const QString CommonData::JSON_COMMAND_DOOROPENWAY = "dooropenway";
const QString CommonData::JSON_COMMAND_DOOROPENROLE = "dooropenrole";
const QString CommonData::JSON_COMMAND_DOOROPENID = "dooropenid";
const QString CommonData::JSON_COMMAND_IPCTYPE = "ipctype";
const QString CommonData::JSON_COMMAND_IPCURL = "ipcurl";
const QString CommonData::JSON_COMMAND_IPCUSERNAME = "ipcusername";
const QString CommonData::JSON_COMMAND_IPCPWD = "ipcpassword";
const QString CommonData::JSON_COMMAND_DISTURBTYPE = "disturbtype";
const QString CommonData::JSON_COMMAND_KEYID = "keyid";
const QString CommonData::JSON_COMMAND_VERSION = "version";
const QString CommonData::JSON_COMMAND_URL = "url";
const QString CommonData::JSON_COMMAND_UPGRADECMD = "upgradecmd";
const QString CommonData::JSON_COMMAND_UPGRADETYPE = "upgradetype";
const QString CommonData::JSON_COMMAND_CONTROLTYPE = "controltype";
const QString CommonData::JSON_COMMAND_CONFIGDATA = "configdata";
const QString CommonData::JSON_COMMAND_CONFIGTYPE = "configtype";
const QString CommonData::JSON_COMMAND_PORT = "port";
const QString CommonData::JSON_COMMAND_TIMER = "time";
const QString CommonData::JSON_COMMAND_SUBDEVTYPE = "subdevtype";
const QString CommonData::JSON_COMMAND_MODULELOOPMAP = "moduleloopmap";
const QString CommonData::JSON_COMMAND_ISCONFIG = "isconfig";
const QString CommonData::JSON_COMMAND_ISONLINE = "isonline";
const QString CommonData::JSON_COMMAND_ISENABLE = "isenable";
const QString CommonData::JSON_COMMAND_SERIALNO = "serialnumber";
const QString CommonData::JSON_COMMAND_SCENARIOID = "scenarioid";
const QString CommonData::JSON_COMMAND_SECURITY_PWD = "securitypwd";
const QString CommonData::JSON_COMMAND_ISARM = "isarm";
const QString CommonData::JSON_COMMAND_MODULESERIALNUM = "moduleserialnum";
const QString CommonData::JSON_COMMAND_MACHINETYPE = "machinetype";
const QString CommonData::JSON_COMMAND_LOOPNUM = "loopnum";
const QString CommonData::JSON_COMMAND_KEYTYPE = "keytype";
const QString CommonData::JSON_COMMAND_KEYVALUE = "keyvalue";
const QString CommonData::JSON_COMMAND_KEYTYPELOOP = "keytypeloop";
const QString CommonData::JSON_COMMAND_BACKAUDIODEVMAP = "backaudiodevmap";
const QString CommonData::JSON_COMMAND_POWER = "power";
const QString CommonData::JSON_COMMAND_VOLUME = "volume";
const QString CommonData::JSON_COMMAND_MUTE = "mute";
const QString CommonData::JSON_COMMAND_PLAYSTATUS = "playstatus";
const QString CommonData::JSON_COMMAND_SINGLECYCLE = "singlecycle";
const QString CommonData::JSON_COMMAND_SOURCE = "source";
const QString CommonData::JSON_COMMAND_SWITCHSONG = "switchsong";
const QString CommonData::JSON_COMMAND_SONGNAME = "songname";
const QString CommonData::JSON_COMMAND_PLAYTIME = "playtime";
const QString CommonData::JSON_COMMAND_ALLPLAYTIME = "allplaytime";

const QString CommonData::JSON_COMMAND_ALARMENABLE = "alarmenable";
const QString CommonData::JSON_COMMAND_SLAVEADDR = "slaveaddr";
const QString CommonData::JSON_COMMAND_PWD_VERIFY = "pwdverify";
const QString CommonData::JSON_COMMAND_SCENARIOLOOMAP = "scenarioloopmap";
const QString CommonData::JSON_COMMAND_ROOMLOOPMAP = "roomloopmap";
const QString CommonData::JSON_COMMAND_WIFIIRCMD = "ircommand";
const QString CommonData::JSON_COMMAND_IRCODE = "codeloopmap";
const QString CommonData::JSON_COMMAND_UUID = "uuid";
const QString CommonData::JSON_COMMAND_CALLSESSIONID = "callsessionid";
const QString CommonData::JSON_COMMAND_PUSHEXCLUDES = "excludefds";
const QString CommonData::JSON_COMMAND_DESCRITPION = "description";
const QString CommonData::JSON_COMMAND_CONDITION = "condition";
const QString CommonData::JSON_COMMAND_VALUE = "value";

 /* ACTION maybe values */
const QString CommonData::JSON_COMMAND_ACTION_REQUEST = "request";
const QString CommonData::JSON_COMMAND_ACTION_RESPONSE = "response";
const QString CommonData::JSON_COMMAND_ACTION_EVENT = "event";

 /* SUBACTION maybe values */
const QString CommonData::JSON_COMMAND_SUBACTION_UNKNOWN = "unknown";
const QString CommonData::JSON_COMMAND_SUBACTION_SETDEV = "setdevice";
const QString CommonData::JSON_COMMAND_SUBACTION_READDEV = "readdevice";
const QString CommonData::JSON_COMMAND_SUBACTION_RELAYINFO = "relayinfo";
const QString CommonData::JSON_COMMAND_SUBACTION_CONFIGDEV = "configdevice";
const QString CommonData::JSON_COMMAND_SUBACTION_DEVICEINFO = "deviceinfo";
const QString CommonData::JSON_COMMAND_SUBACTION_CONFIGMODULE = "configmodule";
const QString CommonData::JSON_COMMAND_SUBACTION_GETDEVCONF = "getdeviceconfig";
const QString CommonData::JSON_COMMAND_SUBACTION_GETDEVCONFIPVDP = "getdeviceconfigipvdp";
const QString CommonData::JSON_COMMAND_SUBACTION_DELDEV = "deletedevice";
const QString CommonData::JSON_COMMAND_SUBACTION_ALARMINFO = "alarminfo";
const QString CommonData::JSON_COMMAND_SUBACTION_EVIROINFO = "enviroinfo";
const QString CommonData::JSON_COMMAND_SUBACTION_ARM = "arm";
const QString CommonData::JSON_COMMAND_SUBACTION_IPCMONITOR = "ipcmonitor";
const QString CommonData::JSON_COMMAND_SUBACTION_CALL = "call";
const QString CommonData::JSON_COMMAND_SUBACTION_BACKUPCONF = "configbackup";
const QString CommonData::JSON_COMMAND_SUBACTION_REVERTCONF = "configrecovery";
const QString CommonData::JSON_COMMAND_SUBACTION_DISTURB = "disturb";
const QString CommonData::JSON_COMMAND_SUBACTION_SCENARIOCTRL = "scenariocontrol";
const QString CommonData::JSON_COMMAND_SUBACTION_TRIGGER = "trigger";
const QString CommonData::JSON_COMMAND_SUBACTION_HDMICTRL = "hdmicontrol";
const QString CommonData::JSON_COMMAND_SUBACTION_REGISTER = "register";
const QString CommonData::JSON_COMMAND_SUBACTION_HEARTBEAT = "heartbeat";
const QString CommonData::JSON_COMMAND_SUBACTION_GETNEWMODULELIST = "getnewmodulelist";
const QString CommonData::JSON_COMMAND_SUBACTION_DISCOVERMODULE = "discovermodule";
const QString CommonData::JSON_COMMAND_SUBACTION_BACKAUDIOINFO = "backaudioinfo";
const QString CommonData::JSON_COMMAND_SUBACTION_CONFIGSECURITY = "configsecurity";


const QString CommonData::JSON_COMMAND_SUBACTION_GETARMZONECONFIG = "getarmzoneconfig";
const QString CommonData::JSON_COMMAND_SUBACTION_MODIFYARMZONECONFIG = "modifyarmzoneconfig";
const QString CommonData::JSON_COMMAND_SUBACTION_GETGETSCENARIOCONFIG = "getscenarioconfig";
const QString CommonData::JSON_COMMAND_SUBACTION_GETTRIGGERRULECONFIG = "gettriggerruleconfig";
const QString CommonData::JSON_COMMAND_SUBACTION_GETALLTRIGGERRULECONFIG = "getalltriggerruleconfig";
const QString CommonData::JSON_COMMAND_SUBACTION_GETALLMUTEXRULECONFIG = "getallmutexruleconfig";
const QString CommonData::JSON_COMMAND_SUBACTION_GETMUTEXRULECONFIG = "getmutexruleconfig";
const QString CommonData::JSON_COMMAND_SUBACTION_GETSCHEDULERULECONFIG = "getscheduleruleconfig";
const QString CommonData::JSON_COMMAND_SUBACTION_SUBPHONEINFO = "subphoneinfo";
const QString CommonData::JSON_COMMAND_SUBACTION_CUBEDEVEVENT = "cubedevevent";
const QString CommonData::JSON_COMMAND_SUBACTION_UPGRADE = "upgrade";
const QString CommonData::JSON_COMMAND_SUBACTION_SYSTEMSECURITYSTATE = "systemsecuritystate";

const QString CommonData::JSON_COMMAND_MESSAGEID = "msgid";
const QString CommonData::JSON_COMMAND_PWDVERIFY = "pwdverify";

 /* WIFI IR Specific command (sub-action) */
const QString CommonData::JSON_COMMAND_ACTION_IRCMD = "ircommand";
 //const QString CommonData::JSON_COMMAND_ACTION_IRDATA = "wifiirdata";
const QString CommonData::JSON_COMMAND_ACTION_WIFIIR_SND = "send";
const QString CommonData::JSON_COMMAND_ACTION_WIFIIR_STDY = "study";
const QString CommonData::JSON_COMMAND_ACTION_WIFIIR_WICFG = "wificonfig";
const QString CommonData::JSON_COMMAND_WIFIIRTYPE = "wifiirtype";
const QString CommonData::JSON_COMMAND_WIFIIRNAME = "wifiirname";
const QString CommonData::JSON_COMMAND_WIFIIRLOCK = "wifiirlock";
const QString CommonData::JSON_COMMAND_WIFIIRPWD = "wifiirpassword";
const QString CommonData::JSON_COMMAND_WIFIIRID = "wifiirid";
const QString CommonData::JSON_COMMAND_WIFIIRSUBDEVICE = "wifiirsubdevice";
const QString CommonData::JSON_COMMAND_WIFIIRKEY = "wifiirkey";
const QString CommonData::JSON_COMMAND_TYPE = "type";
const QString CommonData::JSON_COMMAND_NAME = "name";
const QString CommonData::JSON_COMMAND_IMAGENAME = "imagename";
const QString CommonData::JSON_COMMAND_WIFIIRDATA = "wifiirdata";
const QString CommonData::JSON_COMMAND_DATA = "data";
const QString CommonData::JSON_COMMAND_WIFI_SSID = "wifissid";
const QString CommonData::JSON_COMMAND_WIFI_PWD = "wifipassword";
const QString CommonData::JSON_COMMAND_THRD_IR_SUBSERVICE = "WiFiIRSubService";
const QString CommonData::JSON_COMMAND_THRD_IR_CONTROL = "WIFIIRControl";
const QString CommonData::JSON_COMMAND_REMOTECONTROL_ID = "remotecontrolid";

 /* IPC Specific command */
const QString CommonData::JSON_COMMAND_ACTION_IPCCMD = "IPCCMD";
const QString CommonData::JSON_COMMAND_ACTION_IPCREC_START = "StartRecord";
const QString CommonData::JSON_COMMAND_ACTION_IPCREC_STOP = "StopRecord";
const QString CommonData::JSON_COMMAND_ACTION_IPCDISP_START = "StartRemoteDisplay";
const QString CommonData::JSON_COMMAND_ACTION_IPCDISP_STOP = "StopRemoteDisplay";
const QString CommonData::JSON_COMMAND_ACTION_IPC_GETINFO = "param";
const QString CommonData::JSON_COMMAND_DATA_IPC_IP = CommonData::JSON_COMMAND_MODULEIPADDR;
const QString CommonData::JSON_COMMAND_DATA_IPC_PORT = CommonData::JSON_COMMAND_MODULEPORT;
const QString CommonData::JSON_COMMAND_DATA_IPC_URL = CommonData::JSON_COMMAND_IPCURL;
const QString CommonData::JSON_COMMAND_DATA_IPC_RTTYPE = "RemoteType";
const QString CommonData::JSON_COMMAND_DATA_P2P_UUID = "uuid";
const QString CommonData::JSON_COMMAND_DATA_P2P_IP = "phoneip";
const QString CommonData::JSON_COMMAND_DATA_IPC_VWIDTH = "VideoWidth";
const QString CommonData::JSON_COMMAND_DATA_IPC_VHEIGHT = "VideoHeight";
const QString CommonData::JSON_COMMAND_DATA_IPC_VCODEC = "CodecType";
const QString CommonData::JSON_COMMAND_DATA_IPC_RECTIME = "RecordTime";
const QString CommonData::JSON_COMMAND_MAINSTREAM = "mainstream";
const QString CommonData::JSON_COMMAND_SUBSTREAM = "substream";
const QString CommonData::JSON_COMMAND_AVAILABLETIME = "availabletime";
const QString CommonData::JSON_COMMAND_DELAYTIME = "delaytime";
const QString CommonData::JSON_COMMAND_STARTTIME = "starttime";
const QString CommonData::JSON_COMMAND_ENDTIME = "endtime";
const QString CommonData::JSON_COMMAND_FREQUENCY = "frequency";
const QString CommonData::JSON_COMMAND_TRIGGERTYPE = "triggertype";
const QString CommonData::JSON_COMMAND_CUSTOMIZEDAYS = "customizedays";
const QString CommonData::JSON_COMMAND_TRIGGERNAME = CommonData::JSON_COMMAND_ALIAS;
const QString CommonData::JSON_COMMAND_TRIGGERDESCRIPTION = CommonData::JSON_COMMAND_DESCRITPION;
const QString CommonData::JSON_COMMAND_TRIGGERCONDITION = CommonData::JSON_COMMAND_CONDITION;
const QString CommonData::JSON_COMMAND_SCHEDULEACTION = "scheduleaction";
const QString CommonData::JSON_COMMAND_TRIGGERACTION = "triggeraction";
const QString CommonData::JSON_COMMAND_TRIGGERID = "triggerid";
const QString CommonData::JSON_COMMAND_SCHEDULEID = "scheduleid";
const QString CommonData::JSON_COMMAND_MUTEXID = "mutexid";

 // upgrade commands
const QString CommonData::JSON_COMMAND_UPGRADE_GETPACK = "getpackage";
const QString CommonData::JSON_COMMAND_UPGRADE_NEWVER = "newversion";
const QString CommonData::JSON_COMMAND_UPGRADE_START = "startupgrade";
const QString CommonData::JSON_COMMAND_UPGRADE_QUERY = "queryupgrade";
const QString CommonData::JSON_COMMAND_UPGRADE_GETVER = "getversion";

 // backup
 //const QString CommonData::JSON_COMMON_DATABASE_FILE = "cubeconfig.db";
const QString CommonData::JSON_COMMAND_BACKUP_RETENTION = "retention";
const QString CommonData::JSON_COMMAND_BACKUP_CREATE = "createbackup";
const QString CommonData::JSON_COMMAND_BACKUP_ID = "dataid";

const QString CommonData::JSON_COMMAND_CONTROLMAP = "controlmap";

const QString CommonData::JSON_COMMAND_PRIMARYID = "primaryid";
const QString CommonData::JSON_COMMAND_RESPONSEPRIMARYID = "responseprimaryid";
const QString CommonData::JSON_COMMAND_SUBRESPONSEPRIMARYID = "subresponseprimaryid";

const QString CommonData::JSON_COMMAND_CURRAIRQUAL_INVALID = "invalid";
const QString CommonData::JSON_COMMAND_CURRAIRQUAL_CLEAN = "clean";
const QString CommonData::JSON_COMMAND_CURRAIRQUAL_SLIGHT = "slight";
const QString CommonData::JSON_COMMAND_CURRAIRQUAL_MODERATE = "moderate";
const QString CommonData::JSON_COMMAND_CURRAIRQUAL_SERIOUS = "serious";

const QString CommonData::JSON_COMMAND_PORTMAP = "portmap";
const QString CommonData::JSON_COMMAND_CUBEDEV_EVENT_TYPE = "eventtype";
const QString CommonData::JSON_COMMAND_DATA_SDCARD_IN = "sdcardin";   //sd
const QString CommonData::JSON_COMMAND_DATA_SDCARD_OUT = "sdcardout";
const QString CommonData::JSON_COMMAND_DATA_SDCARD_ERR = "sdcarderr";
const QString CommonData::JSON_COMMAND_DATA_USBDISK_IN = "usbdiskin"; //usb disk
const QString CommonData::JSON_COMMAND_DATA_USBDISK_OUT = "usbdiskout";
const QString CommonData::JSON_COMMAND_DATA_RECORD_FAIL = "recordfail";  //录像失败，例如无卡/卡损坏
const QString CommonData::JSON_COMMAND_RECORDTIME = "RecordTime";

 /* alarm history specified keys for cloud */
const QString CommonData::ALARM_MESSAGE_SENSORTYPE = "sensorType";
const QString CommonData::ALARM_MESSAGE_ALARMTYPE = "alarmType";
const QString CommonData::ALARM_MESSAGE_ALARMTIMESTAMP = "timeStamp"; // time that alarm happens
const QString CommonData::ALARM_MESSAGE_ALARMMSGID = "messageId";
const QString CommonData::ALARM_MESSAGE_LOOPNAME = "loopName";
const QString CommonData::ALARM_MESSAGE_ROOMNAME = "roomName";
const QString CommonData::ALARM_MESSAGE_MODULEADDR = "moduleAddr";
const QString CommonData::ALARM_MESSAGE_MODULETYPE = "moduleType";
const QString CommonData::ALARM_MESSAGE_LOOPID = "loopId";
 /* frequency */
const QString CommonData::FREQUENCY_SINGLE = "single";
const QString CommonData::FREQUENCY_EVERYDAY = "everyday";
const QString CommonData::FREQUENCY_EVERYWORKDAY = "everyworkday";
const QString CommonData::FREQUENCY_EVERYWEEKEND = "everyweekend";
const QString CommonData::FREQUENCY_CUSTOMIZE = "customize";
const QString CommonData::FREQUENCY_CUSTOMIZE_DAY = "day";
const QString CommonData::FREQUENCY_CUSTOMIZE_SUNDAY = "sunday";
const QString CommonData::FREQUENCY_CUSTOMIZE_MONDAY = "monday";
const QString CommonData::FREQUENCY_CUSTOMIZE_TUESDAY = "tuesday";
const QString CommonData::FREQUENCY_CUSTOMIZE_WEDNESDAY = "wednesday";
const QString CommonData::FREQUENCY_CUSTOMIZE_THURSDAY = "thursday";
const QString CommonData::FREQUENCY_CUSTOMIZE_FRIDAY = "friday";
const QString CommonData::FREQUENCY_CUSTOMIZE_SATURDAY = "saturday";

 /* loop type */
const QString CommonData::LOOP_TYPE_LIGHT = "light";
const QString CommonData::LOOP_TYPE_CURTAIN = "curtain";
const QString CommonData::LOOP_TYPE_RELAY = "relay";
const QString CommonData::LOOP_TYPE_SWITCH = "switch";// maia分light和 switch
const QString CommonData::LOOP_TYPE_SENSOR = "sensor";

 /* 433 type */
const QString CommonData::SENSOR_TYPE_433_INFRADE = "5800-PIR-AP";
const QString CommonData::SENSOR_TYPE_433_KEYFOB = "5816EU";
const QString CommonData::SENSOR_TYPE_433_DOORMAGNETI = "5804EU";

const int CommonData::LOOP_TYPE_LIGHT_INT = 1;
const int CommonData::LOOP_TYPE_CURTAIN_INT = 2;
const int CommonData::LOOP_TYPE_RELAY_INT = 3;
const int CommonData::LOOP_TYPE_SWITCH_INT = 4;
const int CommonData::LOOP_TYPE_SENSOR_INT = 5;
const int CommonData::LOOP_TYPE_5800PIRAP_INT = 6;
const int CommonData::LOOP_TYPE_5804EU_INT = 7;
const int CommonData::LOOP_TYPE_5816EU_INT = 8;

 /* switch status type */
const QString CommonData::SWITCHSTATUS_TYPE_ON = "on";
const QString CommonData::SWITCHSTATUS_TYPE_OFF = "off";
const QString CommonData::SWITCHSTATUS_TYPE_OPEN = "opening";
const QString CommonData::SWITCHSTATUS_TYPE_CLOSE = "closing";
const QString CommonData::SWITCHSTATUS_TYPE_STOP = "stopped";

const QString CommonData::MODE_TYPE_COOL = "cooling";
const QString CommonData::MODE_TYPE_HEAT = "heating";
const QString CommonData::MODE_TYPE_VENLITATION = "ventilation";
const QString CommonData::MODE_TYPE_AUTO = "auto";
const QString CommonData::MODE_TYPE_DEHUMIDIFY = "dehumidifying";

const QString CommonData::AC_FAN_SPPED_LOW = "low";
const QString CommonData::AC_FAN_SPPED_MIDDLE = "middle";
const QString CommonData::AC_FAN_SPPED_HIGH = "high";
const QString CommonData::AC_FAN_SPPED_AUTO = "auto";


 // for wifi module type value(5~10为wifi module)
const int CommonData::MODULE_TYPE_SPARKLIGHTING = 1;
const int CommonData::MODULE_TYPE_BACNET = 2;
const int CommonData::MODULE_TYPE_IPC = 3;
const int CommonData::MODULE_TYPE_WIFIIR = 4;
const int CommonData::MODULE_TYPE_WIFIAIR = 5;
const int CommonData::MODULE_TYPE_WIFIRELAY = 6;
const int CommonData::MODULE_TYPE_WIFI485 = 7;
const int CommonData::MODULE_TYPE_WIREDZONE = 8;
const int CommonData::MODULE_TYPE_WIFI315M433M = 9;
const int CommonData::MODULE_TYPE_BACKAUDIO = 10;
const int CommonData::MODULE_TYPE_ALARMZONE = 11;
const int CommonData::MODULE_TYPE_IPVDP = 12;
const int CommonData::MODULE_TYPE_SCENARIO = 13;
const int CommonData::MODULE_TYPE_SCENARIOTRIGGER = 14;
const int CommonData::MODULE_TYPE_MUTEXRULE = 15;
const int CommonData::MODULE_TYPE_SCHEDULERULE = 16;
const int CommonData::MODULE_TYPE_ROOM = 17;

 /* module type maybe values */
const QString CommonData::JSON_COMMAND_MODULETYPE_485 = "485";
const QString CommonData::JSON_COMMAND_MODULETYPE_BACNET = "bacnet";
const QString CommonData::JSON_COMMAND_MODULETYPE_SPARKLIGHT = "sparklighting";
const QString CommonData::JSON_COMMAND_MODULETYPE_WIREDZONE = "wiredzone";
const QString CommonData::JSON_COMMAND_MODULETYPE_315M433 = "315M433M";
const QString CommonData::JSON_COMMAND_MODULETYPE_IPC = "ipc";
const QString CommonData::JSON_COMMAND_MODULETYPE_IR = "ir";
const QString CommonData::JSON_COMMAND_MODULETYPE_RELAY = "relay";
const QString CommonData::JSON_COMMAND_MODULETYPE_AIR = "air";
const QString CommonData::JSON_COMMAND_MODULETYPE_IPVDP = "ipvdp";
const QString CommonData::JSON_COMMAND_MODULETYPE_NFC = "nfc";
const QString CommonData::JSON_COMMAND_MODULETYPE_BACKAUDIO = "backaudio";
const QString CommonData::JSON_COMMAND_MODULETYPE_CUBE = "cube";
const QString CommonData::JSON_COMMAND_MODULETYPE_DIGITALLOCK = "digitallock";
const QString CommonData::JSON_COMMAND_MODULETYPE_ELEVATOR = "elevator";
const QString CommonData::JSON_COMMAND_MODULETYPE_SCENARIO = "scenario";
const QString CommonData::JSON_COMMAND_MODULETYPE_ALARMZONE = "alarmzone";
const QString CommonData::JSON_COMMAND_MODULETYPE_SCENARIOTRIGGER = "scenariotrigger";
const QString CommonData::JSON_COMMAND_MODULETYPE_MUTEXRULE = "mutexrule";
const QString CommonData::JSON_COMMAND_MODULETYPE_SCHEDULERULE = "schedulerule";
const QString CommonData::JSON_COMMAND_MODULETYPE_ROOM = "room";
const QString CommonData::JSON_COMMAND_MODULETYPE_VENTILATION = "ventilation";
const QString CommonData::JSON_COMMAND_MODULETYPE_COMMON_DEVICE = "commondevice";


 // for all sparklighting sub_dev_type
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSD0403 = "HBLS-D0403";// QString,
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSD0602 = "HBLS-D0602";// QString,
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSD0610DC = "HBLS-D0610-DC";// QString,
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSD0605_LED = "HBLS-D0605-LED";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSC02 = "HBLS-C02";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSR0410 = "HBLS-R0410";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSR0810 = "HBLS-R0810";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSR1210 = "HBLS-R1210";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSI04LED = "HBLS-I04-LED";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSI08 = "HBLS-I08";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSSIR = "HBLS-SIR";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSSTLA = "HBLS-STLA";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSGW = "HBLS-GW";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSP750 = "HBLS-P750";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSP2400 = "HBLS-P2400";
const   QString CommonData::SPARKLIGHT_SUBDEVTYPE_HBLSSoftware = "HBLS-Software";


 // ALARMS from ipvdp system
const QString CommonData::ZONE_ALARM_STATUS_GAS = "gas";
const QString CommonData::ZONE_ALARM_STATUS_FIRE = "fire";
const QString CommonData::ZONE_ALARM_STATUS_HELP = "help";
const QString CommonData::ZONE_ALARM_STATUS_THIEF = "thief";
const QString CommonData::ZONE_ALARM_STATUS_EMERGENCY = "emergency";


const QString CommonData::ZONE_TYPE_SECURITY_INSTANT = "instant";
const QString CommonData::ZONE_TYPE_SECURITY_24HOURS = "24hours";
const QString CommonData::ZONE_TYPE_SECURITY_DELAY = "delay";

const QString CommonData::IPCAMERA_TYPE_PHOENIX = "phoenix";
const QString CommonData::IPCAMERA_TYPE_SUPER_HD = "super hd";

const QString CommonData::WIFI485_AC_TYPE_ECC_O1 = "ecc_o1";
const QString CommonData::WIFI485_AC_TYPE_HTC = "htc961d3200";
const QString CommonData::WIFI485_AC_TYPE_ECC_DT300 = "ecc_dt300";
const QString CommonData::WIFI485_AC_TYPE_SIMENS_RDF302 = "simens_rdf302";

const QString CommonData::WIFI485_AC_TYPE_DAKIN_DTA = "dakin_dta116a621";
const QString CommonData::WIFI485_AC_TYPE_Dakin_R4R5 = "dakin_r4r5";
const QString CommonData::WIFI485_AC_TYPE_TOSHIBA_TCB = "toshiba_tcb-ifmb640tle";
const QString CommonData::WIFI485_AC_TYPE_YORK_YVOH_A = "york_yvoh-a_bas";
const QString CommonData::WIFI485_AC_TYPE_YORK_4_IN_1 = "4in1";
const QString CommonData::WIFI485_AC_TYPE_HUANGPUWAN = "huangpuwan";


const   QString CommonData::DEVICETYPE_MAIA2 = "maia2";
const   QString CommonData::DEVICETYPE_SENSOR = "sensor";
const   QString CommonData::DEVICETYPE_AIRCONDITION = "aircondition";
const   QString CommonData::DEVICETYPE_THERMOSTAT = "thermostat";
const   QString CommonData::DEVICETYPE_VENTILATION = "ventilation";
const   QString CommonData::DEVICETYPE_CURTAIN = "curtain";

const QString CommonData::FIRST_SEPARATOR = "::::";
const QString CommonData::SECOND_SEPARATOR = ",";
const QString CommonData::DAY_SEPARATOR = "|";
const QString CommonData::CONTROLMAP_SEPARATOR = "*";

const   int CommonData::SCENARIO_ID_HOME = 1;
const   int CommonData::SCENARIO_ID_LEAVE = 2;
const   int CommonData::SCENARIO_ID_ARMALL = 3;
const   int CommonData::SCENARIO_ID_DISARMALL = 4;

const   QString CommonData::SCENARIO_HOME_NAME = "回家";
const   QString CommonData::SCENARIO_LEAVE_NAME = "离家";
const   QString CommonData::SCENARIO_ARMALL_NAME = "全部布防";
const   QString CommonData::SCENARIO_DISARMALL_NAME = "全部撤防";

const   QString CommonData::IRLOOPTYPE_DVD = "DVD";
const   QString CommonData::IRLOOPTYPE_TV = "TV";
const   QString CommonData::IRLOOPTYPE_FAN = "FAN";
const   QString CommonData::IRLOOPTYPE_AIR = "AIR";
const   int CommonData::SCENARIO_ID_BASIC = 100;

const   QString CommonData::DEFAULTSECURITYPWD = "1123445";
const   QString CommonData::DEFAULT_DEV_SERIAL_NUMBER = "5555";
const   QString CommonData::DEFAULTIPCUSER = "admin";
const   QString CommonData::DEFAULTIPCPWD = DEFAULTSECURITYPWD;
const   int CommonData::DEFAULTIPCSTREAMPORT = 554;

 /**
  * upgrade info
  */
const   QString CommonData::UPGRADE_RELEASEDATE = "releasedate";
const   QString CommonData::UPGRADE_UPGRADECMD = "upgradecmd";
const   QString CommonData::UPGRADE_DESCRIPTION = "description";
const   QString CommonData::UPGRADE_VERSION = "description";

 /**
  * Scenario 部分，三级页面获取设备列表和Zone列表，用于Event返回数据
  */
const   QString CommonData::SCENARIO_EDIT_GET_DEVICES = "devices";
const   QString CommonData::SCENARIO_EDIT_GET_ZONES = "zones";
