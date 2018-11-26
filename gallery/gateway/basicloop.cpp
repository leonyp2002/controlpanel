#include "basicloop.h"

BasicLoop::BasicLoop(QObject *parent) : QObject(parent)
{
      mLoopSelfPrimaryId = -1;//loop self primaryid
      mModulePrimaryId = -1;//perialdevice primaryid
      mSubDevId = -1;//只有sparklighting，wireless315M433M用到
      mLoopName = "";
      mRoomId = 0;
      mLoopId = -1;
      mIpAddr = "";
      mMacAddr = "";
      mModuleType = -1;
      mLoopType = -1;//str，区分灯光，窗帘，5804EU/5816EU/5800-PIR-AP

      isOnline = false;

      var.insert("_id",QVariant::fromValue(mLoopSelfPrimaryId));
      var.insert("dev_id",QVariant::fromValue(mModulePrimaryId));
      var.insert("sub_dev_id",QVariant::fromValue(mSubDevId));
      var.insert("loop_name",QVariant::fromValue(mLoopName));
      var.insert("room_name",QVariant::fromValue(mRoomId));
      var.insert("loop_id",QVariant::fromValue(mLoopId));
      var.insert("ip",QVariant::fromValue(mIpAddr));
      var.insert("mac",QVariant::fromValue(mMacAddr));
      var.insert("module_type",QVariant::fromValue(mModuleType));
      var.insert("loop_type",QVariant::fromValue(mLoopType));


}

QVariantMap BasicLoop::getDetailInfoList()
{
    return var;
}

//}
