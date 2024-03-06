#ifndef CHROME_H
#define CHROME_H

#include "file1.h"

class OperaAudio : public IAudio
{
public:
    void createAudio() override;
    void attachAudio() override;
};

class OperaVideo : public IVideo
{
public:
    void createVideo() override;
    void attachVideo() override;
};

class OperaMag : public IMag
{
public:
    void createMag() override;
    void attachMag() override;
};

class OperaFactory : public IFactory
{
    public:
    IAudio *getAudio() override;
    IVideo *getVideo() override;
    IMag *getMag() override;
};
#endif // CHROME_H
