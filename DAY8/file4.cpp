#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "----------------\n"

/* What ever is above the comments is given to us by the vendor.
Here we have the state of the object stored so we can modify.
 */
class Cvendor
{
public:
    void vendorFun()
    {
        cout << "Vendor Job1 started\n";
        ClientFun();
        cout << "Vendor Job1 completed\n";
    }

protected:
    virtual void ClientFun() = 0;
};
//------------------
class CAT : public Cvendor
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

class DOG : public Cvendor
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

    cat.vendorFun();
    line();
    dog.vendorFun();
    return 0;
}