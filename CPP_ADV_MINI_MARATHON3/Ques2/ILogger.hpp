#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <iostream>
using namespace std;
#define line(msg) cout << "---------------" #msg "------------------\n"

class ILogger
{
public:
    virtual void log(string) = 0;
};

#endif // ILOGGER_HPP
