#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <functional>
#include <mutex>
#include <sstream>
#include <future>
#include <tuple>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

// Class Template Auto Deduction

template <typename A, typename B>
struct CA
{
    CA(A a, B b)
    {
        cout << "a = [ " << typeid(a).name() << " ]\n";
        cout << "b = [ " << typeid(b).name() << " ]\n";
    }
    A a;
    B b;
};

template <typename T>
struct S
{
    S(T) { cout << "S T = [" << typeid(T).name() << "]\n"; }
};

int main()
{

    CA<int, double> obj1(111, 1.23);
    CA obj2(111, 12.34);
    line();
    S s(900);

    mutex mute;
    
    return 0;
}