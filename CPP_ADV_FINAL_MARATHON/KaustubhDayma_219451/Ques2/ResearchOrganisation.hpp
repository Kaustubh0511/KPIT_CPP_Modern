#ifndef ORGANISATION_HPP
#define ORGANISATION_HPP

#include "MissionList.hpp"
class ResearchOrganisation
{
    MissionList ml;
    string name;

public:
    ResearchOrganisation(string name) : name(name)
    {
    }
    void AddMission(Mission *m);

    friend ostream &operator<<(ostream &os, ResearchOrganisation &org);
    
};

#endif // ORGANISATION_HPP
