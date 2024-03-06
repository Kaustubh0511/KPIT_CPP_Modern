#ifndef CHROME_H
#define CHROME_H

#include "file1.h"

class ChromeAudio : public IAudio
{
public:
    void createAudio() override;
    void attachAudio() override;
};

class ChromeVideo : public IVideo
{
public:
    void createVideo() override;
    void attachVideo() override;
};

class ChromeMag : public IMag
{
public:
    void createMag() override;
    void attachMag() override;
};

class ChromeFactory : public IFactory
{
public:
    IAudio *getAudio() override;
    IVideo *getVideo() override;
    IMag *getMag() override;
};
#endif // CHROME_H
