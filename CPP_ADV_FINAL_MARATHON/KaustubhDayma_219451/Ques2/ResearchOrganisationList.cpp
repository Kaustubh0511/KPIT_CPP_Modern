#include "ResearchOrganisationList.hpp"

ostream &operator<<(ostream &os, ResearchOrgainiasationList &rol)
{
    for (auto rng : rol)
    {
        os << rng;
    }
    return os;
}
