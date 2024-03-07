#include "Chrome.h"

void ChromeAudio::createAudio()
{
    cout << "IE Audio Created\n";
}

void ChromeAudio::attachAudio()
{
    cout << "IE Audio Attached\n";
}

void ChromeVideo::createVideo()
{
    cout << "IE Video Created\n";
}

void ChromeVideo::attachVideo()
{
    cout << "IE Video Attached\n";
}

void ChromeMag::createMag()
{
    cout << "IE Magnification Created\n";
}

void ChromeMag::attachMag()
{
    cout<<"IE Mag Attached\n";
}

IAudio *ChromeFactory::getAudio()
{
    return new ChromeAudio();
}

IVideo *ChromeFactory::getVideo()
{
    return new ChromeVideo();
}

IMag *ChromeFactory::getMag()
{
    return new ChromeMag();
}
