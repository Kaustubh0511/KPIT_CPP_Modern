#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "---------------------\n";

template <typename T>
auto Sum(T par)
{
    return 0;
}

template <typename T1, typename... T>
auto Sum(T1 p, T... par)
{
    return p + Sum(par...);
}

int main1()
{
    cout << Sum(1, 2, 3, 4, 5, 6, 7, 8, 9) << "\n";
    return 0;
}
