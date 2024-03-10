#ifndef TEAMLIST_HPP
#define TEAMLIST_HPP

#include "Team.hpp"
class TeamList : public vector <Team *>
{
public:
    friend ostream &operator<<(ostream &os, TeamList &tl)
    {
        for (auto rng : tl)
        {
            os << *rng ;
        }
        return os;
    }
};
#endif // TEAMLIST_HPP
