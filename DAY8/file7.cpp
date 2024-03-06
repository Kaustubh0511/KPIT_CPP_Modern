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

//------------------- &c = c2
using FPTR = void (*)();
void ClientFun()
{
    cout << "Hi I am from client\n";
}
void Fun()
{
    cout << "Haaaaa\n";
}

class CA
{
    int a{0};
    int b{0};

public:
    CA(int a, int b) : a(a), b(b)
    {
    }
    void operator()()
    {
        cout << "CA Client Code a : " << a << " , b : " << b << "\n";
    }
};
int main()
{
    FPTR fp1 = ClientFun;
    FPTR fp2 = Fun;

    vendorFun(fp1);
    line();
    vendorFun(fp2);
    line();
    CA obj(11, 22);
    vendorFun(obj);
    line();
    return 0;
}