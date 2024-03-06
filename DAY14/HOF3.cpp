#include <iostream>
#include <tuple>
#include <string>
#include <list>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

template <typename T>
void PrintMe(string msg, T &collection)
{
    cout << msg << "\n";
    for (auto rng : collection)
    {
        cout << rng << '\t';
    }

    cout << '\n';
}
int main()
{
    std::list<int> lst(7);
    std::iota(lst.begin(), lst.end(), 1);
    vector<int> vec(lst.begin(), lst.end());
    PrintMe("Element of lsit : ", lst);
    line();
    PrintMe("Element of vector : ", vec);
    line();
    vector<std::reference_wrapper<int>> vec2(lst.begin(), lst.end());
    vec2[2].get() = 999;
    PrintMe("After using reference wrapper", vec2);
    line();
    return 0;
}