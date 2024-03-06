#include <iostream>
using namespace std;
#define line(msg) cout << "------------" #msg "----------------\n"

// template <typename T>
using FPTR = void (*)();
void vendorFun(FPTR obj)
{
    cout << "vendor job started T :[ " << typeid(obj).name() << " ]\n";
    obj();
    cout << "vendor job completed\n";
}

// ----------------
int main()
{
    int i = 100;
    int j = 200;
    // auto fnc = functor() {};
    // auto fnc = []() {}; // lambda expression

    // auto f1 = []()
    // { cout << "I am from lambda\n"; }; // inspector ()operator
    // auto f2 = []() mutable
    // { cout << "I am from lambda\n"; }; // mutable ()operator
    // auto f3 = [i]()
    // { i += 100; cout << "I am from lambda i : " << i << "\n"; }; // inspector ()operator
    // auto f4 = [i]()
    // { cout << "I am from lambda i : " << i << "\n"; };
    // auto f5 = [i, j]()
    // { cout << "I am from lambda i : " << i << "j : "
    //        << " \n"; };

    auto func = []() {cout<<"I am from lambda";}; // lambda without capture can be converted to a function pointer.
    vendorFun(func);
    return 0;
}