#include <iostream>
#include <tuple>
#include <string>
#include <functional>
#include <tuple>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

auto shubham = [](int x, int y)
{ return x + y; };

template <typename T>
T mano(T x, T y) { return x + y; }
auto aabhas = [](auto x, auto y)
{ return x + y; };

template <typename... T>
ostream &operator<<(ostream &os, tuple<T...> const &tup)
{
    std::apply([&os](T const &...tupArgs)
               { ((os << tupArgs << '\t'), ...); },
               tup);
    cout << '\n';
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec)
{
    for (auto rng : vec)
    {
        cout << rng << '\t';
    }
    cout << '\n';
    return os;
}

int main()
{
    cout << "result1 : " << std::apply(shubham, make_tuple(10, 20)) << "\n";
    cout << "result2 : " << std::apply(aabhas, make_tuple(10, 20)) << "\n";
    cout << "result3 : " << std::apply(shubham, std::pair(10, 20)) << "\n";
    cout << "result4 : " << std::apply(aabhas, std::pair(10, 20)) << "\n";

    // error : cannot deduce
    //  cout << "result5 : " << std::apply(shubham, make_tuple(10, 20));

    tuple vishal(100, "shagun", 1.0f, 3.14159, 'c');
    cout << vishal << '\n';
    return 0;
}