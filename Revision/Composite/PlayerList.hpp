#ifndef PLAYERLIST_HPP
#define PLAYERLIST_HPP

#include "Player.hpp"

class PlayerList : public vector<Player *>
{
public:
    friend ostream &operator<<(ostream &os, PlayerList &pl)
    {
        for (auto play : pl)
        {
            os << *play;
        }
        return os;
    }
};

#endif // PLAYERLIST_HPP
