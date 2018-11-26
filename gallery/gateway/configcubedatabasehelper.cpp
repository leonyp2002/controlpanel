#include "configcubedatabasehelper.h"
#include "commondata.h"
#include "utility.h"

ConfigCubeDatabaseHelper* ConfigCubeDatabaseHelper::m_instance = NULL;

ConfigCubeDatabaseHelper::ConfigCubeDatabaseHelper(QObject *parent) : QObject(parent)
{

}

const QString ConfigCubeDatabaseHelper::TAG = "ConfigCubeDatabaseHelper";

const QString ConfigCubeDatabaseHelper::DB_NAME = CommonData::APPDATABASEFILE;
const int ConfigCubeDatabaseHelper::DB_VERSION = CommonData::APPDATABASEVersion;

const QString ConfigCubeDatabaseHelper::TABLE_CUBE = "cube";//存储
const QString ConfigCubeDatabaseHelper::TABLE_PERIPHERALDEVICE = "peripheraldevice";//主表
const QString ConfigCubeDatabaseHelper::TABLE_SPARKLIGNTINGLOOP = "sparklightingloop";
const QString ConfigCubeDatabaseHelper::TABLE_VENTILATIONLOOP = "ventilationloopmap";
const QString ConfigCubeDatabaseHelper::TABLE_CUBEBASE = "cubebase";
const QString ConfigCubeDatabaseHelper::TABLE_CUBEBASECONFIG = "cubebaseconfig";

const QString ConfigCubeDatabaseHelper::TABLE_RELAYLOOP = "relayloop";
const QString ConfigCubeDatabaseHelper::TABLE_BACNETLOOP = "bacnetloop";
const QString ConfigCubeDatabaseHelper::TABLE_WIRDEDZONELOOP = "wiredzoneloop";
const QString ConfigCubeDatabaseHelper::TABLE_WIRELESS315M433MLOOP = "wireless315M433Mloop";
const QString ConfigCubeDatabaseHelper::TABLE_SCENARIOSETTINGS = "ScenarioSettings";
const QString ConfigCubeDatabaseHelper::TABLE_SCENARIOIDS = "Scenarioids";
const QString ConfigCubeDatabaseHelper::TABLE_IR_INFO = "irinfo";
const QString ConfigCubeDatabaseHelper::TABLE_IR_LOOP = "irloop";
const QString ConfigCubeDatabaseHelper::TABLE_IR_CODE = "ircode";
const QString ConfigCubeDatabaseHelper::TABLE_BACKAUDIO_DEVICE = "backaudiodevice";
const QString ConfigCubeDatabaseHelper::TABLE_BACKAUDIO_LOOP = "backaudioloop";
const QString ConfigCubeDatabaseHelper::TABLE_485_LOOP = "wifi485loop";
const QString ConfigCubeDatabaseHelper::TABLE_IPCSTREAM_INFO = "ipcstreaminfo";
const QString ConfigCubeDatabaseHelper::TABLE_IPVDP_INFO = "ipvdpinfo";
const QString ConfigCubeDatabaseHelper::TABLE_IPVDPZONELOOP = "ipvdpzoneloop";
const QString ConfigCubeDatabaseHelper::TABLE_SCENARIO_TRIGGER = "scenario_trigger";
const QString ConfigCubeDatabaseHelper::TABLE_CONDITION = "condition";
const QString ConfigCubeDatabaseHelper::TABLE_TRIGGER_SCENARIO = "trigger_scenario";
const QString ConfigCubeDatabaseHelper::TABLE_TRIGGER_DEVICE = "trigger_device";
const QString ConfigCubeDatabaseHelper::TABLE_MUTEX_RULE = "mutexrule";
const QString ConfigCubeDatabaseHelper::TABLE_MUTEX_DEVICE_MAP = "mutexdevicemap";
const QString ConfigCubeDatabaseHelper::TABLE_SCHEDULE_RULE = "schedule_rule";
const QString ConfigCubeDatabaseHelper::TABLE_SCHEDULE_SCENARIO = "schedule_scenario";
const QString ConfigCubeDatabaseHelper::TABLE_SCHEDULE_DEVICE = "schedule_device";
const QString ConfigCubeDatabaseHelper::TABLE_ROOM = "room";
const QString ConfigCubeDatabaseHelper::TABLE_ENVIRONMENT = "environment";
const QString ConfigCubeDatabaseHelper::TABLE_APPINFO = "appinfo";

const QString ConfigCubeDatabaseHelper::TABLE_COMMON_DEVICE = "commondeviceloopmap";

const QString ConfigCubeDatabaseHelper::TABLE_NAMES[] = {ConfigCubeDatabaseHelper::TABLE_CUBE,
                                                                          ConfigCubeDatabaseHelper::TABLE_PERIPHERALDEVICE,
                                                                          ConfigCubeDatabaseHelper::TABLE_SPARKLIGNTINGLOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_VENTILATIONLOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_CUBEBASE,
                                                                          ConfigCubeDatabaseHelper::TABLE_RELAYLOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_BACNETLOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_WIRDEDZONELOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_WIRELESS315M433MLOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_SCENARIOSETTINGS,
                                                                          ConfigCubeDatabaseHelper::TABLE_SCENARIOIDS,
                                                                          ConfigCubeDatabaseHelper::TABLE_IR_INFO,
                                                                          ConfigCubeDatabaseHelper::TABLE_IR_LOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_IR_CODE,
                                                                          ConfigCubeDatabaseHelper::TABLE_BACKAUDIO_DEVICE,
                                                                          ConfigCubeDatabaseHelper::TABLE_BACKAUDIO_LOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_485_LOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_IPCSTREAM_INFO,
                                                                          ConfigCubeDatabaseHelper::TABLE_IPVDP_INFO,
                                                                          ConfigCubeDatabaseHelper::TABLE_IPVDPZONELOOP,
                                                                          ConfigCubeDatabaseHelper::TABLE_SCENARIO_TRIGGER,
                                                                          ConfigCubeDatabaseHelper::TABLE_CONDITION,
                                                                          ConfigCubeDatabaseHelper::TABLE_TRIGGER_SCENARIO,
                                                                          ConfigCubeDatabaseHelper::TABLE_TRIGGER_DEVICE,
                                                                          ConfigCubeDatabaseHelper::TABLE_MUTEX_RULE,
                                                                          ConfigCubeDatabaseHelper::TABLE_MUTEX_DEVICE_MAP,
                                                                          ConfigCubeDatabaseHelper::TABLE_SCHEDULE_RULE,
                                                                          ConfigCubeDatabaseHelper::TABLE_SCHEDULE_SCENARIO,
                                                                          ConfigCubeDatabaseHelper::TABLE_SCHEDULE_DEVICE,
                                                                          ConfigCubeDatabaseHelper::TABLE_ROOM,
                                                                          ConfigCubeDatabaseHelper::TABLE_ENVIRONMENT,
                                                                          ConfigCubeDatabaseHelper::TABLE_APPINFO,
                                                                          ConfigCubeDatabaseHelper::TABLE_CUBEBASECONFIG,
                                                                          ConfigCubeDatabaseHelper::TABLE_COMMON_DEVICE};

