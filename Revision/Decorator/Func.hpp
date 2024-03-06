#ifndef FUNC_HPP
#define FUNC_HPP

#include <iostream>
#include <tuple>
#include <string>
#include <functional>
#include <list>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <variant>
#include "CAT.hpp"
#include "DOG.hpp"
#include "OX.hpp"
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

class Func
{
public:
    void operator()(CAT cat)
    {
        cat.catFun();
    }
    void operator()(DOG dog)
    {
        dog.dogFun();
    }
    void operator()(OX ox)
    {
        ox.oxFun();
    }
} fnc;

#endif // FUNC_HPP
