#include "Opera.h"

void OperaAudio::createAudio()
{
    cout << "Opera Audio Created\n";
}

void OperaAudio::attachAudio()
{
    cout << "Opera Audio Attached\n";
}

void OperaVideo::createVideo()
{
    cout << "Opera Video Created\n";
}

void OperaVideo::attachVideo()
{
    cout << "Opera Video Attached\n";
}

void OperaMag::createMag()
{
    cout << "Opera Magnification Created\n";
}

void OperaMag::attachMag()
{
    cout<<"Opera Mag Attached\n";
}

IAudio *OperaFactory::getAudio()
{
    return new OperaAudio();
}

IVideo *OperaFactory::getVideo()
{
    return new OperaVideo();
}

IMag *OperaFactory::getMag()
{
    return new OperaMag();
}

