#include "Mission.hpp"

void Mission::AddScientist(Scientist *s)
{
    sci.push_back(s);
}

ostream &operator<<(ostream &os, Mission &mis)
{
    os << "\t\t" << mis.name << "\n"
       << mis.sci;
    return os;
};
