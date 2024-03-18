#include "Service.hpp"

void Service::log(string msg)
{
    LogStitch::log(msg);
    msg = "Service Logger logged [ " + msg + "] ";
    cout << msg << "\n";
}