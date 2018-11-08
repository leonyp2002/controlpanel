#ifndef SCENARIOTRIGGERINFO_H
#define SCENARIOTRIGGERINFO_H

#include <QObject>

class ScenarioTriggerInfo : public QObject
{
    Q_OBJECT
public:
    explicit ScenarioTriggerInfo(QObject *parent = 0);

signals:

public slots:
public:
    int mPrimaryId;
};

#endif // SCENARIOTRIGGERINFO_H
