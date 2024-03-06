#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

// name decoration/name mangling
/* Rule :-
1. name of function
2. namespace of the function
3. class of the function.
 */
void fun()
{
}

void fun(int)
{
}

void fun(int, int)
{
}

extern "C++" void fun1() // naming convention
{
}
extern "C" void fun1()
{
}

constexpr int fib(int n) // this will help it run at compile time. // donot put cout as it runs in compile time and we want it to run at compile time.
{
    return (n < 2) ? n : (fib(n - 1) + fib(n - 2));
}
template <int num>
class Stack
{
};
//----------------------------------------------------
int main1()
{
    fun();
    fun(10);
    fun(10, 20);
    // fun1();
    int arr[10];
    int arr1[fib(5)];
    Stack<5> stk1;
    Stack<fib(3)> stk2;
    int k = 10;
    int h = fib(k);
    return 0;
}

// UDL -> user defined literals
constexpr long double operator"" _rad(long double deg) // This is now working compile time.
{
    return 3.14159 / 180.0 * deg;
}

int main2()
{
    constexpr long double angle = 90.0_rad; // This is working at compile time.
    cout << angle << '\n';
    return 0;
}
template <int index>
void GetMe()
{
    cout << "Apple\n";
    if constexpr (0 == index)
    {
        cout << "Bhindi\n";
    }
    else if constexpr (1 == index)
    {
        cout << "Palak\n";
    }
    else
    {
        cout << "Bottle Gourd\n";
    }
    cout << "Orange\n";
}

int main()
{
    GetMe<0>();
    GetMe<1>();
    GetMe<2>();
    return 0;
}
