#ifndef LEAGUE_HPP
#define LEAGUE_HPP

#include "DivisionList.hpp"
class League
{
    DivisionList division;
    string name;

public:
    League(string name) : name(name)
    {
    }
    void AddDivision(Division *div)
    {
        division.push_back(div);
    }
    friend ostream &operator<<(ostream &os, League &league)
    {
        os << league.name << "\n"
           << league.division;
        return os;
    }
};

#endif // LEAGUE_HPP
