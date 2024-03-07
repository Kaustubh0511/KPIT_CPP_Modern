#ifndef IMSGSEND_HPP
#define IMSGSEND_HPP

#include <iostream>
#include <string>
using namespace std;
#define line(msg) cout << "--------------" #msg "--------------\n";
class IMsgSend
{
public:
    virtual void Send(string) = 0;
    virtual ~IMsgSend() {}
};

#endif // IMSGSEND_HPP
