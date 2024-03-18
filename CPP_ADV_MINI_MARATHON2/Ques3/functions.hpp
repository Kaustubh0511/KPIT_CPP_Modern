#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
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
auto add = [](int x, int y)
{ return x + y; };

auto Sum2 = [](auto first, auto second)
{ return first + second; };

template <typename... T>
ostream &operator<<(ostream &os, tuple<T...> const &tup)
{
    std::apply([&os](T const &...tupArgs)
               { ((os << tupArgs << '\t'), ...); },
               tup);
    return os;
}

#endif // FUNCTIONS_HPP
