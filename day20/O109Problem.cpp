#include <iostream>
#include <string>
#include <list>
using namespace std;

class Player
{
	string _name;

public:
	Player(string name) : _name(name)
	{
	}
	friend ostream &operator<<(ostream &os, Player &player)
	{
		os << "\t\t\t\t" << player._name << endl;

		return os;
	}
};

class PlayerList : public list<Player *>
{
public:
	friend ostream &operator<<(ostream &os, PlayerList &playerList)
	{
		for (auto player : playerList)
		{
			os << *player << '\n';
		}
		return os;
	}
};

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
		os << "\t\t\t" << team.name << '\n'
		   << team.players;
		return os;
	}
};

class Teamlist : public list<Team *>
{
public:
	friend ostream &operator<<(ostream &os, Teamlist &teamlist)
	{
		for (auto rng : teamlist)
		{
			os << *rng << '\n';
		}
		return os;
	}
};

class Division
{
	Teamlist teams;
	string Name;

public:
	Division(string Name) : Name(Name)
	{
	}
	void AddTeam(Team *team)
	{
		teams.push_back(team);
	}
	friend ostream &operator<<(ostream &os, Division &division)
	{
		os << "\t\t" << division.Name << '\n'
		   << division.teams;
		return os;
	}
};

int main()
{
	Team *team;

	Division div1("Apple");
	div1.AddTeam(team = new Team("Alpha"));
	team->AddPlayer(new Player("sewag"));
	team->AddPlayer(new Player("rahul"));

	div1.AddTeam(team = new Team("Beta"));
	team->AddPlayer(new Player("virat"));
	team->AddPlayer(new Player("rohith"));

	cout << div1 << '\n';

	Division div2("orange");
	div2.AddTeam(team = new Team("Alpha"));
	team->AddPlayer(new Player("sewag"));
	team->AddPlayer(new Player("rahul"));
	team->AddPlayer(new Player("vvs"));
	team->AddPlayer(new Player("sachin"));
	team->AddPlayer(new Player("zaheer"));

	div2.AddTeam(team = new Team("Beta"));
	team->AddPlayer(new Player("virat"));
	team->AddPlayer(new Player("rohith"));
	team->AddPlayer(new Player("rahane"));
	team->AddPlayer(new Player("dhoni"));
	team->AddPlayer(new Player("rahul"));

	div2.AddTeam(team = new Team("Gama"));
	team->AddPlayer(new Player("prabakar"));
	team->AddPlayer(new Player("ajay"));
	team->AddPlayer(new Player("azhar"));
	team->AddPlayer(new Player("mongia"));

	cout << div2;

	return 0;
}

