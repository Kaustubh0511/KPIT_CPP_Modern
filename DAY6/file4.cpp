#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

void f1(const int *pt)
{
    int *p = const_cast<int *>(pt);
    *p = 999;
    cout << "*p = " << *p << "\n";
}
int main()
{
    int x = 10;
    const int y = 20;

    f1(&x);
    f1(&y);

    cout << "x : " << x << "\n";
    cout << "y : " << y << "\n";
    return 0;
}