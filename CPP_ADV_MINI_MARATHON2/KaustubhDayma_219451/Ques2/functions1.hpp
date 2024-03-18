#ifndef FUNCTIONS1_HPP
#define FUNCTIONS1_HPP

#include "structCar.hpp"
#include "structLorry.hpp"
#include "structOX.hpp"
#include "Func.hpp"
#include <variant>
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

// snippet
void DoBuisness(variant<Car, Lorry, Ox> vt)
{
    return std::visit(fnc, vt);
}

void BookVehicle(int id, string driverName)
{
    cout << "BookVehicle id : " << id << "\t"
         << "driver name : " << driverName << "\n";
}

void FeedAnimal(string item, int weight)
{
    cout << "Feed Animal with : " << item << " of weight : " << weight << "kgs\n";
}

void ExecuteBuisnessFlow(std::function<void()> fn)
{
    fn();
}

#endif // FUNCTIONS1_HPP
