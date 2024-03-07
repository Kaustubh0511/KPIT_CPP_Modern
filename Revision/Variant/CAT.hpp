#ifndef CAT_H
#define CAT_H
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

class CAT
{
public:
    CAT()
    {
        cout << "CAT()\n";
    }
    void catFun()
    {
        cout << "CAT::catFun()\n";
    }
    ~CAT()
    {
        cout << "~CAT()\n";
    }
};

#endif // CAT_H
