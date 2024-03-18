#include "Start.hpp"
#include "LoggerFactory.hpp"

ILogger *LoggerFactory::CreateLoggers()
{
    return new Console(new Service(new File(new NullLogger())));
}

int main()
{
    Start(LoggerFactory::CreateLoggers());
    return 0;
}