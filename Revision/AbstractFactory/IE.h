#ifndef IE_H
#define IE_H

#include "file1.h"

class IEAudio : public IAudio
{
public:
    void createAudio() override;
    void attachAudio() override;
};

class IEVideo : public IVideo
{
public:
    void createVideo() override;
    void attachVideo() override;
};

class IEMag : public IMag
{
public:
    void createMag() override;
    void attachMag() override;
};

class IEFactory : public IFactory
{
    public:
    IAudio *getAudio() override;
    IVideo *getVideo() override;
    IMag *getMag() override;
};

#endif // IE_H