//ALTER TABLE peripheraldevice ADD laichao varchar(128) default "0abc"
//for basic column
const QString ConfigCubeDatabaseHelper::COLUMN_ID = "_id";//integer
const QString ConfigCubeDatabaseHelper::COLUMN_DEVICEID = "dev_id";//int,主外键，和peripheraldevice的id一致,根据外部传入的ip_addr和mac_addr，虽然不存储 。
const QString ConfigCubeDatabaseHelper::COLUMN_LOOPNAME = "loop_name";//str
const QString ConfigCubeDatabaseHelper::COLUMN_ROOM_ID = "room_id";//int
const QString ConfigCubeDatabaseHelper::COLUMN_ROOMNAME = "room_name";//str
const QString ConfigCubeDatabaseHelper::COLUMN_LOOPID = "loop_id";//int
const QString ConfigCubeDatabaseHelper::COLUMN_IS_ENABLE = "is_enable";//int
const QString ConfigCubeDatabaseHelper::COLUMN_LOOPTYPE = "loop_type";//byte
const QString ConfigCubeDatabaseHelper::COLUMN_ZONETYPE = "zone_type";//zonetype,string
const QString ConfigCubeDatabaseHelper::COLUMN_ALARMTYPE = "alarm_type";//alarmtype,string
const QString ConfigCubeDatabaseHelper::COLUMN_ALARMTIMER = "alarm_timer";//alarmtimer,int

const QString ConfigCubeDatabaseHelper::COLUMN_PRIMARYID = "primaryid";//alarmtimer,int
const QString ConfigCubeDatabaseHelper::COLUMN_MODULETYPE = "moduletype";//alarmtimer,int

//colume for cube -- CUBE表
const QString ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEID = "deviceid";//设备Id
const QString ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICE_SERIAL = "deviceSerial";//SerialNum
const QString ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_SERIALNUMBER = "serialnumber";//设备信息-serialNum
const QString ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_FIRMWAREVERSION = "firmwareversion";//设备信息-firmwareversion
const QString ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_APPLICATIONVERSION = "applicationversion";//设备信息-application version
const QString ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_MACADDRESS = "macaddress";//设备信息-mac address
const QString ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_ALIASNAME = "aliasname";//设备信息-别名


//colume for peripheraldevice－－小模块主表
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_PRIMARYID = "primaryid";//映射子表
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_TYPE = "type";//int,
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_NAME = "name";//str
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_IP = "ip_addr";//str
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_MAC = "mac_addr";//str
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_PORT = "port";//str
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_ISCONFIG = "isconfig";//int
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_ISONLINE = "isonline";//int
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_BACNETID = "bacnetid";//int
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_BRANDNAME = "brandname";
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_MASKID = "mask_id";//byte
const QString ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_VERSION = "version";//byte

//colume for ventilation
const QString ConfigCubeDatabaseHelper::COLUMN_VENTILATION_CONTROLTYPE = "controltype";
const QString ConfigCubeDatabaseHelper::COLUMN_VENTILATION_POWER = "power";
const QString ConfigCubeDatabaseHelper::COLUMN_VENTILATION_FANSPEED = "fanspeed";
const QString ConfigCubeDatabaseHelper::COLUMN_VENTILATION_CYCLETYPE = "cycletype";
const QString ConfigCubeDatabaseHelper::COLUMN_VENTILATION_HUMIDITY = "humidity";
const QString ConfigCubeDatabaseHelper::COLUMN_VENTILATION_DEHUMIDITY = "dehumidity";

//colume for sparkinglightingloop
const QString ConfigCubeDatabaseHelper::COLUMN_SPARKLIGNTINGLOOP_SUBDEVICEID = "sub_dev_id";//byte
const QString ConfigCubeDatabaseHelper::COLUMN_SPARKLIGNTINGLOOP_SUBDEVTYPE = "sub_dev_type";//str

//colume for cubebase
const QString ConfigCubeDatabaseHelper::COLUMN_CUBEBASE_CONFIGNAME = "conf_name";
const QString ConfigCubeDatabaseHelper::COLUMN_CUBEBASE_CONFIGVALUE = "conf_value";


//colume for relayloop
const QString ConfigCubeDatabaseHelper::COLUMN_REALYLOOP_TRIGGERTIME = "trigger_time";//trigger_time,int

//colume for bacnetloop
const QString ConfigCubeDatabaseHelper::COLUMN_BACNET_SUBGATEWAYID = "sub_gateway_id";//sub_gateway_id int

//colume for wireless315M433Mloop
const QString ConfigCubeDatabaseHelper::COLUMN_WIREDLESS315433SERIALNO = "serial_number";//sn,str
const QString ConfigCubeDatabaseHelper::COLUMN_WIREDLESS315433DEVICEID = "device_id";//device_id,int
const QString ConfigCubeDatabaseHelper::COLUMN_WIREDLESS315433DEVICETYPE = "device_type";//device_type,str

//column for scenario settings
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIO_ID = "scenario_id";//scenario_id
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIO_NAME = "scenario_name";//scenario_name
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIO_ACTIONINFO = "actioninfo";//
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIO_IS_ARM = "isarm";//
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIO_IMAGENAME = "imagename";//
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIO_MODULETYPE = "moduletype";//
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIO_CLICKCOUNT = "clickcount";//点击次数
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIO_UUID = "uuid";//uuid

//ir info(和 peripheral 平级的)
const QString ConfigCubeDatabaseHelper::COLUMN_IR_INFO_TYPE = "ir_type";//str
const QString ConfigCubeDatabaseHelper::COLUMN_IR_INFO_NAME = "ir_name";//str
const QString ConfigCubeDatabaseHelper::COLUMN_IR_INFO_LOCK = "ir_lock";//int
const QString ConfigCubeDatabaseHelper::COLUMN_IR_INFO_PASSWORD = "ir_pwd";//String（本身是long，太长了，用str 替代）
const QString ConfigCubeDatabaseHelper::COLUMN_IR_INFO_ID = "ir_id";//int
const QString ConfigCubeDatabaseHelper::COLUMN_IR_INFO_SUBDEV = "ir_sub_dev";//int
const QString ConfigCubeDatabaseHelper::COLUMN_IR_INFO_KEY = "ir_key";//scenario_name

