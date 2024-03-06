#ifndef BASEMOMENTO_H
#define BASEMOMENTO_H

#include "IMomento.h"
#include "CareTaker.h"

class BaseMomento:public IMomento
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
     void Hyderate()override;
     void Dehyderate()override;

protected:
    virtual IMomento* clone()=0;
    virtual void ReciveState(IMomento*)=0;
};                                                                                                                  

#endif // BASEMOMENTO_H
