#include "appinfofunc.h"
#include "preferenceutil.h"
AppInfoFunc::AppInfoFunc(QObject *parent) : QObject(parent)
{

}

/**
 * 获取当前登陆的用户
 */
AppInfo* AppInfoFunc::getCurrentUser(/*Context context*/) {

    const QStringList userInfo = PreferenceUtil::getUserInfo();
    AppInfo *info=new AppInfo();
//    if (!"".equalsIgnoreCase(userInfo[0])) {
//        info = new AppInfoFunc(ConfigCubeDatabaseHelper.getInstance(context)).getAppInfoByUserName(userInfo[0]);
//    }
//    if (info == null) {
//        Loger.print("ssd test", "ssd get current info --- info is null", Thread.currentThread());
//    }
    info->username = userInfo.at(0);
    info->password = userInfo.at(1);
    return info;
}
/**
 * 获取访客
 *
 * @param context
 * @return
 */
//AppInfo* getGuestUser(Context context) {
//        AppInfoFunc func = new AppInfoFunc(ConfigCubeDatabaseHelper.getInstance(context));
//        AppInfo info = func.getAppInfoByUserName(ModelEnum.GuestNum);
//        if (info == null) {
//            AppInfo info1 = new AppInfo();
//            info1.current_scenario_id = 1;
//            info1.username = ModelEnum.GuestNum;
//            info1.version = CommonUtils.getVersion(context);
//            func.addAppInfo(info1);
//            info = info1;
//        }
//        return info;
//    }
