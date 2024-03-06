#include <iostream>
#include <vector>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

class MyMethod
{
public:
    void AddFun(int)
    {
        cout << "MyMethod::AddFun(int)\n";
    }
    void AddFun(int, int)
    {
        cout << "MyMethod::AddFun(int,int)\n";
    }
};

class MyMethodEx : public MyMethod
{
public:
    using MyMethod::AddFun;
    void AddFun(int, int, int)
    {
        cout << "MyMethodEx::AddFun(int,int,int)\n";
    }
};

int main()
{
    MyMethodEx obj;
    obj.AddFun(10);
    obj.AddFun(10, 20);
    obj.AddFun(10, 20, 30);

    return 0;
}
