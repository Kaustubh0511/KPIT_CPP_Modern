#include "ResearchOrganisation.hpp"

void ResearchOrganisation::AddMission(Mission *m)
{
    ml.push_back(m);
}

ostream &operator<<(ostream &os, ResearchOrganisation &org)
{
    os << " " << org.name << '\n'
       << org.ml;
    return os;
}
