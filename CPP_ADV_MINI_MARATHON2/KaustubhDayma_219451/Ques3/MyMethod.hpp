#include <iostream>
#include <vector>
using namespace std;

template <typename...>
class MyMethod
{
public:
    void AddFun()
public:
    void AddFun()
    {
    }
};

template <typename T1, typename... T2>
class MyMethod<T1, T2...> : public MyMethod<T2...>
{
public:
    using MyMethod<T2...>::AddFun;
    void AddFun(T1 x, T1 y)
    {
        cout << "T1 = [" << typeid(T1).name() << "] & the sum is : " << x + y << "\n";
    }
};