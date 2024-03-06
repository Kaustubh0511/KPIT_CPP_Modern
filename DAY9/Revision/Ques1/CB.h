#ifndef CB_H
#define CB_H

#include <iostream>
using namespace std;
// #define line(msg) "------------" #msg "-----------------\n";

class CB
{
    int b{0};
public:
    CB();
    CB(const CB&);
    CB(CB&&);
    CB(int);
    ~CB();
};

#endif // CB_H
