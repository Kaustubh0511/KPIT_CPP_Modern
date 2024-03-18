#ifndef CA_H
#define CA_H
#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "-----------------\n"

class CA
{
public:
    CA();
    CA(const CA &);
    CA(CA &&);
    void fun();
    template <typename T>
    CA(const T &);
    ~CA();
};

#endif // CA_H