//ir loop
const QString ConfigCubeDatabaseHelper::COLUMN_IR_LOOP_TYPE = "looptype";//str

//ir code
const QString ConfigCubeDatabaseHelper::COLUMN_IR_CODE_LOOPID = "ir_loop_id";//int
const QString ConfigCubeDatabaseHelper::COLUMN_IR_CODE_NAME = "name";//str
const QString ConfigCubeDatabaseHelper::COLUMN_IR_CODE_IMAGENAME = "imagename";//str
const QString ConfigCubeDatabaseHelper::COLUMN_IR_CODE_DATA1 = "data1";//str
const QString ConfigCubeDatabaseHelper::COLUMN_IR_CODE_DATA2 = "data2";//str

//backAudio device(没有外围设备表)
const QString ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_SERIALNUMBER = "serialnumber";//str
const QString ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_NAME = "name";//str
const QString ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_MACHINETYPE = "machinetype";//str
const QString ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_LOOPNUMBER = "loopnumber";//int
const QString ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_ISONLINE = "isonline";//int

//485 loop
const QString ConfigCubeDatabaseHelper::COLUMN_485_BRANDNAME = "brandname";
const QString ConfigCubeDatabaseHelper::COLUMN_485_PORTID = "portid";
const QString ConfigCubeDatabaseHelper::COLUMN_485_SLAVEADDR = "slaveaddr";

//ipc_stream info (和 peripheral 平级的)
const QString ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_TYPE = "type";//str
const QString ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_MAIN_STREAM = "main_stream";//str
const QString ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_SUB_STREAM = "sub_stream";//str
const QString ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_STREAM_PORT = "stream_port";//int
const QString ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_USER = "user";//str
const QString ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_PASSWORD = "password";//str

//ipvdp info
const QString ConfigCubeDatabaseHelper::COLUMN_IPVDP_INFO_DEVICEID = "deviceid";
const QString ConfigCubeDatabaseHelper::COLUMN_IPVDP_INFO_HNSSERVERADDR = "hnsserveraddr";

//scenario trigger field
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_SWITCHSTATUS = "switchstatus";
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_DELAYTIME = "delaytime";
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_AVAIBLETIME = "avaibletime";
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_TYPE = "type";
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_NAME = "name";
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_DESCRIPTION = "description";

/*condition is another table*/
const QString ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_SCENARIOACTION = "scenarionaction";
/*device action is anothetr table*/

//trigger condition table field
const QString ConfigCubeDatabaseHelper::COLUMN_CONDITION_PRIMARYID = "conditionprimaryid";
const QString ConfigCubeDatabaseHelper::COLUMN_CONDITION_TRIGGERID = "triggerid";
const QString ConfigCubeDatabaseHelper::COLUMN_CONDITION_ACTIONINFO = "actioninfo";

//trigger scenario table field
const QString ConfigCubeDatabaseHelper::COLUMN_TRIGGERSCNARIO_TRIGGERID = ConfigCubeDatabaseHelper::COLUMN_CONDITION_TRIGGERID;
const QString ConfigCubeDatabaseHelper::COLUMN_TRIGGERSCNARIO_ACTIONINFO = ConfigCubeDatabaseHelper::COLUMN_CONDITION_ACTIONINFO;


//trigger device control table field
const QString ConfigCubeDatabaseHelper::COLUMN_TRIGGERDEVICE_PRIMARYID = "triggerdeviceprimaryid";
const QString ConfigCubeDatabaseHelper::COLUMN_TRIGGERDEVICE_TRIGGERID = ConfigCubeDatabaseHelper::COLUMN_CONDITION_TRIGGERID;
const QString ConfigCubeDatabaseHelper::COLUMN_TRIGGERDEVICE_ACTIONINFO = ConfigCubeDatabaseHelper::COLUMN_CONDITION_ACTIONINFO;
const QString ConfigCubeDatabaseHelper::COLUMN_TRIGGERDEVICE_UUID = "uuid";

//mutex rule table field
    //scenario trigger field
const QString ConfigCubeDatabaseHelper::COLUMN_MUTEXRULE_SWITCHSTATUS = "switchstatus";
const QString ConfigCubeDatabaseHelper::COLUMN_MUTEXRULE_NAME = "name";
const QString ConfigCubeDatabaseHelper::COLUMN_MUTEXRULE_DESCRIPTION = "description";
    /*mutexmap is another table*/

    //mutex device map table field
const QString ConfigCubeDatabaseHelper::COLUMN_MUTEXDEVICEMAP_MUTEXID = "mutexid";

//mutex device map table field  QString ConfigCubeDatabaseHelper::COLUMN_MUTEXDEVICEMAP_MUTEXID = "mutexid";
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULERULE_SWITCHSTATUS = "switchstatus";
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULERULE_AVAIBLETIME = "avaibletime";
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULERULE_NAME = "name";
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULERULE_DESCRIPTION = "description";
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULERULE_SCENARIOACTION = "scenarionaction";
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULESCENARIO_RULEID = "schedulerule_id";
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULESCENARIO_ACTIONINFO = "actioninfo";
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULEDEVICE_ID = "scheduledeviceid";
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULEDEVICE_RULEID = ConfigCubeDatabaseHelper::COLUMN_SCHEDULESCENARIO_RULEID;
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULEDEVICE_ACTIONINFO = ConfigCubeDatabaseHelper::COLUMN_SCHEDULESCENARIO_ACTIONINFO;
const QString ConfigCubeDatabaseHelper::COLUMN_SCHEDULEDEVICE_UUID = "uuid";
const QString ConfigCubeDatabaseHelper::COLUMN_ROOM_IMAGENAME = ConfigCubeDatabaseHelper::COLUMN_IR_CODE_IMAGENAME;
const QString ConfigCubeDatabaseHelper::COLUMN_ENVIRONMENT_ROOMID = "roomid";
const QString ConfigCubeDatabaseHelper::COLUMN_ENVIRONMENT_SUBGATEWAYID = ConfigCubeDatabaseHelper::COLUMN_BACNET_SUBGATEWAYID;
const QString ConfigCubeDatabaseHelper::COLUMN_ENVIRONMENT_PARAMTYPE = "paramtype";


