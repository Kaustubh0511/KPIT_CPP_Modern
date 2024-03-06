#include "Functionality.h"

void functionality()
{
    IFactory * factory = FactoryDecider::getFactoy(10);
    IAudio* audio = factory->getAudio();
    audio->createAudio();
    audio->attachAudio();

    IVideo* video = factory->getVideo();
    video->createVideo();
    video->attachVideo();

    IMag* mag = factory->getMag();
    mag->createMag();
    mag->attachMag();
}