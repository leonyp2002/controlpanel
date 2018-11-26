#ifndef CONFIGCUBEDATABASEHELPER_H
#define CONFIGCUBEDATABASEHELPER_H

#include <QObject>
#include "baseqtinclude.h"
#include "basicloop.h"
class ConfigCubeDatabaseHelper : public QObject
{
    Q_OBJECT
public:
    QString createCommonDeviceTable();
    QString createRoomTable();
    QString createScheduleDeviceTable();
    QString createScheduleScenarioTable();
    QString createScheduleRuleTable();
    QString createMutexDeviceMapTable();
    QString createMutexRuleTable();
    QString createTriggerDeviceTable();
    QString createTriggerScenarioTable();
    QString createConditionTable();
    QString createScenarioTriggerTable();
    QString createIpvdpZoneLoopTable();
    QString createIpvdpInfoTable();
    QString createIpcStreamInfoTable();
    QString create485LoopTable();
    QString createBackaudioLoopTable();
    QString createBackaudioDeviceTable();
    QString createIrCodeTable();
    QString createIrLoopTable();
    QString createIrInfoTable();
    QString createScenarioIdsTable();
    QString createScenarioSettingsTable();
    QString createWireless315m433mLoopTable();
    QString createWirdzoneLoopTable();
    QString createBacnetLoopTable();
    QString createRelayLoopTable();
    QString createCubebaseConfigTable();
    QString createCubebaseTable();
    QString createSparkLightingLoopTable();
    QString createPeripheralDeviceTable();
    QString createCubeTable();
    void clearTableWithName(QString tableName, QSqlDatabase *db);
public:
    explicit ConfigCubeDatabaseHelper(QObject *parent=0);
    static ConfigCubeDatabaseHelper* getInstance()
    {
        if(!m_instance)
        {
            m_instance = new ConfigCubeDatabaseHelper();
        }
        return m_instance;
    }

    QString insertWithOnConflict(QString table, QString nullColumnHack, QHash<QString, QVariant> initialValues);
    QString createAppInfoTable();
    QString createEnvironmentTable();
    void initRoomTableRecord(QSqlDatabase db);
    void initScenarioSettingNormalTableRecord(QSqlDatabase *db);
    void clearTable();
    void onUpgrade(QSqlDatabase db, int oldVersion, int newVersion);
    void onCreate(QSqlDatabase db);
    void addLoopToDefaultScenario(ConfigCubeDatabaseHelper dbHelper, BasicLoop basicLoop, bool isZone);
signals:

public slots:
private:
    static ConfigCubeDatabaseHelper* m_instance;
    QSqlDatabase *thisDatabase;

     static const QString TAG ;

     const static QString DB_NAME ;
     const static int DB_VERSION ;

    //Table_name
     static const QString TABLE_CUBE ;//存储
     static const QString TABLE_PERIPHERALDEVICE ;//主表
     static const QString TABLE_SPARKLIGNTINGLOOP ;
     static const QString TABLE_VENTILATIONLOOP ;
     static const QString TABLE_CUBEBASE ;
     static const QString TABLE_CUBEBASECONFIG ;

     static const QString TABLE_RELAYLOOP ;
     static const QString TABLE_BACNETLOOP ;
     static const QString TABLE_WIRDEDZONELOOP ;
     static const QString TABLE_WIRELESS315M433MLOOP ;
     static const QString TABLE_SCENARIOSETTINGS ;
     static const QString TABLE_SCENARIOIDS ;

     static const QString TABLE_IR_INFO ;
     static const QString TABLE_IR_LOOP ;
     static const QString TABLE_IR_CODE ;

     static const QString TABLE_BACKAUDIO_DEVICE ;
     static const QString TABLE_BACKAUDIO_LOOP ;

     static const QString TABLE_485_LOOP ;

     static const QString TABLE_IPCSTREAM_INFO ;

     static const QString TABLE_IPVDP_INFO ;
     static const QString TABLE_IPVDPZONELOOP ;

     static const QString TABLE_SCENARIO_TRIGGER ;
     static const QString TABLE_CONDITION ;
     static const QString TABLE_TRIGGER_SCENARIO ;
     static const QString TABLE_TRIGGER_DEVICE ;

     static const QString TABLE_MUTEX_RULE ;
     static const QString TABLE_MUTEX_DEVICE_MAP ;

     static const QString TABLE_SCHEDULE_RULE ;
     static const QString TABLE_SCHEDULE_SCENARIO ;
     static const QString TABLE_SCHEDULE_DEVICE ;
     static const QString TABLE_ROOM ;
     static const QString TABLE_ENVIRONMENT ;
     static const QString TABLE_APPINFO ;

