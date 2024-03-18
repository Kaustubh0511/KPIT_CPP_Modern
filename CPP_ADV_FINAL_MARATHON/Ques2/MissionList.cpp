#include "MissionList.hpp"

ostream &operator<<(ostream &os, MissionList &missionList)
{
    for (auto rng : missionList)
    {
        os << *rng;
    }
    return os;
}