#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <tuple>
template <typename... T>
auto sum1(T... t)
{
    return (std::forward<T>(t) + ...);
}

template <typename... PCK>
void ShowAll(PCK... pck)
{
    ((cout << std::forward<PCK>(pck) << "\t"), ...);
    cout << "\n";
}

template <typename T, typename... PCK>
void pushAll(vector<T> &vec, PCK... pck)
{
    (vec.push_back(std::forward<PCK>(pck)), ...);
}

template <typename T>
std::ostream &operator<<(ostream &os, vector<T> &vec)
{
    for (auto rng : vec)
    {
        os << rng << "\t";
    }
    return os;
}

#endif // FUNCTIONS_HPP
