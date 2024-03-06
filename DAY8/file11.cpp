#include <iostream>
using namespace std;
#define line(msg) cout << "------------" #msg "----------------\n"

template <typename T>
void vendorFun(T obj)
{
    cout << "vendor job started T :[ " << typeid(T).name() << " ]\n";
    obj();
    cout << "vendor job completed\n";
}
//------------------------------------------------------------------------
class CA
{
    int x{10};
    int y{20};

public:
    void fun1()
    {
        int a = 11;
        int b = 22;
        // inspector.
        auto fn1 = [=]()
        {
            x += 10; // members are captured by refernce.
            // a += 10; // local variables are cpatured by value, hence the error.
            cout << "x = " << x << "\n";
            cout << "y = " << y << "\n";
            cout << "a = " << a << "\n";
            cout << "b = " << b << "\n";
        };
        vendorFun(fn1);
    }

    void fun2()
    {
        int a = 11;
        int b = 22;
        // inspector where all are passed by refernce.
        auto fn1 = [&]()
        {
            x += 10; // members are captured by refernce.
            a += 10;
            cout << "x = " << x << "\n";
            cout << "y = " << y << "\n";
            cout << "a = " << a << "\n";
            cout << "b = " << b << "\n";
        };
        vendorFun(fn1);
    }

    void fun3()
    {
        int a = 11;
        int b = 22;
        // inspector where only members are captured by reference
        auto fn1 = [this]()
        {
            x += 10; // members are captured by refernce.
            // a += 10; //
            cout << "x = " << x << "\n";
            cout << "y = " << y << "\n";
            // cout << "a = " << a << "\n";
            // cout << "b = " << b << "\n";
        };
        vendorFun(fn1);
    }

    void fun4()
    {
        int a = 11;
        int b = 22;
        // inspector where members are capture by value intead of reference.
        auto fn1 = [local = *this]()
        {
            // x += 10; // members are captured by value , hence it is giving error.
            // a += 10;
            cout << "x = " << local.x << "\n";
            cout << "y = " << local.y << "\n";
        };
        vendorFun(fn1);
    }

    /*void fun5()
    {
        int a = 11;
        int b = 22;
        // inspector where members are capture by value intead of reference.
        auto fn1 = [*this]()
        {
            // x += 10; // members are captured by value , hence it is giving error.
            // a += 10;
            cout << "x = " << x << "\n";
            cout << "y = " << y << "\n";
        };
        vendorFun(fn1);
    }*/ // This is available in cpp 17 onwards.

};

int main()
{
    CA obj;
    obj.fun1();
    line();
    obj.fun2();
    line();
    obj.fun3();
    line();
    obj.fun4();
    return 0;
}