//app info
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_DEVICETOKEN = "deviceToken";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_VERSION = "version";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_DATABASE_VERSION = "databaseversion";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_PHONE_PREFIX = "phone_prefix";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_USERNAME = "username";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_PASSWORD = "password";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_NICKNAME = "nickname";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_PHONEID = "phoneid";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_DEVICEID = "deviceid";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_USER_IMAGE_PATH = "user_image_path";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CURRENT_SCENARIO_ID = "current_scenario_id";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_LOCATION = "location";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_IP = "cube_ip";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_MAC = "cube_mac";

const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_PORT = "cube_port";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_LOCAL_NICKNAME = "cube_local_nickname";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_LOCAL_ID = "cube_local_id";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_LOCAL_PASSWORD = "cube_local_password";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_ALL_HEADER_FIELDS_COOKIE = "all_header_fields_cookie";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_ROUTER_SSID_PASSWORD = "router_ssid_password";

//后加的
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CURRENT_SECURITY_STATUS = "current_security_status";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_VOICE_RECOGNIZE = "cube_voice_recognize";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_VERSION = "cube_version";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_LAST_READ_TIME = "last_read_time";
const QString ConfigCubeDatabaseHelper::COLUMN_APPINFO_ONLINE = "online";

//Common device表
const QString ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_MODULE_UUID = "moduleuuid";
const QString ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_IMAGENAME = "imagename";
const QString ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_DEVICETYPE = "devicetype";
const QString ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_ROOMID = "roomid";
const QString ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_LOOP_NAME = "loop_name";
const QString ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_UUID = "uuid";
const QString ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_COMMONNAME = "commonname";

const QString ConfigCubeDatabaseHelper::cubebase_confignames[] = {
        "CUBE_ID", "CUBE_PWD", "WIFI_SSID", "WIFI_PWD",
        "WIFI_ENC_TYPE", "WIFI_IP", "WIFI_MASK", "WIFI_GW",
        "LAN_IP", "LAN_MASK", "LAN_GW", "DNS_SERVER1",
        "DNS_SERVER2", "HNS_SERVER_IP", "CLOUD_SERV1", "NICK_NAME",
        "BACNET_ID", "CONFIG_VER"};
const QString ConfigCubeDatabaseHelper::cubebase_configvalues[] = {"88888888", "222222", "homesystem", "123456",
        "WEP2", "192.168.0.100", "255.255.255.0", "192.168.0.254",
        "172.16.1.100", "255.255.0.0", "172.16.1.254", "8.8.8.8",
        "6.6.6.6", "172.16.1.2", "https://www.", "My Cube",
        "123", "0"};
const QString ConfigCubeDatabaseHelper::default_roomname[] = {"Master Bedroom", "Second Bedroom", "Guest Bedroom", "Kitchen",
        "Dining Room", "Living Room", "Master Bathroom", "Second Bathroom"};


//single instance Java Mode


void ConfigCubeDatabaseHelper::onCreate(QSqlDatabase db) {

    // createPeripheralDeviceTable
    QString sql = createPeripheralDeviceTable();
    db.exec(sql);

    //create cube table
    sql = createCubeTable();
    db.exec(sql);

    // createSparkLightingLoopTable
    sql = createSparkLightingLoopTable();
    db.exec(sql);

    // createVentilationLoopTable
    sql = createVentilationLoopTable();
    db.exec(sql);

    //这个表不一定有用 后面需要验证
    //create Cubebase table
    sql = createCubebaseTable();
    db.exec(sql);
    //should insert init record
//        initCubebaseTableRecord(db);

    //create cubebase configuration
    sql = createCubebaseConfigTable();
    db.exec(sql);

    // create RelayLoop Table
    sql = createRelayLoopTable();
    db.exec(sql);

    //createBacnetLoopTable
    sql = createBacnetLoopTable();
    db.exec(sql);

    //create WiredZone Loop Table
    sql = createWirdzoneLoopTable();
    db.exec(sql);

    //create wired 315M 433M looptable
    sql = createWireless315m433mLoopTable();
    db.exec(sql);

    //create Scenario Settings Table
    sql = createScenarioSettingsTable();
    db.exec(sql);

    //create Scenario IO ids Tables
    sql = createScenarioIdsTable();
    db.exec(sql);
    initScenarioSettingNormalTableRecord(&db);


    // create Ir Info Table
    sql = createIrInfoTable();
    db.exec(sql);

    //create Ir Loop Table
    sql = createIrLoopTable();
    db.exec(sql);

    //create Ir Code Table
    sql = createIrCodeTable();
    db.exec(sql);

    //create back audio device table
    sql = createBackaudioDeviceTable();
    db.exec(sql);

    //create back audio loop table
    sql = createBackaudioLoopTable();
    db.exec(sql);

    //create 485 loop table
    sql = create485LoopTable();
    db.exec(sql);

    //create ipc stream info table
    sql = createIpcStreamInfoTable();
    db.exec(sql);

    //create ipvdp info Table
    sql = createIpvdpInfoTable();
    db.exec(sql);

    //create ipvdp zone loop table
    sql = createIpvdpZoneLoopTable();
    db.exec(sql);

    //create scenario trigger table
    sql = createScenarioTriggerTable();
    db.exec(sql);

    //create condition table
    sql = createConditionTable();
    db.exec(sql);

    //create trigger scenario table
    sql = createTriggerScenarioTable();
    db.exec(sql);

    //create trigger device table
    sql = createTriggerDeviceTable();
    db.exec(sql);

    //ios中没有下面2个表 待验证
    //create mutex rule table-－－MutexRule  MutexDevice
    sql = createMutexRuleTable();
    db.exec(sql);

    //create mutex device map table
    sql = createMutexDeviceMapTable();
    db.exec(sql);

    //create schedule rule table
    sql = createScheduleRuleTable();
    db.exec(sql);

    //create schedule scenario table
    sql = createScheduleScenarioTable();
    db.exec(sql);

    //create schedule device table
    sql = createScheduleDeviceTable();
    db.exec(sql);


    //create environment table

    sql = createEnvironmentTable();
    db.exec(sql);

    //App info
    sql = createAppInfoTable();
    db.exec(sql);

    //room
    sql = createRoomTable();
    db.exec(sql);

    //common device
    sql = createCommonDeviceTable();
    db.exec(sql);

    //初始化Scenario
//        initScenarioSettingNormalTableRecord(db);

}

