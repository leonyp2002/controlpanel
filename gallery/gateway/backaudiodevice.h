#ifndef BACKAUDIODEVICE_H
#define BACKAUDIODEVICE_H

#include <QObject>

class BackaudioDevice : public QObject
{
    Q_OBJECT
public:
    explicit BackaudioDevice(QObject *parent = 0);

signals:

public slots:
public:
    QString mSerialNumber;
};

#endif // BACKAUDIODEVICE_H
