#ifndef NULLLOGGER_HPP
#define NULLLOGGER_HPP

#include "ILogger.hpp"

class NullLogger : public ILogger
{
public:
    NullLogger() {}
    void log(string) override
    {
        // Do nothing
    }
};

#endif // NULLLOGGER_HPP
