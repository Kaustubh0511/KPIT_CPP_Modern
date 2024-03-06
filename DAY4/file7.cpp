#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

template <typename T>
T AddFun(T x, T y)
{
    // rtti -> runtime type identification
    cout << "AddFun for T = [" << typeid(T).name() << "]\n";
    return x + y;
}

template <typename T1, typename T2>
T2 SubFun(T1 x, T1 y)
{
    // rtti -> runtime type identification
    cout << "SubFun for T = [" << typeid(T1).name() << "]\t[" << typeid(T2).name() << "]\n";
    return x - y;
}

template <typename T1, typename T2>
auto MulFun(T1 x, T2 y) -> decltype(x + y) // trailing deduce from c++ 11 onwards.
{
    // rtti -> runtime type identification
    cout << "SubFun for T = [" << typeid(T1).name() << "]\t[" << typeid(T2).name() << "]\n";
    return x * y;
}

template <typename T1, typename T2>
auto MulFunNew(T1 x, T2 y) -> decltype(MulFun(x, y))
{
    // rtti -> runtime type identification
    cout << "SubFun for T = [" << typeid(T1).name() << "]\t[" << typeid(T2).name() << "]\n";
    return x * y;
}

template <typename T1, typename T2>
auto MulFunNew14(T1 x, T2 y) // auto return type deduce : c++14
{
    // rtti -> runtime type identification
    cout << "SubFun for T = [" << typeid(T1).name() << "]\t[" << typeid(T2).name() << "]\n";
    return x * y;
}

// template <typename T1, typename T2>
// auto MulFunNew14(T1 x, T2 y) // For mulitple return type , a constraint was introduced to back to the c++ 11 method of trailing deduce.
// {
//     // rtti -> runtime type identification
//     int par = 10;
//     cout << "SubFun for T = [" << typeid(T1).name() << "]\t[" << typeid(T2).name() << "]\n";
//     if (10 == par)
//         return x * y;
//     return x / y;
// }

struct Shubham
{
    char c;
    int x;
    double y;
};

template <int index>
auto getStruct(Shubham &s)
{
    if constexpr (0 == index)
        return s.c;
    else if constexpr (1 == index)
        return s.x;
    else
        return s.y;
}
class CA
{
public:
    CA operator+(const CA &par)
    {
        return CA();
    }
};
int main()
{
    static_assert(std::is_same<double, decltype(MulFun(1.2, 3))>(), "Unexpected type emerged at pune"); // It is a library to check if the return type of mulfun() and the type specified.
    // T is deduced to integer
    int x = AddFun(10, 20);
    // T is deduced to double
    double y = AddFun(1.0, 2.0);
    CA obj;
    CA ob = AddFun(obj, obj);
    line();
    double z = SubFun<int, double>(30, 20);
    auto a = MulFunNew(3.0f, 2.0f);
    line();
    cout << "Type of the auto function : [" << typeid(MulFun(3.0, 2.0f)).name() << "]\n";
    cout << "Type of the auto function : [" << typeid(MulFunNew14(3.0, 2.0f)).name() << "]\n";
    line();
    Shubham sh{'c', 123, 3.14};
    cout << "Type of the auto function : [" << typeid(getStruct<0>(sh)).name() << "]\n";
    cout << "Type of the auto function : [" << typeid(getStruct<1>(sh)).name() << "]\n";
    cout << "Type of the auto function : [" << typeid(getStruct<2>(sh)).name() << "]\n";
    return 0;
}