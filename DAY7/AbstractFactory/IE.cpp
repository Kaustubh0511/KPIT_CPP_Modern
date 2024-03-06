#include "IE.h"

void IEAudio::createAudio()
{
    cout<<"IE Audio Created\n";
}

void IEAudio::attachAudio()
{
    cout<<"IE Audio Attached\n";
}

void IEVideo::createVideo()
{
    cout<<"IE Video Created\n";
}

void IEVideo::attachVideo()
{
    cout<<"IE Video Attached\n";
}

void IEMag::createMag()
{
    cout<<"IE Mag Created\n";
}

void IEMag::attachMag()
{
    cout<<"IE Mag Attached\n";
}

IAudio *IEFactory::getAudio()
{
    return new IEAudio();
}

IVideo *IEFactory::getVideo()
{
    return new IEVideo();
}

IMag *IEFactory::getMag()
{
    return new IEMag();
}
