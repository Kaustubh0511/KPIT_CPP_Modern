#include <iostream>
#include <tuple>
#include <string>
#include <functional>
#include <list>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <optional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

auto ChangeVal(int par)
{
    static string name = "shubham";
    return par == 10 ? std::optional<std::reference_wrapper<string>>{name} : nullopt;
}
int main()
{
    auto res = ChangeVal(10);
    cout << res->get() << '\n';
    res->get() = "Das";
    auto res1 = ChangeVal(10);
    cout << res1->get() << '\n';

    return 0;
}
