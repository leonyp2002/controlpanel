#ifndef BASICLOOP_H
#define BASICLOOP_H

#include <QObject>
#include "baseqtinclude.h"


//using namespace lce;
class BasicLoop : public QObject
{
    Q_OBJECT
public:
    BasicLoop(QObject *parent = 0);
    QVariantMap getDetailInfoList();
public:
	long mLoopSelfPrimaryId;
	long mModulePrimaryId;
	int mSubDevId;
	QString mLoopName;
	int mRoomId;
	int mLoopId;
	QString mIpAddr;
	QString mMacAddr;
	int mModuleType;
	int mLoopType;
    boolean isOnline;
signals:

public slots:
private:
    QVariantMap var;

};

#endif // BASICLOOP_H
