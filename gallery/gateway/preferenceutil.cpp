#include "preferenceutil.h"
PreferenceUtil* PreferenceUtil::m_instance = NULL;

PreferenceUtil::PreferenceUtil(QObject *parent) : QObject(parent)
{

}

QStringList PreferenceUtil::getUserInfo(/*Context context*/) {
    //SharedPreferences sp = context.getSharedPreferences("cube_login", Context.MODE_PRIVATE);
    QSettings sp;

    QStringList result;
//    result. = sp.getString("username", "");
//    result[1] = sp.getString("password", "");
    result.append(sp.value("username").toString());
    result.append(sp.value("password").toString());
    return result;
}