void ConfigCubeDatabaseHelper::onUpgrade(QSqlDatabase db, int oldVersion, int newVersion) {

}

//清空所有表的内容
void ConfigCubeDatabaseHelper::clearTable() {
    //QSqlDatabase db = this.getWritableDatabase();
    QSqlDatabase *db = thisDatabase;
    //cube
    clearTableWithName(TABLE_CUBE, db);

    //cube base config
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_CUBEBASECONFIG, db);

    //backAudio
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_BACKAUDIO_DEVICE, db);

    //backAudioLoop
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_BACKAUDIO_LOOP, db);

    //Periphera
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_PERIPHERALDEVICE, db);

    //SparkLighting
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_SPARKLIGNTINGLOOP, db);

    //ventilation
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_VENTILATIONLOOP, db);

    //WIFi relay
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_RELAYLOOP, db);

    //ipvdp zone
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_IPVDPZONELOOP, db);

    //wired zone
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_WIRDEDZONELOOP, db);

    //315_433M
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_WIRELESS315M433MLOOP, db);

    //Ip camera
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_IPCSTREAM_INFO, db);

    //bacnet
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_BACNETLOOP, db);

    //485
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_485_LOOP, db);

    //IR info
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_IR_INFO, db);

    //IR Loop
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_IR_LOOP, db);

    //IR Code
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_IR_CODE, db);

    //scenario setting
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_SCENARIOSETTINGS, db);

    //schedule
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_SCHEDULE_RULE, db);

    //schedule scenario
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_SCHEDULE_SCENARIO, db);

    //schedule devices
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_SCHEDULE_DEVICE, db);

    //rule
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_SCENARIO_TRIGGER, db);

    //rule condition
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_CONDITION, db);

    //rule action scenario
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_TRIGGER_SCENARIO, db);

    //rule device
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_TRIGGER_DEVICE, db);

    //room
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_ROOM, db);

    //common device
    clearTableWithName(ConfigCubeDatabaseHelper::TABLE_COMMON_DEVICE, db);

    initScenarioSettingNormalTableRecord(db);
}


void ConfigCubeDatabaseHelper::clearTableWithName(QString tableName, QSqlDatabase *db) {

    QString sql = "delete from " + tableName + " where 1=1";
    //Loger.print(TAG, sql, Thread.currentThread());
    db->exec(sql);
}

QString ConfigCubeDatabaseHelper::createCubeTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_CUBE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEID + " INTEGER, "//device id
            + ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICE_SERIAL + " nvarchar(128), " // device serial
            + ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_SERIALNUMBER + " nvarchar(128), " // info - serial number
            + ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_FIRMWAREVERSION + " nvarchar(128), " // info - firmware version
            + ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_APPLICATIONVERSION + " nvarchar(128), " // Application version
            + ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_MACADDRESS + " nvarchar(128), " // Mac 地址
            + ConfigCubeDatabaseHelper::COLUMN_CUBE_DEVICEINFO_ALIASNAME + " nvarchar(128) " // 别名
            + ") ";
}


QString ConfigCubeDatabaseHelper::createPeripheralDeviceTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_PERIPHERALDEVICE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_PRIMARYID + " INTEGER, "//primary Id
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_TYPE + " INTEGER, " // type
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_NAME + " nvarchar(128), " // name
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_IP + " nvarchar(128), " // ip_addr
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_MAC + " nvarchar(128), " // mac_addr
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_PORT + " INTEGER, " // port
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_ISCONFIG + " INTEGER, " // isConfig
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_ISONLINE + " INTEGER, " // isOnline
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_BACNETID + " INTEGER, " // brandid
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_BRANDNAME + " nvarchar(128), " // brandname
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_MASKID + " INTEGER, " // maskid
            + ConfigCubeDatabaseHelper::COLUMN_PERIPHERALDEVICE_VERSION + " nvarchar(128)" // version
            + ") ";
}

QString ConfigCubeDatabaseHelper::createSparkLightingLoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_SPARKLIGNTINGLOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, " //primary id
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " // dev_id
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), " // loop_name
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER, " // room_name
            + ConfigCubeDatabaseHelper::COLUMN_SPARKLIGNTINGLOOP_SUBDEVICEID + " INTEGER, " // sub_dev_id
            + ConfigCubeDatabaseHelper::COLUMN_SPARKLIGNTINGLOOP_SUBDEVTYPE + " nvarchar(128), " // sub_dev_type
            + ConfigCubeDatabaseHelper::COLUMN_LOOPTYPE + " INTEGER, " // loop_type
            + ConfigCubeDatabaseHelper::COLUMN_LOOPID + " INTEGER, " // loop_id
            + ConfigCubeDatabaseHelper::COLUMN_IS_ENABLE + " INTEGER" //is_enable
            + ") ";
}

QString ConfigCubeDatabaseHelper::createVentilationLoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_VENTILATIONLOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, " //primary id
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), " // loop_name
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER, " // room_name
            + ConfigCubeDatabaseHelper::COLUMN_VENTILATION_CONTROLTYPE + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_VENTILATION_POWER + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_VENTILATION_FANSPEED + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_VENTILATION_CYCLETYPE + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_VENTILATION_HUMIDITY + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_VENTILATION_DEHUMIDITY + " nvarchar(128)"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createCubebaseTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_CUBEBASE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_CUBEBASE_CONFIGNAME + " nvarchar(128), " // conf_name
            + ConfigCubeDatabaseHelper::COLUMN_CUBEBASE_CONFIGVALUE + " nvarchar(128)" // conf_value
            + ") ";
}

QString ConfigCubeDatabaseHelper::createCubebaseConfigTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_CUBEBASECONFIG + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, " //primary id
            + ConfigCubeDatabaseHelper::COLUMN_CUBEBASE_CONFIGNAME + " nvarchar(128), " // conf_name
            + ConfigCubeDatabaseHelper::COLUMN_CUBEBASE_CONFIGVALUE + " nvarchar(128)" // conf_value
            + ") ";
}

//  void initCubebaseTableRecord(SQLiteDatabase db) {
//        db.beginTransaction();//开始事务
//        try {
//            for (int i = 0; i < cubebase_confignames.length; i++) {
//                ContentValues values = new ContentValuesFactory()
//                        .put(ConfigCubeDatabaseHelper::COLUMN_CUBEBASE_CONFIGNAME, cubebase_confignames[i])
//                        .put(ConfigCubeDatabaseHelper.ConfigCubeDatabaseHelper::COLUMN_CUBEBASE_CONFIGVALUE, cubebase_configvalues[i]).getValues();
//                db.insert(ConfigCubeDatabaseHelper.ConfigCubeDatabaseHelper::TABLE_CUBEBASE, null, values);
//            }
//            db.setTransactionSuccessful();//由事务的标志决定是提交事务，还是回滚事务
//        } catch (Exception e) {
//            Loger.print(TAG, "ssd:initCubebaseTableRecord()--exception" + e.toQString(), Thread.currentThread());
//            e.printStackTrace();
//        }ly {
//            db.endTransaction();//由事务的标志决定是提交事务，还是回滚事务
//        }
//    }


