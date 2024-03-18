#include "Console.hpp"

void Console::log(string msg)
{
    LogStitch::log(msg);
    msg = "Console Logger logged [ " + msg + "]";
    cout << msg << "\n";
}
