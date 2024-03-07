#include <iostream>
#include <tuple>
#include <string>
#include <functional>
#include <list>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <any>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

int main()
{
    std::any a = 10;
    a = "sachin";

    cout << a.type().name() << " : " << std::any_cast<const char *>(a) << "\n";
    a = 100;
    cout << a.type().name() << " : " << std::any_cast<int>(a) << "\n";

    try
    {
        cout << a.type().name() << " : " << std::any_cast<double>(a) << "\n";
    }
    catch (std::bad_any_cast &exp)
    {
        cout << exp.what() << '\n';
    }

    a.reset();
    if (!a.has_value())
    {
        cout << "no value \n";
    }
    return 0;
}