#include <iostream>
using namespace std;
#define line(msg) cout << "------------" #msg "----------------\n"

template <typename T>
void vendorFun(T obj)
{
    cout << "vendor job started T :[ " << typeid(T).name() << " ]\n";
    int res = obj(25);
    cout << "vendor job completed res :  " << res << "\n";
}
//------------------------------------------------------------------------

int main()
{
    int i = 100;
    int j = 200;
    auto func = [](int par)
    {cout<<"I am from lambda par : " << par << "\n"; return par * 30; };
    vendorFun(func);
    return 0;
}