    //common 表
     static const QString TABLE_COMMON_DEVICE ;
#define MAX_TABLE 34
     static const QString TABLE_NAMES[MAX_TABLE];

    //ALTER TABLE peripheraldevice ADD laichao varchar(128) default "0abc"
    //for basic column
     const static QString COLUMN_ID ;//integer
     const static QString COLUMN_DEVICEID ;//int,主外键，和peripheraldevice的id一致,根据外部传入的ip_addr和mac_addr，虽然不存储 。
     const static QString COLUMN_LOOPNAME ;//str
     const static QString COLUMN_ROOM_ID ;//int
     const static QString COLUMN_ROOMNAME ;//str
     const static QString COLUMN_LOOPID ;//int
     const static QString COLUMN_IS_ENABLE ;//int
     const static QString COLUMN_LOOPTYPE ;//byte
     const static QString COLUMN_ZONETYPE ;//zonetype,QString
     const static QString COLUMN_ALARMTYPE ;//alarmtype,QString
     const static QString COLUMN_ALARMTIMER ;//alarmtimer,int

     const static QString COLUMN_PRIMARYID ;//alarmtimer,int
     const static QString COLUMN_MODULETYPE ;//alarmtimer,int

    //colume for cube -- CUBE表
     const static QString COLUMN_CUBE_DEVICEID ;//设备Id
     const static QString COLUMN_CUBE_DEVICE_SERIAL ;//SerialNum
     const static QString COLUMN_CUBE_DEVICEINFO_SERIALNUMBER ;//设备信息-serialNum
     const static QString COLUMN_CUBE_DEVICEINFO_FIRMWAREVERSION ;//设备信息-firmwareversion
     const static QString COLUMN_CUBE_DEVICEINFO_APPLICATIONVERSION ;//设备信息-application version
     const static QString COLUMN_CUBE_DEVICEINFO_MACADDRESS ;//设备信息-mac address
     const static QString COLUMN_CUBE_DEVICEINFO_ALIASNAME ;//设备信息-别名


    //colume for peripheraldevice－－小模块主表
     const static QString COLUMN_PERIPHERALDEVICE_PRIMARYID ;//映射子表
     const static QString COLUMN_PERIPHERALDEVICE_TYPE ;//int,
     const static QString COLUMN_PERIPHERALDEVICE_NAME ;//str
     const static QString COLUMN_PERIPHERALDEVICE_IP ;//str
     const static QString COLUMN_PERIPHERALDEVICE_MAC ;//str
     const static QString COLUMN_PERIPHERALDEVICE_PORT ;//str
     const static QString COLUMN_PERIPHERALDEVICE_ISCONFIG ;//int
     const static QString COLUMN_PERIPHERALDEVICE_ISONLINE ;//int
     const static QString COLUMN_PERIPHERALDEVICE_BACNETID ;//int
     const static QString COLUMN_PERIPHERALDEVICE_BRANDNAME ;
     const static QString COLUMN_PERIPHERALDEVICE_MASKID ;//byte
     const static QString COLUMN_PERIPHERALDEVICE_VERSION ;//byte

    //colume for ventilation
     const static QString COLUMN_VENTILATION_CONTROLTYPE ;
     const static QString COLUMN_VENTILATION_POWER ;
     const static QString COLUMN_VENTILATION_FANSPEED ;
     const static QString COLUMN_VENTILATION_CYCLETYPE ;
     const static QString COLUMN_VENTILATION_HUMIDITY ;
     const static QString COLUMN_VENTILATION_DEHUMIDITY ;

    //colume for sparkinglightingloop
     const static QString COLUMN_SPARKLIGNTINGLOOP_SUBDEVICEID ;//byte
     const static QString COLUMN_SPARKLIGNTINGLOOP_SUBDEVTYPE ;//str

    //colume for cubebase
     const static QString COLUMN_CUBEBASE_CONFIGNAME ;
     const static QString COLUMN_CUBEBASE_CONFIGVALUE ;


    //colume for relayloop
     const static QString COLUMN_REALYLOOP_TRIGGERTIME ;//trigger_time,int

    //colume for bacnetloop
     const static QString COLUMN_BACNET_SUBGATEWAYID ;//sub_gateway_id int

    //colume for wireless315M433Mloop
     const static QString COLUMN_WIREDLESS315433SERIALNO ;//sn,str
     const static QString COLUMN_WIREDLESS315433DEVICEID ;//device_id,int
     const static QString COLUMN_WIREDLESS315433DEVICETYPE ;//device_type,str

