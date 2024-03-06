#include <iostream>
#include <vector>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

template <typename...>
class MyMethod
{
public:
    void AddFun()
    {
    }
};

// template <>
// class MyMethod<>
// {
// public:
//     void AddFun()
//     {
//     }
// };

template <typename T1, typename... T2>
class MyMethod<T1, T2...> : public MyMethod<T2...>
{
public:
    using MyMethod<T2...>::AddFun;
    void AddFun(T1 x, T1 y)
    {
        cout << "T1 = [" << typeid(T1).name() << "]"
             << "\n";
    }
};

int main()
{
    MyMethod<int, double, float, char> obj;
    obj.AddFun(9, 10);
    obj.AddFun(9.0, 10.0);
    obj.AddFun(9.0f, 10.0f);
    obj.AddFun('a', 'b');
    return 0;
}