QString ConfigCubeDatabaseHelper::createRelayLoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_RELAYLOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " // dev_id
            + ConfigCubeDatabaseHelper::COLUMN_LOOPID + " INTEGER, " //relay_id
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), " // loop_name
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_REALYLOOP_TRIGGERTIME + " INTEGER" // trigger_time
            + ") ";
}

QString ConfigCubeDatabaseHelper::createBacnetLoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_BACNETLOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " // dev_id
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), " // loop_name
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_LOOPID + " INTEGER, " // loop_id
            + ConfigCubeDatabaseHelper::COLUMN_BACNET_SUBGATEWAYID + " INTEGER" // subgateway_id
            + ") ";
}

QString ConfigCubeDatabaseHelper::createWirdzoneLoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_WIRDEDZONELOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " // dev_id
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), " // loop_name
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_LOOPID + " INTEGER, " // loop_id
            + ConfigCubeDatabaseHelper::COLUMN_ZONETYPE + " nvarchar(128), " // zonetype
            + ConfigCubeDatabaseHelper::COLUMN_ALARMTYPE + " nvarchar(128), " // alarmtype
            + ConfigCubeDatabaseHelper::COLUMN_ALARMTIMER + " INTEGER, " // alarmtimer
            + ConfigCubeDatabaseHelper::COLUMN_IS_ENABLE + " INTEGER" // isenable()
            + ") ";
}

QString ConfigCubeDatabaseHelper::createWireless315m433mLoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_WIRELESS315M433MLOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " // dev_id
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), " // loop_name
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_LOOPID + " INTEGER, " // loop_id
            + ConfigCubeDatabaseHelper::COLUMN_ZONETYPE + " nvarchar(128), " // zonetype
            + ConfigCubeDatabaseHelper::COLUMN_ALARMTYPE + " nvarchar(128), " // alarmtype
            + ConfigCubeDatabaseHelper::COLUMN_ALARMTIMER + " INTEGER, " // alarmtimer
            + ConfigCubeDatabaseHelper::COLUMN_IS_ENABLE + " INTEGER, " // isenable()
            + ConfigCubeDatabaseHelper::COLUMN_WIREDLESS315433DEVICEID + " INTEGER, " // deviceid
            + ConfigCubeDatabaseHelper::COLUMN_WIREDLESS315433SERIALNO + " nvarchar(128), " // serialnumber
            + ConfigCubeDatabaseHelper::COLUMN_WIREDLESS315433DEVICETYPE + " nvarchar(128), " // devicetype
            + ConfigCubeDatabaseHelper::COLUMN_LOOPTYPE + " INTEGER" // looptype
            + ") ";
}

QString ConfigCubeDatabaseHelper::createScenarioSettingsTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_SCENARIOSETTINGS + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_ID + " INTEGER, " // scenario_id
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_NAME + " nvarchar(128), " // scenario_name
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_MODULETYPE + " INTEGER, " // moduletype
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " // dev_id,   device loop的primaryid
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_ACTIONINFO + " nvarchar(1024), " // action
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_IS_ARM + " INTEGER, " // isarm
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_IMAGENAME + " nvarchar(128), " // action
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_CLICKCOUNT + " INTEGER, " // click count
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_UUID + " nvarchar(128)" // action
            + ") ";
}

QString ConfigCubeDatabaseHelper::createScenarioIdsTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_SCENARIOIDS + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_ID + " INTEGER, " // scenario_id
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_NAME + " nvarchar(128), " // scenario_name
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIO_IMAGENAME + " nvarchar(128)" // imagename
            + ") ";
}

void ConfigCubeDatabaseHelper::initScenarioSettingNormalTableRecord(QSqlDatabase *db) {
//    //db.beginTransaction();//开始事务

//    //try {
//        for (int i = CommonData::SCENARIO_ID_HOME; i <= CommonData::SCENARIO_ID_DISARMALL; i++) {
////            ContentValues values = new ContentValuesFactory()
////                    .put(ConfigCubeDatabaseHelper::COLUMN_SCENARIO_ID, i)
////                    .put(ConfigCubeDatabaseHelper::COLUMN_SCENARIO_NAME, Util.getScenarioNameByScenarioId(i))
////                    .put(ConfigCubeDatabaseHelper::COLUMN_SCENARIO_IMAGENAME, "").getValues();
//            QHash<QString,QVariant> values;
//            values.insert(COLUMN_SCENARIO_ID,i);
//            values.insert(COLUMN_SCENARIO_NAME,Utility::)
//            db.insert(ConfigCubeDatabaseHelper.ConfigCubeDatabaseHelper::TABLE_SCENARIOSETTINGS, null, values);
//        }
//        db.setTransactionSuccessful();//由事务的标志决定是提交事务，还是回滚事务
//    // } catch (Exception e) {
//    //     e.printStackTrace();
//    // }ly {
//    //     db.endTransaction();//由事务的标志决定是提交事务，还是回滚事务
//    // }
}

QString ConfigCubeDatabaseHelper::createIrInfoTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_IR_INFO + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_IR_INFO_TYPE + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_IR_INFO_NAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_IR_INFO_LOCK + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_IR_INFO_PASSWORD + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_IR_INFO_ID + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_IR_INFO_SUBDEV + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_IR_INFO_KEY + " nvarchar(128)"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createIrLoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_IR_LOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_IR_LOOP_TYPE + " nvarchar(128)" //
            + ") ";
}

QString ConfigCubeDatabaseHelper::createIrCodeTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_IR_CODE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_IR_CODE_LOOPID + " INTEGER, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_IR_CODE_NAME + " nvarchar(128), " //
            + ConfigCubeDatabaseHelper::COLUMN_IR_CODE_IMAGENAME + " nvarchar(128), " //
            + ConfigCubeDatabaseHelper::COLUMN_IR_CODE_DATA1 + " nvarchar(1024), "
            + ConfigCubeDatabaseHelper::COLUMN_IR_CODE_DATA2 + " nvarchar(1024)"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createBackaudioDeviceTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_BACKAUDIO_DEVICE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_SERIALNUMBER + " nvarchar(10), "
            + ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_NAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_MACHINETYPE + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_LOOPNUMBER + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_BACKAUDIO_DEVICE_ISONLINE + " INTEGER"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createBackaudioLoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_BACKAUDIO_LOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_LOOPID + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER"
            + ") ";
}

