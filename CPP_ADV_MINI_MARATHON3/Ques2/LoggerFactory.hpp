#ifndef LOGGERFACTORY_HPP
#define LOGGERFACTORY_HPP

#include "ILogger.hpp"
class LoggerFactory
{
public:
    static ILogger *CreateLoggers();
};

#endif // LOGGERFACTORY_HPP
