#include "BaseMomento.h"

void BaseMomento::SetCareTaker(CareTaker *_caretaker) { this->_caretaker = _caretaker; }

void BaseMomento::Hyderate(){
    IMomento* state =clone();
    _caretaker->FeedIn(this,state);
}
void BaseMomento::Dehyderate(){
    IMomento* RecivedState=_caretaker->FetchOut(this);
    ReciveState(RecivedState);
}