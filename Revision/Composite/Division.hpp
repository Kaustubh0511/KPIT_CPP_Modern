#ifndef DIVISION_HPP
#define DIVISION_HPP

#include "TeamList.hpp"
class Division
{
    TeamList teams;
    string name;

public:
    Division(string name) : name(name)
    {
    }
    void AddTeam(Team *team)
    {
        teams.push_back(team);
    }
    friend ostream &operator<<(ostream &os, Division &div)
    {
        os << "\t" << div.name << "\n" << div.teams;
        return os;
    }
};

#endif // DIVISION_HPP
