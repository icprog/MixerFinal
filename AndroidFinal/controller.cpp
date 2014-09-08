#include "controller.h"
#include <QApplication>
#include <usb_mixer.h>
#include <iostream>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QMutex>
#include<interface.h>






Controller::Controller()
    : QObject()
{

}

int Controller::initController()
{
    activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");
    int fd = activity.callMethod<jint>("returnFD");
    int g = usb_mixer_connect(fd);
    return g;
}

void Controller::deinitController()
{
    int g = usb_mixer_disconnect();
}

unsigned short* Controller::getLevels(int inout)
{
    int y = usb_mixer_mem_get(0,inout,levels);
    unsigned short * levelData = (unsigned short *)levels;
    return levelData;
}

void Controller::mapChannelToMix(int channel, int mixerChannel)
{
   int b = usb_set_aud_channel_map(channel ,mixerChannel);
}

unsigned char Controller::getMixerMap(int mixerChannel, int mixRef)
{
    return usb_mixsel_get_state(0, mixerChannel, mixRef);
}

void Controller::mapMixInput(int mixerChannel, int channel, int mixRef)
{
    usb_mixsel_set_state(0, mixerChannel, channel, mixRef);
}

void Controller::changeVolume(int node, int volume)
{
    int x = usb_mixer_set_value(0, node, volume);
}

int Controller::getMap(int channel)
{
    int x = usb_get_aud_channel_map(channel);
    return x;
}

int Controller::getValue(int node)
{
    int y = usb_mixer_get_value(0,node);
    return y;
}


