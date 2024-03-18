#ifndef START_HPP
#define START_HPP

#include "ILogger.hpp"
#include "Console.hpp"
#include "File.hpp"
#include "Service.hpp"
#include "NullLogger.hpp"
void Start(ILogger *logger)
{
    logger->log("Add Product");
}

#endif // START_HPP
