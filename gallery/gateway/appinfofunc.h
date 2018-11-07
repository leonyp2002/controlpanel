#ifndef APPINFOFUNC_H
#define APPINFOFUNC_H

#include <QObject>
//#include "baseqtinclude.h"
#include "appinfo.h"
class AppInfoFunc : public QObject
{
    Q_OBJECT
public:
    explicit AppInfoFunc(QObject *parent = 0);

    static AppInfo* getCurrentUser();
signals:

public slots:
};

#endif // APPINFOFUNC_H
