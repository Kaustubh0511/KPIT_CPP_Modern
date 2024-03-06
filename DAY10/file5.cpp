#include <iostream>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------\n"

void VendorFun(std::function<void(int)> obj)
{
    cout << "Start\n";
    // callback;
    obj(1);
    cout << "End\n";
}
class CA
{
public:
    void Bharath(int x)
    {
        cout << "Bharath x : " << x << "\n";
    }
    void India(int x)
    {
        cout << "India x : " << x << "\n";
    }
    void Hindustan(int x)
    {
        cout << "Hindustan x : " << x << "\n";
    }
    void Alhind(int x)
    {
        cout << "Alhind x : " << x << "\n";
    }
};

int main()
{
    CA c;
    VendorFun([&c](int x)
              { c.Bharath(x); });
    std::function<void(int)> fnc1 = std::bind(&CA::Bharath, &c, placeholders::_1);
    VendorFun(fnc1);
    return 0;
}