#ifndef CA_H
#define CA_H

#include <iostream>
using namespace std;
#define line(msg) cout << "------------" #msg "------------\n"
class CA
{
private:
    int a{0};

public:
    CA();
    CA(const CA &);
    template<typename T>
    CA(const T&);
    CA(CA &&);
    void fun();
    ~CA();
};
#endif // CA_H
