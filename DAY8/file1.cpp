#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "----------------\n"

/* What ever is above the comments is given to us by the vendor.
Here the state of the function is not available as the function is created.
 */

void vendorFun(void (*fp)())
{
    cout << "Vendor Job started\n";
    // client code
    //(*fp)(); // Callback is happening here // Syntax of c
    fp(); // Cpp syntax and callback is happening here.
    cout << "Vendor Job completed\n";
}

// typedef void (*FPTR)(); // Old cpp
using FPTR = void(*)(); // Feature of cpp11 onwards.
void vendorFun1(FPTR fp)
{
    cout << "Vendor Job1 started\n";
    fp(); // Cpp syntax and callback is happening here.
    cout << "Vendor Job1 completed\n";

}
//------------------

void ClientFun()
{
    cout << "Hi I am client function\n";
}
void Fun()
{
    cout << "Haaaaaaaa\n";
}
void Fun1()
{
    cout << "Heeeeeeeee\n";
}
int main()
{
    void (*fp1)() = &ClientFun;
    void (*fp2)() = ClientFun;

    vendorFun(fp1);
    line();
    vendorFun(fp2);
    line();
    vendorFun(&Fun);
    line();
    vendorFun(Fun1);
    line();
    line();
    vendorFun1(fp1);
    line();
    vendorFun1(fp2);
    line();
    vendorFun1(&Fun);
    line();
    vendorFun1(Fun1);
    line();
    return 0;
}