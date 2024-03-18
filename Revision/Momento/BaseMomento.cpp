#include "BaseMomento.h"

void BaseMomento::SetCareTaker(CareTaker *_caretaker) { this->_caretaker = _caretaker; }

void BaseMomento::Hyderate(){
    std::any state =clone();
    _caretaker->FeedIn(this,state);
}
void BaseMomento::Dehyderate(){
    std::any RecivedState=_caretaker->FetchOut(this);
    ReciveState(RecivedState);
}