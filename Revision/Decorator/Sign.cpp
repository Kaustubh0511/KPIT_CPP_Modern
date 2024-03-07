#include "Sign.hpp"

void Signature::Send(string msg)
{
    msg = "sign - " + msg + " - sign";
    cout << "Signed : " << msg << "\n";
    Helper::Send(msg);  
}