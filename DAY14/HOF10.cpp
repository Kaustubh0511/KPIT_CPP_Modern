#include <iostream>
#include <tuple>
#include <string>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

struct CB
{
    int a{1000};
    int b{2000};
    int c{3000};
 
    void PrintX(int y) const
    {
        cout<<"x: "<<a+b+c+y<<"\n";
    }
 
    void operator()(int i) const
    {
        cout<<"CB() i = "<<i<<"\n";
    }
};
 
// With simple template
// template<typename T1, typename T2>
// auto GetVal(T1 what, T2 where)
// {
//     return invoke(what, where);
// }
 
// With variadic template // file 103 104 107 file dekhlo for last question

template<typename T1, typename... T2>
auto GetVal(T1 what, T2... where)
{
    return invoke(what, forward<T2>(where)...);
}
 
int main()
{
    CB obj;
    cout<<GetVal(&CB::a, obj)<<"\n";
    cout<<GetVal(&CB::b, obj)<<"\n";
    cout<<GetVal(&CB::c, obj)<<"\n";
 
    GetVal(&CB::PrintX, obj, 123);
    GetVal(obj, 888);
 
    return 0;
}