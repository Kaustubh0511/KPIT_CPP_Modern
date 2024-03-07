#include "CareTaker.h"

void CareTaker::FeedIn(void *key, IMomento *value) { _repo[key] = value; }

IMomento *CareTaker::FetchOut(void *key)
{
    IMomento *value = _repo[key];
    _repo.erase(key);
    return value;
}
