#include "Encryptor.hpp"

void Encryptor::Send(string msg)
{
    msg = "ency - " + msg + " - ency";
    cout << "Encrypted : " << msg << "\n";
    Helper::Send(msg);
}
