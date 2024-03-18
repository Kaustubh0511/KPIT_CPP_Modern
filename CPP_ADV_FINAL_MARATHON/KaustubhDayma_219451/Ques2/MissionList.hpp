#ifndef MISSIONLIST_HPP
#define MISSIONLIST_HPP

#include "Mission.hpp"
class MissionList : public list<Mission *>
{
public:
    friend ostream &operator<<(ostream &os, MissionList &missionList);
    
};

#endif // MISSIONLIST_HPP
