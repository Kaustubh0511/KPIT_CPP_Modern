#include "Encoder.hpp"

void Encoder::Send(string msg)
{
    msg = "encode - " + msg + " - encode";
    cout << "Encode : " << msg << "\n";
    Helper::Send(msg);
}