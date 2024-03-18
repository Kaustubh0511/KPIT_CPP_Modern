#include "File.hpp"

void File::log(string msg)
{
    LogStitch::log(msg);
    msg = "File Logger logged [ " + msg + "]";
    cout << msg << "\n";
}
