#ifndef BASEMOMENTO_H
#define BASEMOMENTO_H

#include "IMomento.h"
#include "CareTaker.h"

class BaseMomento
{
private:
    CareTaker* _caretaker{nullptr};

public:
    BaseMomento() = default;
    BaseMomento(const BaseMomento&) = delete;
    BaseMomento(BaseMomento&&) = delete;
    BaseMomento& operator=(const BaseMomento&) = delete;
    BaseMomento& operator=(const BaseMomento&&) = delete;
    ~BaseMomento() = default;

     void SetCareTaker(CareTaker* );
     void Hyderate();
     void Dehyderate();

protected:
    virtual std::any clone()=0;
    virtual void ReciveState(std::any)=0;
};                                                                                                                  

#endif // BASEMOMENTO_H
