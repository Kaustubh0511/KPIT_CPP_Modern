#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "----------------\n"

/* What ever is above the comments is given to us by the vendor.
Here we have the state of the object stored so we can modify.
 */

// typedef void (*FPTR)(); // Old cpp
class IClient
{
public:
    virtual void ClientFun() = 0;
};
void vendorFun(IClient *ic)
{
    cout << "Vendor Job1 started\n";
    ic->ClientFun();
    cout << "Vendor Job1 completed\n";
}
//------------------
class CAT : public IClient
{
    int a{0};
    int b{0};

public:
    CAT(int a, int b) : a(a), b(b)
    {
    }
    void ClientFun() override
    {
        cout << "Cat is called a : " << a << " , b : " << b << "\n";
    }
};

class DOG : public IClient
{
    int a{0};

public:
    DOG(int a, int b) : a(a + b)
    {
    }
    void ClientFun() override
    {
        cout << "Dog is called a : " << a << "\n";
    }
};
int main()
{
    CAT cat(11, 22);
    DOG dog(44, 55);

    vendorFun(&cat);
    line();
    vendorFun(&dog);
    return 0;
}