#ifndef DIVISIONLIST_HPP
#define DIVISIONLIST_HPP

#include "Division.hpp"
class DivisionList : public vector<Division *>
{
public:
    friend ostream &operator<<(ostream &os, DivisionList &dl)
    {
        for (auto rng : dl)
        {
            os << *rng ;
        }
        return os;
    }
};

#endif // DIVISIONLIST_HPP
