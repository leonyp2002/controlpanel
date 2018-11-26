#include "utility.h"


Utility::Utility()
{

}


// QString >> QJson

QJsonObject Utility::getJsonObjectFromString(const QString jsonString){

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());

    if( jsonDocument.isNull() ){

        qDebug()<< "===> please check the string "<< jsonString.toLocal8Bit().data();

    }

    QJsonObject jsonObject = jsonDocument.object();

    return jsonObject;

}

// QJson >> QString

QString Utility::getStringFromJsonObject(const QJsonObject& jsonObject){

    return QString(QJsonDocument(jsonObject).toJson());

}
