#ifndef PREFERENCEUTIL_H
#define PREFERENCEUTIL_H

#include <QObject>
#include "baseqtinclude.h"
class PreferenceUtil : public QObject
{
    Q_OBJECT
public:
    explicit PreferenceUtil(QObject *parent = 0);
    static PreferenceUtil* getInstance()
    {
        if(!m_instance)
        {
            m_instance = new PreferenceUtil();
        }
        return m_instance;
    }
    static QStringList getUserInfo();
signals:

public slots:
private:
    static PreferenceUtil* m_instance;
};

#endif // PREFERENCEUTIL_H
