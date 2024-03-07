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

std::optional<std::string> GetValForFun(int par)
{
    if (10 == par)
    {
        return "kunal";
    }
    else if (20 == par)
    {
        return {};
    }
    return nullopt; // this is called as null option/nullopt
}
int main()
{
    cout << GetValForFun(10).value_or("Dere1") << "\n";
    cout << GetValForFun(20).value_or("Dere2") << "\n";
    cout << GetValForFun(30).value_or("Dere3") << "\n";

    std::optional<string> res = GetValForFun(10);
    if (res.has_value())
    {
        cout << "Has Value : " << res.value() << '\n';
    }
    return 0;
}
