#include "CareTaker.h"

void CareTaker::FeedIn(void *key, std::any value) { _repo[key] = value; }

std::any CareTaker::FetchOut(void *key)
{
    std::any value = _repo[key];
    _repo.erase(key);
    return value;
}
