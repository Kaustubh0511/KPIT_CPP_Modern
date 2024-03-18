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

// snippet 1 solution
template <typename FN>
void print_args(FN fn)
{
}

template <typename FN, typename T, typename... Args>
void print_args(FN fn, T val, Args &&...pck)
{
    fn(std::forward<T>(val));
    print_args(fn, std::forward<Args>(pck)...);
}

// snippet 2 solution
template <typename T1, typename... T2>
auto GetVal(T1 t1, T2... t2)
{
    return invoke(t1, forward<T2>(t2)...);
}

// snippet 3 solution
void Change_List(std::list<int> &lst)
{
    std::iota(lst.begin(), lst.end(), 10);
    std::for_each(lst.begin(), lst.end(), [](int par)
                  { cout << par << '\t'; });
    cout << "\n";
    std::vector<std::reference_wrapper<int>> vec(lst.begin(), lst.end());
    for (auto rng : vec)
    {
        rng *= 10;
    }
    std::for_each(lst.begin(), lst.end(), [](int par)
                  { cout << par << '\t'; });
    cout << "\n";
}

#endif // FUNCTIONS_HPP
