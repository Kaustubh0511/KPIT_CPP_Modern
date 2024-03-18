#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "LogStitch.hpp"

class Console : public LogStitch
{
public:
    Console(ILogger *ilog) : LogStitch(ilog)
    {
    }
    void log(string msg) override;
};
#endif // CONSOLE_HPP
