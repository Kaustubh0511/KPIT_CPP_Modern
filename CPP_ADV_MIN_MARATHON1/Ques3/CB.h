#ifndef CB_H
#define CB_H
#include<iostream>
using namespace std;
class CB
{
    public:
    CB();
    CB(const CB&);
    CB(CB&&);
    void fun();
    template<typename T>
    CB(const T&);
    ~CB();

};

#endif // CB_H
