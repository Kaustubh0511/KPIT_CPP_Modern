#ifndef LOGSTITCH_HPP
#define LOGSTITCH_HPP

#include "ILogger.hpp"
class LogStitch : public ILogger
{
    ILogger *msg_send;

public:
    LogStitch(ILogger *msg_send) : msg_send(msg_send)
    {
    }
    void log(string msg) override;
};

#endif // LOGSTITCH_HPP
