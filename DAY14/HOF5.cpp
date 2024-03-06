#include <iostream>
#include <tuple>
#include <string>
#include <list>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include <random>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

void fun1()
{
    cout << "fun1 Apple\n";
}
void fun2(int count)
{
    cout << "fun2 Orange , count = " << count << '\n';
}
int main()
{
    std::reference_wrapper<void()> ref = fun1;
    ref();
    auto ref1 = std::ref(fun1);
    ref1();
    line();
    std::function<void()> ref3 = std::bind(fun2, 140);
    ref3();
    line();
    auto ref2 = std::bind(fun2, 100);
    ref2();

    int k = 100;
    auto lmd = [k](int x, int y)
    { cout << "k = " << k << " x = " << x << " y = " << y << '\n'; };
    std::function<void(int, int)> refLmd = std::bind(lmd, placeholders::_2, placeholders::_1);
    auto refLmdRef = std::ref(refLmd);
    refLmdRef(101, 102);
    line();
    return 0;
}