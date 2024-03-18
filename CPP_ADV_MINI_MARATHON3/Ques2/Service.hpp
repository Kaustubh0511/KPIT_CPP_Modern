#ifndef SERVICE_HPP
#define SERVICE_HPP

#include "LogStitch.hpp"

class Service : public LogStitch
{
public:
    Service(ILogger *ilog) : LogStitch(ilog)
    {
    }
    void log(string msg) override;
};

#endif // SERVICE_HPP
