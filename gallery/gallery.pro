TEMPLATE = app
TARGET = gallery
QT += quick

SOURCES += \
    gallery.cpp \
    gateway/messagemanager.cpp \
    gateway/appinfo.cpp \
    gateway/appinfofunc.cpp \
    gateway/preferenceutil.cpp \
    gateway/backaudiodevice.cpp \
    gateway/backaudioloop.cpp \
    gateway/scenariotriggerinfo.cpp

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
    gateway/scenariotriggerinfo.h
