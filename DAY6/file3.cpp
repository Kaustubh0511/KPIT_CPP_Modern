#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

int main()
{
    int x{10}; // Universal initialization.
    int y{20};
    // int *pt{&x}; // Normal pointer
    // const int *pt{&x}; // pointer to a constant
    // int * const pt{&x}; // constant pointer
    const int * const pt{&x}; // constant pointer to a constant

    // *pt = 99;
    // pt = &y;

    cout << "&x : " << &x << "\n";
    cout << "pt : " << pt << "\n";
    cout << "&y : " << &y << "\n";
    cout << "x : " << x << "\n";
    cout << "y : " << y << "\n";

    return 0;
}