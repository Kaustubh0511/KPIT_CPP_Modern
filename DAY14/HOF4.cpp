#include <iostream>
#include <tuple>
#include <string>
#include <list>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include <random>
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
    vector<std::reference_wrapper<int>> vec(lst.begin(), lst.end());
    PrintMe("Element of list: ", lst);
    PrintMe("Element of vector are", vec);
    line();
    std::shuffle(vec.begin(), vec.end(), std::mt19937{std::random_device{}()});
    PrintMe("After shuffling of vector :", vec);
    line();
    vec[3].get() = 999;
    PrintMe("After shuffling of vector :", vec);
    PrintMe("List is the same", lst);
    return 0;
}