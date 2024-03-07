#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <tuple>
#include <string>
#include <functional>
#include <list>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <random>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

class DOG
{
public:
    DOG()
    {
        cout << "DOG()\n";
    }
    void dogFun()
    {
        cout << "DOG::dogFun()\n";
    }
    ~DOG()
    {
        cout << "~DOG()\n";
    }
};

#endif // DOG_H
