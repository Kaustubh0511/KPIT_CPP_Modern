#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "----------------\n"

// CRTP -> curiously recuring template pattern (Idiom of cpp)
/* Fast runtime as everthing is resolved at compile time.
Drawback -> Every time a new base class is being created
         -> Size will increase .
*/
template <typename T>
class Cvendor
{
public:
    void vendorFun()
    {
        cout << "Vendor Job1 started\n";
        ((T *)this)->ClientFun();
        cout << "Vendor Job1 completed\n";
    }
};
//------------------
class CAT : public Cvendor<CAT>
{
    int a{0};
    int b{0};

public:
    CAT(int a, int b) : a(a), b(b)
    {
    }
    void ClientFun()
    {
        cout << "Cat is called a : " << a << " , b : " << b << "\n";
    }
};

class DOG : public Cvendor<DOG>
{
    int a{0};

public:
    DOG(int a, int b) : a(a + b)
    {
    }
    void ClientFun()
    {
        cout << "Dog is called a : " << a << "\n";
    }
};
int main()
{
    CAT cat(11, 22);
    DOG dog(44, 55);

    cat.vendorFun();
    line();
    dog.vendorFun();
    return 0;
}