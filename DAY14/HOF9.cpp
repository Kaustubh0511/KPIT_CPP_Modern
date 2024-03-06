#include <iostream>
#include <tuple>
#include <string>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

void PrintMe(int i)
{
    cout << i << "\n";
}

class CA
{
public:
    int _x;
    CA(int x) : _x(x)
    {
    }
    void PrintX(int y) const
    {
        cout << "PrintX _x = " << _x + y << "\n";
    }
    void operator()(int i) const
    {
        cout << "CA() i  = " << i << "\n";
    }
};

int main()
{
    std::invoke(PrintMe, 1000);
    line();
    std::invoke([]()
                { PrintMe(99); });
    line();
    const CA obj(111);
    std::invoke(&CA::PrintX, obj, 222);
    line();
    cout << "_x = " << std::invoke(&CA::_x, obj) << "\n";
    line();
    std::invoke(obj, 666);
    line();
    std::invoke([](int par)
                { cout << "Hello " << par << "\n"; },
                1010);
    line();
    std::invoke([](int par) { cout << "Hello " << par << "\n";}, std::invoke(&CA::_x,obj));
    return 0;
}