#ifndef TEAM_HPP
#define TEAM_HPP

#include "PlayerList.hpp"
class Team
{
    PlayerList players;
    string name;

public:
    Team(string name) : name(name)
    {
    }
    void AddPlayer(Player *ply)
    {
        players.push_back(ply);
    }
    friend ostream &operator<<(ostream &os, Team &team)
    {
        os << "\t\t" << team.name << "\n"
           << team.players;
        return os;
    }
};

#endif // TEAM_HPP
