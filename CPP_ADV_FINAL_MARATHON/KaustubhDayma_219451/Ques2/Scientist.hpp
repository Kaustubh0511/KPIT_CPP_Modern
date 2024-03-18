#ifndef SCIENTIST_HPP
#define SCIENTIST_HPP

#include <iostream>
#include <string>
#include <list>
#define line(msg) cout << "-----------" #msg "---------\n"
using namespace std;

class Scientist
{
    string name;

public:
    Scientist(string name) : name(name)
    {
    }

    friend ostream &operator<<(ostream &os, Scientist &sc);
    
};

#endif // SCIENTIST_HPP
