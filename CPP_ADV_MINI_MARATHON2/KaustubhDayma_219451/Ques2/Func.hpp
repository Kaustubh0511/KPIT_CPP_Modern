#ifndef FUNC_HPP
#define FUNC_HPP
#include <iostream>
#include "structCar.hpp"
#include "structLorry.hpp"
#include "structOX.hpp"
using namespace std;

class Func
{
public:
    void operator()(Car car)
    {
        car.carFun();
    }
    void operator()(Lorry Lorry)
    {
        Lorry.lorryFun();
    }
    void operator()(Ox ox)
    {
        ox.OxFun();
    }

} fnc;

#endif // FUNC_HPP
