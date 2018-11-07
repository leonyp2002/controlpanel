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
