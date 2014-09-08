#-------------------------------------------------
#
# Project created by QtCreator 2014-07-07T15:19:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MixerOSX
TEMPLATE = app


SOURCES += main.cpp\
    mixer.cpp \
    volumelevel.cpp \
    volslider.cpp \
    usb_mixer.cpp \
    controller.cpp \
    volumelevelintermixer.cpp \
    interface.cpp \
    mixer_main.cpp \
    qfingerscrollarea.cpp \
    channelbox.cpp \
    outputbox.cpp \
    masterslider.cpp

HEADERS  += \
    mixer.h \
    volumelevel.h \
    volslider.h \
    usb_mixer.h \
    controller.h \
    volumelevelintermixer.h \
    interface.h \
    mixer_main.h \
    libusb.h \
    qfingerscrollarea.h \
    channelbox.h \
    outputbox.h \
    masterslider.h \

FORMS    += \
    mixer_main.ui

RESOURCES += \
    Resources.qrc

OTHER_FILES +=



macx: LIBS += -L$$PWD/ -lusb-1.0.0

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
