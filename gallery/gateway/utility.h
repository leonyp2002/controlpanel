#ifndef UTILITY_H
#define UTILITY_H
#include "baseqtinclude.h"

class Utility
{
public:
    Utility();
    static QJsonObject getJsonObjectFromString(const QString jsonString);
    static QString getStringFromJsonObject(const QJsonObject& jsonObject);
};

#endif // UTILITY_H
