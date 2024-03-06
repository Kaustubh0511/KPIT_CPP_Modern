#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "----------------\n"

class CVendor
{
    int x{0};
    int y{0};

public:
    CVendor(int a, int b) : x(a), y(b)
    {
    }
    void f1()
    {
        cout << "CVendor f1 called x : " << x << ", y : " << y << "\n";
    }
    void f2()
    {
        cout << "CVendor f2 called x : " << x << ", y : " << y << "\n";
    }
};

using FPTR = void (CVendor::*)();
void vendorFun(CVendor &cv, FPTR fp)
{
    cout << "vendor job started\n";
    (cv.*fp)(); // member function callback.
    cout << "vendor job completed\n";
}
//-----------------------
int main()
{
    CVendor c1(11, 22);
    CVendor c2(100, 200);

    FPTR fp1 = &CVendor ::f1;
    FPTR fp2 = &CVendor ::f2;

    vendorFun(c1, fp1);
    line();
    vendorFun(c2, fp1);
    line();
    vendorFun(c1, fp2);
    line();
    vendorFun(c2, fp2);
    line();

    return 0;
}