QString ConfigCubeDatabaseHelper::create485LoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_485_LOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_485_BRANDNAME + " nvarchar(32), " //
            + ConfigCubeDatabaseHelper::COLUMN_485_PORTID + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_LOOPID + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_LOOPTYPE + " nvarchar(32), " //
            + ConfigCubeDatabaseHelper::COLUMN_485_SLAVEADDR + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createIpcStreamInfoTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_IPCSTREAM_INFO + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_TYPE + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_MAIN_STREAM + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_SUB_STREAM + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_STREAM_PORT + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_USER + " nvarchar(32), "
            + ConfigCubeDatabaseHelper::COLUMN_IPCSTREAN_INFO_PASSWORD + " nvarchar(32), "
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createIpvdpInfoTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_IPVDP_INFO + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_IPVDP_INFO_DEVICEID + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_IPVDP_INFO_HNSSERVERADDR + " nvarchar(16)"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createIpvdpZoneLoopTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_IPVDPZONELOOP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_DEVICEID + " INTEGER, " // dev_id
            + ConfigCubeDatabaseHelper::COLUMN_LOOPNAME + " nvarchar(128), " // loop_name
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_ID + " INTEGER, " // room_name
            + ConfigCubeDatabaseHelper::COLUMN_LOOPID + " INTEGER, " // loop_id
            + ConfigCubeDatabaseHelper::COLUMN_ZONETYPE + " nvarchar(128), " // zonetype
            + ConfigCubeDatabaseHelper::COLUMN_ALARMTYPE + " nvarchar(128), " // alarmtype
            + ConfigCubeDatabaseHelper::COLUMN_ALARMTIMER + " INTEGER, " // alarmtimer
            + ConfigCubeDatabaseHelper::COLUMN_IS_ENABLE + " INTEGER" // isenable()
            + ") ";
}

QString ConfigCubeDatabaseHelper::createScenarioTriggerTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_SCENARIO_TRIGGER + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_SWITCHSTATUS + " nvarchar(32), "
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_DELAYTIME + " INTEGER, " //
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_AVAIBLETIME + " nvarchar(256), "
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_TYPE + " nvarchar(64), "
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_NAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_SCENARIOTRIGGER_DESCRIPTION + " nvarchar(128)"
            + ") ";
}


QString ConfigCubeDatabaseHelper::createConditionTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_CONDITION + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_CONDITION_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_CONDITION_TRIGGERID + " INTEGER, " // triggerid
            + ConfigCubeDatabaseHelper::COLUMN_CONDITION_ACTIONINFO + " nvarchar(1024), "
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, " // primaryid
            + ConfigCubeDatabaseHelper::COLUMN_MODULETYPE + " INTEGER" // moduletype
            + ") ";
}


QString ConfigCubeDatabaseHelper::createTriggerScenarioTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_TRIGGER_SCENARIO + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_TRIGGERSCNARIO_TRIGGERID + " INTEGER, " // triggerid
            + ConfigCubeDatabaseHelper::COLUMN_TRIGGERSCNARIO_ACTIONINFO + " nvarchar(1024)"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createTriggerDeviceTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_TRIGGER_DEVICE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_TRIGGERDEVICE_PRIMARYID + " INTEGER, " // triggerid
            + ConfigCubeDatabaseHelper::COLUMN_TRIGGERDEVICE_TRIGGERID + " INTEGER, " // triggerid
            + ConfigCubeDatabaseHelper::COLUMN_TRIGGERDEVICE_ACTIONINFO + " nvarchar(1024), "
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULEDEVICE_UUID + " nvarchar(128), " // uuid
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, " // primaryid
            + ConfigCubeDatabaseHelper::COLUMN_MODULETYPE + " INTEGER" // moduletype
            + ") ";
}

QString ConfigCubeDatabaseHelper::createMutexRuleTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_MUTEX_RULE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_MUTEXRULE_SWITCHSTATUS + " nvarchar(32), "
            + ConfigCubeDatabaseHelper::COLUMN_MUTEXRULE_NAME + " nvarchar(64), "
            + ConfigCubeDatabaseHelper::COLUMN_MUTEXRULE_DESCRIPTION + " nvarchar(128)"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createMutexDeviceMapTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_MUTEX_DEVICE_MAP + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_MUTEXDEVICEMAP_MUTEXID + " INTEGER, " // mutexid
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, " // primaryid
            + ConfigCubeDatabaseHelper::COLUMN_MODULETYPE + " INTEGER" // moduletype
            + ") ";
}

QString ConfigCubeDatabaseHelper::createScheduleRuleTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_SCHEDULE_RULE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULERULE_SWITCHSTATUS + " nvarchar(32), "
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULERULE_AVAIBLETIME + " nvarchar(512), "
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULERULE_NAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULERULE_DESCRIPTION + " nvarchar(128)"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createScheduleScenarioTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_SCHEDULE_SCENARIO + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULESCENARIO_RULEID + " INTEGER, " // triggerid
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULESCENARIO_ACTIONINFO + " nvarchar(1024)"
            + ") ";
}

QString ConfigCubeDatabaseHelper::createScheduleDeviceTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_SCHEDULE_DEVICE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULEDEVICE_ID + " INTEGER, " // triggerid
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULEDEVICE_RULEID + " INTEGER, " // triggerid
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULEDEVICE_ACTIONINFO + " nvarchar(1024), "
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, " // primaryid
            + ConfigCubeDatabaseHelper::COLUMN_SCHEDULEDEVICE_UUID + " nvarchar(128), " // uuid
            + ConfigCubeDatabaseHelper::COLUMN_MODULETYPE + " INTEGER" // moduletype
            + ") ";
}

QString ConfigCubeDatabaseHelper::createRoomTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_ROOM + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_ROOMNAME + " nvarchar(128), " // roomname
            + ConfigCubeDatabaseHelper::COLUMN_ROOM_IMAGENAME + " nvarchar(128)"//imagename
            + ") ";
}

