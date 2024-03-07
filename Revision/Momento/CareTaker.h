#ifndef CARETAKER_H
#define CARETAKER_H

#include <map>
#include "IMomento.h"
using std::map;

class CareTaker
{
private:
    map<void *, IMomento *> _repo;

public:
    CareTaker() = default;
    CareTaker(const CareTaker &) = delete;
    CareTaker(CareTaker &&) = delete;
    CareTaker &operator=(const CareTaker &) = delete;
    CareTaker &operator=(const CareTaker &&) = delete;
    ~CareTaker() = default;

    operator CareTaker *(){return this;}
    void FeedIn(void *, IMomento *);
    IMomento *FetchOut(void *key);
};

#endif // CARETAKER_H
