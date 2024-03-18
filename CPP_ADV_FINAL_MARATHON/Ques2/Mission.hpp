#ifndef MISSION_HPP
#define MISSION_HPP

#include "ScientistList.hpp"
class Mission
{
    ScientistList sci;
    string name;

public:
    Mission(string name) : name(name)
    {
    }
    void AddScientist(Scientist *s);
    
    friend ostream &operator<<(ostream &os, Mission &mis);
    
};

#endif // MISSION_HPP
