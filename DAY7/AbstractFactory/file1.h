#ifndef FILE1_H
#define FILE1_H

#include <iostream>
using namespace std;
#define line(msg) cout << "--------------" #msg "-------------\n";

class IAudio
{
public:
    IAudio() = default;
    IAudio(const IAudio &) = delete;
    IAudio(IAudio &&) = delete;
    ~IAudio() = default;

    virtual void createAudio() = 0;
    virtual void attachAudio() = 0;
};

class IVideo
{
public:
    IVideo() = default;
    IVideo(const IAudio &) = delete;
    IVideo(IVideo &&) = delete;
    ~IVideo() = default;

    virtual void createVideo() = 0;
    virtual void attachVideo() = 0;
};

class IMag
{
public:
    IMag() = default;
    IMag(const IAudio &) = delete;
    IMag(IVideo &&) = delete;
    ~IMag() = default;

    virtual void createMag() = 0;
    virtual void attachMag() = 0;
};

class IFactory
{
public:
    virtual IAudio *getAudio() = 0;
    virtual IVideo *getVideo() = 0;
    virtual IMag *getMag() = 0;
};

#endif // FILE1_H
