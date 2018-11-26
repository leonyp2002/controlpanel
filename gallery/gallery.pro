TEMPLATE = app
TARGET = gallery
QT += quick sql xml

SOURCES += \
    gallery.cpp \
    gateway/messagemanager.cpp \
    gateway/appinfo.cpp \
    gateway/appinfofunc.cpp \
    gateway/preferenceutil.cpp \
    gateway/backaudiodevice.cpp \
    gateway/backaudioloop.cpp \
    gateway/scenariotriggerinfo.cpp \
    gateway/socketcontroller.cpp \
    gateway/commandqueuemanager.cpp \
    gateway/receiverqueuemanager.cpp \
    gateway/netconstant.cpp \
    gateway/utility.cpp \
    gateway/respondercontroller.cpp \
    gateway/commondata.cpp \
    gateway/configcubedatabasehelper.cpp \
    gateway/basicloop.cpp

OTHER_FILES += \
    gallery.qml

RESOURCES += \
    gallery.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quickcontrols2/gallery
INSTALLS += target

HEADERS += \
    gateway/messagemanager.h \
    gateway/baseqtinclude.h \
    gateway/appinfo.h \
    gateway/appinfofunc.h \
    gateway/preferenceutil.h \
    gateway/backaudiodevice.h \
    gateway/backaudioloop.h \
    gateway/scenariotriggerinfo.h \
    gateway/socketcontroller.h \
    gateway/commandqueuemanager.h \
    gateway/receiverqueuemanager.h \
    gateway/netconstant.h \
    gateway/utility.h \
    gateway/respondercontroller.h \
    gateway/commondata.h \
    gateway/configcubedatabasehelper.h \
    gateway/basicloop.h

DISTFILES += \
    gallery

INCLUDEPATH += \
    gateway \
    gateway/3rdparty
