#include <iostream>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------\n"

void Vendor3(std::function<int(int)> obj)
{
    cout << "Start\n";
    int res = obj(30);
    cout << "End res : " << res << "\n";
}

int ClientFun(int x, int y)
{
    cout << "x : " << x << " y : " << y << "\n";
    return x + y + 10;
}

int main()
{
    int i = 999;
    // using FPTR = int (*)(int, int);
    using FPTR = std::function<int(int,int)>;
    FPTR fp1 = ClientFun;
    auto func = [i, fp1](int venPar)
    { return fp1(i, venPar); };
    Vendor3(func);
    line();
    std::function<int(int)> fnc1 = std::bind(&ClientFun, i, placeholders::_1);
    Vendor3(fnc1);
    std::function<int(int)> fnc2 = std::bind(&ClientFun, placeholders::_1,i);
    Vendor3(fnc2);
}