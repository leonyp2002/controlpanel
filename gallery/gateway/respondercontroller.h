#ifndef RESPONDERCONTROLLER_H
#define RESPONDERCONTROLLER_H

#include <QObject>
#include "baseqtinclude.h"

class ResponderController : public QObject
{
    Q_OBJECT
public:
    explicit ResponderController(QObject *parent = 0);
    static ResponderController* getInstance()
    {
        if(!m_instance)
        {
            m_instance = new ResponderController;
        }
        return m_instance;
    }
    void dealNetData(QJsonObject object);
    void dealWithWebSocketResponce(QString jsonStr);
    static QString getTAG();

signals:

public slots:
private:
    static ResponderController* m_instance;
    const static QString TAG;
};

#endif // RESPONDERCONTROLLER_H