    //column for scenario settings
     const static QString COLUMN_SCENARIO_ID ;//scenario_id
     const static QString COLUMN_SCENARIO_NAME ;//scenario_name
     const static QString COLUMN_SCENARIO_ACTIONINFO ;//
     const static QString COLUMN_SCENARIO_IS_ARM ;//
     const static QString COLUMN_SCENARIO_IMAGENAME ;//
     const static QString COLUMN_SCENARIO_MODULETYPE ;//
     const static QString COLUMN_SCENARIO_CLICKCOUNT ;//点击次数
     const static QString COLUMN_SCENARIO_UUID ;//uuid

    //ir info(和 peripheral 平级的)
     const static QString COLUMN_IR_INFO_TYPE ;//str
     const static QString COLUMN_IR_INFO_NAME ;//str
     const static QString COLUMN_IR_INFO_LOCK ;//int
     const static QString COLUMN_IR_INFO_PASSWORD ;//QString（本身是long，太长了，用str 替代）
     const static QString COLUMN_IR_INFO_ID ;//int
     const static QString COLUMN_IR_INFO_SUBDEV ;//int
     const static QString COLUMN_IR_INFO_KEY ;//scenario_name

    //ir loop
     const static QString COLUMN_IR_LOOP_TYPE ;//str

    //ir code
     const static QString COLUMN_IR_CODE_LOOPID ;//int
     const static QString COLUMN_IR_CODE_NAME ;//str
     const static QString COLUMN_IR_CODE_IMAGENAME ;//str
     const static QString COLUMN_IR_CODE_DATA1 ;//str
     const static QString COLUMN_IR_CODE_DATA2 ;//str

    //backAudio device(没有外围设备表)
     const static QString COLUMN_BACKAUDIO_DEVICE_SERIALNUMBER ;//str
     const static QString COLUMN_BACKAUDIO_DEVICE_NAME ;//str
     const static QString COLUMN_BACKAUDIO_DEVICE_MACHINETYPE ;//str
     const static QString COLUMN_BACKAUDIO_DEVICE_LOOPNUMBER ;//int
     const static QString COLUMN_BACKAUDIO_DEVICE_ISONLINE ;//int

    //485 loop
     const static QString COLUMN_485_BRANDNAME ;
     const static QString COLUMN_485_PORTID ;
     const static QString COLUMN_485_SLAVEADDR ;

    //ipc_stream info (和 peripheral 平级的)
     const static QString COLUMN_IPCSTREAN_INFO_TYPE ;//str
     const static QString COLUMN_IPCSTREAN_INFO_MAIN_STREAM ;//str
     const static QString COLUMN_IPCSTREAN_INFO_SUB_STREAM ;//str
     const static QString COLUMN_IPCSTREAN_INFO_STREAM_PORT ;//int
     const static QString COLUMN_IPCSTREAN_INFO_USER ;//str
     const static QString COLUMN_IPCSTREAN_INFO_PASSWORD ;//str

    //ipvdp info
     const static QString COLUMN_IPVDP_INFO_DEVICEID ;
     const static QString COLUMN_IPVDP_INFO_HNSSERVERADDR ;

    //scenario trigger field
     const static QString COLUMN_SCENARIOTRIGGER_SWITCHSTATUS ;
     const static QString COLUMN_SCENARIOTRIGGER_DELAYTIME ;
     const static QString COLUMN_SCENARIOTRIGGER_AVAIBLETIME ;
     const static QString COLUMN_SCENARIOTRIGGER_TYPE ;
     const static QString COLUMN_SCENARIOTRIGGER_NAME ;
     const static QString COLUMN_SCENARIOTRIGGER_DESCRIPTION ;

    /*condition is another table*/
     const static QString COLUMN_SCENARIOTRIGGER_SCENARIOACTION ;
    /*device action is anothetr table*/

    //trigger condition table field
     const static QString COLUMN_CONDITION_PRIMARYID ;
     const static QString COLUMN_CONDITION_TRIGGERID ;
     const static QString COLUMN_CONDITION_ACTIONINFO ;

    //trigger scenario table field
     const static QString COLUMN_TRIGGERSCNARIO_TRIGGERID ;
     const static QString COLUMN_TRIGGERSCNARIO_ACTIONINFO ;


    //trigger device control table field
     const static QString COLUMN_TRIGGERDEVICE_PRIMARYID ;
     const static QString COLUMN_TRIGGERDEVICE_TRIGGERID ;
     const static QString COLUMN_TRIGGERDEVICE_ACTIONINFO ;
     const static QString COLUMN_TRIGGERDEVICE_UUID ;


