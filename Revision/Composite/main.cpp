#include "League.hpp"

int main()
{
    Team *t;
    Division *div1;
    League l1("IPL");
    l1.AddDivision(div1 = new Division("Div A"));
    div1->AddTeam(t = new Team("CSK"));
    t->AddPlayer(new Player("Dhoni"));
    t->AddPlayer(new Player("DJ Bravo"));
    div1->AddTeam(t = new Team("RR"));
    t->AddPlayer(new Player("Watson"));
    t->AddPlayer(new Player("Sachin"));

    Division *div2;
    l1.AddDivision(div2 = new Division("Div B"));
    div2->AddTeam(t = new Team("MI"));
    t->AddPlayer(new Player("Rohit"));
    t->AddPlayer(new Player("Pandya"));
    div2->AddTeam(t = new Team("RCB"));
    t->AddPlayer(new Player("Virat"));
    t->AddPlayer(new Player("Gayle"));
    cout << l1;
    return 0;
}
