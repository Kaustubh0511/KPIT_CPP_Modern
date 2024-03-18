#ifndef RESEARCHORGANISATIONLIST_HPP
#define RESEARCHORGANISATIONLIST_HPP

#include "ResearchOrganisation.hpp"
class ResearchOrgainiasationList : public list<ResearchOrganisation>
{

public:
    void AddResearchOrganisation(ResearchOrganisation rso)
    {
        push_back(rso);
    }
    friend ostream &operator<<(ostream &os, ResearchOrgainiasationList &rol);
};

#endif // RESEARCHORGANISATIONLIST_HPP
