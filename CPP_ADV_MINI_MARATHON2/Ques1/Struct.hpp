#ifndef STRUCT_HPP
#define STRUCT_HPP
#include <iostream>
using namespace std;

struct CB
{
    int a{1000};
    int b{2000};
    int c{3000};

    void PrintX(int y) const
    {
        cout << "PrintX x : " << a + b + c + y << "\n";
    }
    void operator()(int i) const
    {
        cout << "CB() i = " << i << '\n';
    }
};

#endif // STRUCT_HPP
