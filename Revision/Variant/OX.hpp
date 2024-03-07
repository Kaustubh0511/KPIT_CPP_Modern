#ifndef OX_HPP
#define OX_HPP

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

class OX
{
public:
    OX()
    {
        cout << "OX()\n";
    }
    void oxFun()
    {
        cout << "OX::oxFun()\n";
    }
    ~OX()
    {
        cout << "~OX()\n";
    }
};

#endif // OX_HPP