    //mutex rule table field
    //scenario trigger field
     const static QString COLUMN_MUTEXRULE_SWITCHSTATUS ;
     const static QString COLUMN_MUTEXRULE_NAME ;
     const static QString COLUMN_MUTEXRULE_DESCRIPTION ;
    /*mutexmap is another table*/

    //mutex device map table field
     const static QString COLUMN_MUTEXDEVICEMAP_MUTEXID ;

     const static QString COLUMN_SCHEDULERULE_SWITCHSTATUS ;
     const static QString COLUMN_SCHEDULERULE_AVAIBLETIME ;
     const static QString COLUMN_SCHEDULERULE_NAME ;
     const static QString COLUMN_SCHEDULERULE_DESCRIPTION ;
     const static QString COLUMN_SCHEDULERULE_SCENARIOACTION ;

     const static QString COLUMN_SCHEDULESCENARIO_RULEID ;
     const static QString COLUMN_SCHEDULESCENARIO_ACTIONINFO ;

     const static QString COLUMN_SCHEDULEDEVICE_ID ;
     const static QString COLUMN_SCHEDULEDEVICE_RULEID ;
     const static QString COLUMN_SCHEDULEDEVICE_ACTIONINFO ;
     const static QString COLUMN_SCHEDULEDEVICE_UUID ;

     const static QString COLUMN_ROOM_IMAGENAME ;
     const static QString COLUMN_ENVIRONMENT_ROOMID ;
     const static QString COLUMN_ENVIRONMENT_SUBGATEWAYID ;
     const static QString COLUMN_ENVIRONMENT_PARAMTYPE ;


    //app info
     const static QString COLUMN_APPINFO_DEVICETOKEN ;
     const static QString COLUMN_APPINFO_VERSION ;
     const static QString COLUMN_APPINFO_DATABASE_VERSION ;
     const static QString COLUMN_APPINFO_PHONE_PREFIX ;
     const static QString COLUMN_APPINFO_USERNAME ;
     const static QString COLUMN_APPINFO_PASSWORD ;
     const static QString COLUMN_APPINFO_NICKNAME ;
     const static QString COLUMN_APPINFO_PHONEID ;
     const static QString COLUMN_APPINFO_DEVICEID ;
     const static QString COLUMN_APPINFO_USER_IMAGE_PATH ;
     const static QString COLUMN_APPINFO_CURRENT_SCENARIO_ID ;
     const static QString COLUMN_APPINFO_CUBE_LOCATION ;
     const static QString COLUMN_APPINFO_CUBE_IP ;
     const static QString COLUMN_APPINFO_CUBE_MAC ;

     const static QString COLUMN_APPINFO_CUBE_PORT ;
     const static QString COLUMN_APPINFO_CUBE_LOCAL_NICKNAME ;
     const static QString COLUMN_APPINFO_CUBE_LOCAL_ID ;
     const static QString COLUMN_APPINFO_CUBE_LOCAL_PASSWORD ;
     const static QString COLUMN_APPINFO_ALL_HEADER_FIELDS_COOKIE ;
     const static QString COLUMN_APPINFO_ROUTER_SSID_PASSWORD ;
    //后加的
     const static QString COLUMN_APPINFO_CURRENT_SECURITY_STATUS ;
     const static QString COLUMN_APPINFO_CUBE_VOICE_RECOGNIZE ;
     const static QString COLUMN_APPINFO_CUBE_VERSION ;
     const static QString COLUMN_APPINFO_LAST_READ_TIME ;
     const static QString COLUMN_APPINFO_ONLINE ;

    //Common device表
     const static QString COLUMN_COMMONDEVICE_MODULE_UUID ;
     const static QString COLUMN_COMMONDEVICE_IMAGENAME ;
     const static QString COLUMN_COMMONDEVICE_DEVICETYPE ;
     const static QString COLUMN_COMMONDEVICE_ROOMID ;
     const static QString COLUMN_COMMONDEVICE_LOOP_NAME ;
     const static QString COLUMN_COMMONDEVICE_UUID ;
     const static QString COLUMN_COMMONDEVICE_COMMONNAME ;


#define MAX_CONFIG_NAMES 18
     static const QString cubebase_confignames[MAX_CONFIG_NAMES];
#define MAX_CONFIG_VALUES 18
     static const QString cubebase_configvalues[MAX_CONFIG_VALUES];
#define MAX_DEFAULE_ROOMS 8
     static const QString default_roomname[MAX_DEFAULE_ROOMS];


     void clearTableWithName(QString tableName, QSqlDatabase db);
    // method

     QString createVentilationLoopTable();
};

#endif // CONFIGCUBEDATABASEHELPER_H