//创建 common device 表
QString ConfigCubeDatabaseHelper::createCommonDeviceTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_COMMON_DEVICE + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_PRIMARYID + " INTEGER, "//primaryId
            + ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_MODULE_UUID + " nvarchar(128), " // module uuid
            + ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_IMAGENAME + " nvarchar(128), "//imagename
            + ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_DEVICETYPE + " nvarchar(128), " // device type
            + ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_ROOMID + " INTEGER, " // room id
            + ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_LOOP_NAME + " nvarchar(128), " // loop name
            + ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_COMMONNAME + " nvarchar(128), " // loop name
            + ConfigCubeDatabaseHelper::COLUMN_COMMONDEVICE_UUID + " nvarchar(128)" // uuid
            + ") ";
}

void ConfigCubeDatabaseHelper::initRoomTableRecord(QSqlDatabase db) {
//    db.beginTransaction();//开始事务
//    try {
//        for (int i = 0; i < default_roomname.length; i++) {
//            ContentValues values = new ContentValuesFactory()
//                    .put(ConfigCubeDatabaseHelper::COLUMN_ROOMNAME, default_roomname[i])
//                    .put(ConfigCubeDatabaseHelper::COLUMN_ROOM_IMAGENAME, default_roomname[i].replace(" ", "_").toLowerCase()).getValues();
//            db.insert(ConfigCubeDatabaseHelper.ConfigCubeDatabaseHelper::TABLE_ROOM, null, values);
//        }
//        db.setTransactionSuccessful();//由事务的标志决定是提交事务，还是回滚事务
//    } catch (Exception e) {
//        e.printStackTrace();
//    }ly {
//        db.endTransaction();//由事务的标志决定是提交事务，还是回滚事务
//    }
}

QString ConfigCubeDatabaseHelper::createEnvironmentTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_ENVIRONMENT + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_ENVIRONMENT_ROOMID + " INTEGER, " // triggerid
            + ConfigCubeDatabaseHelper::COLUMN_MODULETYPE + " INTEGER, "//moduletype
            + ConfigCubeDatabaseHelper::COLUMN_ENVIRONMENT_SUBGATEWAYID + " INTEGER, " // loopid
            + ConfigCubeDatabaseHelper::COLUMN_LOOPID + " INTEGER, " // loopid
            + ConfigCubeDatabaseHelper::COLUMN_ENVIRONMENT_PARAMTYPE + " nvarchar(128)" // paramtype
            + ") ";
}

QString ConfigCubeDatabaseHelper::createAppInfoTable() {
    return "CREATE TABLE IF NOT EXISTS " + ConfigCubeDatabaseHelper::TABLE_APPINFO + "("
            + ConfigCubeDatabaseHelper::COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " // _id
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_DEVICETOKEN + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_VERSION + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_DATABASE_VERSION + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_LOCATION + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_PHONE_PREFIX + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_USERNAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_PASSWORD + " nvarchar(128),"
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_NICKNAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_PHONEID + " INTEGER,"
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_DEVICEID + " INTEGER,"
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_USER_IMAGE_PATH + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CURRENT_SCENARIO_ID + " INTEGER,"
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_IP + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_MAC + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_PORT + " INTEGER,"
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_LOCAL_NICKNAME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_LOCAL_ID + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_LOCAL_PASSWORD + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_ALL_HEADER_FIELDS_COOKIE + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_ROUTER_SSID_PASSWORD + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CURRENT_SECURITY_STATUS + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_VOICE_RECOGNIZE + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_ONLINE + " INTEGER, "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_LAST_READ_TIME + " nvarchar(128), "
            + ConfigCubeDatabaseHelper::COLUMN_APPINFO_CUBE_VERSION + " nvarchar(128)"
            + ") ";
}
QString ConfigCubeDatabaseHelper::insertWithOnConflict(QString table, QString nullColumnHack,
                                          QHash<QString,QVariant> initialValues) {

    //QStringBuilder sql = new QStringBuilder();
    //QStringBuilder sql2 = new QStringBuilder();
    QString sql;
//    sql.append("INSERT");
//    sql.append(" INTO ");
//    sql.append(table);
//    sql.append(" ( ");

//    //Object[] bindArgs = null;
//    QVariantList bindArgs;
//    bindArgs.clear();
//    int size = (initialValues.size() > 0)
//            ? initialValues.size() : 0;
//    if (size > 0) {
//        //bindArgs = new Object[size];
//        int i = 0;
//        for (QString colName : initialValues.keys()) {
//            sql.append((i > 0) ? "," : "");
//            sql.append(colName);
//            sql2.append((i > 0) ? ("," + initialValues.get(colName)) : "" + initialValues.get(colName));
//            bindArgs[i++] = initialValues.get(colName);
//        }
//        sql.append(" ) ");
//        sql.append(" VALUES ( ");
//        sql.append(sql2.toQString());
////                for (i = 0; i < size; i++) {
////                    sql.append((i > 0) ? ",?" : "?");
////                }
//    } else {
//        sql.append(nullColumnHack + " ) VALUES (NULL");
//    }
//    sql.append(" );");
    return sql;
}

void ConfigCubeDatabaseHelper::addLoopToDefaultScenario(ConfigCubeDatabaseHelper dbHelper,BasicLoop basicLoop,boolean isZone) {
//       if(null == dbHelper || null == basicLoop){
//           return;
//       }
//       ScenarioLoopFunc fuc = new ScenarioLoopFunc(dbHelper);
//       ScenarioLoop loop = null;
//       List<ScenarioLoop> loops = new ArrayList<ScenarioLoop>();
//		for(int scenaridId = CommonData.SCENARIO_ID_HOME;scenaridId <= CommonData.SCENARIO_ID_DISARMALL;scenaridId++){
//       for(int scenaridId = CommonData.SCENARIO_ID_ARMALL;scenaridId <= CommonData.SCENARIO_ID_DISARMALL;scenaridId++){
//           //非防区不加到armall 和disarmall 模式
//           if(!isZone && (scenaridId == CommonData.SCENARIO_ID_ARMALL||scenaridId == CommonData.SCENARIO_ID_DISARMALL)){
//               continue;
//           }
//           loop = fillDefaultLoop(basicLoop);
//           if(scenaridId == CommonData.SCENARIO_ID_ARMALL){
//               loop.mIsArm = CommonData.ARM_TYPE_ENABLE;
//           }
//           if(null != loop){
//               loop.mScenarioId = scenaridId;
//               loop.mScenarioName = getScenarioNameByScenarioId(scenaridId);
//               loops.add(loop);
//           }
//       }
//       if(loop != null && !loops.isEmpty()){
//           fuc.addScenarioLoopList(loops,false);
//       }
   }
