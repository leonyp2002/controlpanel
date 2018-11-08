#ifndef BACKAUDIOLOOP_H
#define BACKAUDIOLOOP_H

#include <QObject>

class BackaudioLoop : public QObject
{
    Q_OBJECT
public:
    explicit BackaudioLoop(QObject *parent = 0);

signals:

public slots:
public:
    QString mLoopId;
};

#endif // BACKAUDIOLOOP_H
