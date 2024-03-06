#include <iostream>
#include <tuple>
#include <string>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

template <typename T>
void PrintMe(string displaymsg, T &collection)
{
    // cout << "T = [" << typeid(T).name() << "]\n";
    for (auto rng : collection)
    {
        cout << rng << "\t";
    }
    cout << "\n";
}

int main()
{
    // int arr[6] = {11, 22, 33, 44, 55, 66};
    std::list<int> lst(7);
    std::iota(lst.begin(), lst.end(), 1);
    PrintMe("Elements are : ", lst);
    line();
    std::for_each(lst.begin(), lst.end(), [](int &par)
                  { par *= 20; });
    // PrintMe("After using HOF for_each", lst);
    std::for_each(lst.begin(), lst.end(), [](int &par)
                  { cout << par << "\t"; });
    cout << "\n";
    return 0;
}