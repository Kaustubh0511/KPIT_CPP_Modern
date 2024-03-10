#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
    string _name;

public:
    Player(string name) : _name(name)
    {
    }
    friend ostream &operator<<(ostream &os, Player &ply)
    {
        os << "\t\t\t" << ply._name << endl;
        return os;
    }
};

#endif // PLAYER_HPP
