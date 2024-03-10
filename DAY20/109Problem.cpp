#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Composite pattern

class Player
{
    string name;

public:
    Player(string name) : name(name)
    {
    }
    friend ostream &operator<<(ostream &os, Player &p)
    {
        os << "\t\t\t\t\t" << p.name << "\n";
        return os;
    }
};

class PlayerList : vector<Player *>
{
public:
    void AddPlayer(Player *p)
    {
        push_back(p);
    }
    friend ostream &operator<<(ostream &os, PlayerList &ply)
    {
        for (auto rng : ply)
        {
            cout << *rng << "\n";
        }
        return os;
    }
};

class Team
{
    string name;
    PlayerList ply;

public:
    Team(string name) : name(name)
    {
    }
    void AddPlayer(Player *p)
    {
        ply.AddPlayer(p);
    }
    friend ostream &operator<<(ostream &os, Team &t)
    {
        os << "\t\t\t\t" << t.name << "\n"
           << t.ply;
        return os;
    }
};

class TeamList : vector<Team *>
{
public:
    void AddTeam(Team *t)
    {
        push_back(t);
    }
    friend ostream &operator<<(ostream &os, TeamList &tl)
    {
        for (auto rng : tl)
        {
            os << *rng << "\n";
        }
        return os;
    }
};

class Division
{
    string name;
    TeamList teamlist;

public:
    Division(string name) : name(name)
    {
    }
    void AddTeam(Team *t)
    {
        teamlist.AddTeam(t);
    }
    friend ostream &operator<<(ostream &os, Division &d)
    {
        os << "\t\t" << d.name << "\n"
           << d.teamlist;
        return os;
    }
};

class DivisionList : vector<Division *>
{
public:
    void AddDivision(Division *d)
    {
        push_back(d);
    }
    friend ostream &operator<<(ostream &os, DivisionList &dl)
    {
        for (auto rng : dl)
        {
            os << dl << "\n";
        }
        return os;
    }
};

class League
{
    string name;
    DivisionList divlist;
    /* Composite Pattern 
    Abstract Factory
    Sender Reciever
    Injection with CRTP
    Momento 
    Chain of Responsibilty or Interpreter 

    */

public:
    League(string name) : name(name)
    {
    }

    void AddDivision(Division *d)
    {
        divlist.AddDivision(d);
    }
    friend ostream &operator<<(ostream &os, League &l)
    {
        os << "\t" << l.name << "\n"
           << l.divlist;
        return os;
    }
};

class LeagueList : vector<League *>
{
public:
    void AddLeague(League *lg)
    {
        push_back(lg);
    }
    friend ostream &operator<<(ostream &os, LeagueList &ll)
    {
        for (auto rng : ll)
        {
            os << *rng << "\n";
        }
        return os;
    }
};

int main()
{
    LeagueList lg_lst;
    League *l = nullptr;
    Division *d = nullptr;
    Team *t = nullptr;
    Player *p = nullptr;

    lg_lst.AddLeague(l = new League("League Alpha"));
    l->AddDivision(d = new Division("Div A"));
    d->AddTeam(t = new Team("CSK"));
    t->AddPlayer(p = new Player("Player Dhoni"));
    t->AddPlayer(p = new Player("Player Raina"));

    cout << lg_lst << "\n";

    return 0;
}