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

// ----------------

void ClientFun(int p1, int p2)
{
    cout << "ClientFun called p1 : " << p1 << " , p2 : " << p2 << "\n";
}

class Wrapper
{
public:
    using FPTR = void (*)(int, int);
    Wrapper(int i, int j, FPTR fp) : i(i), j(j), fp(fp)
    {
    }
    void operator()() const
    {
        fp(i, j);
    }

private:
    int i{0};
    int j{0};
    FPTR fp;
};

int main()
{
    int i = 100;
    int j = 200;
    Wrapper::FPTR fp = &ClientFun;
    Wrapper wp(i, j, fp);
    vendorFun(wp);
    return 0;
}