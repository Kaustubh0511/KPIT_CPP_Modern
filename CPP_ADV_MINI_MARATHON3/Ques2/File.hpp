#ifndef FILE_HPP
#define FILE_HPP

#include "LogStitch.hpp"

class File : public LogStitch
{
public:
    File(ILogger *ilog) : LogStitch(ilog)
    {
    }
    void log(string msg) override;
};
#endif // FILE_HPP
