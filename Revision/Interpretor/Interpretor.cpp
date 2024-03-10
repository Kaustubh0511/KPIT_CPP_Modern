#include "Interpretor.hpp"

void Interpretor::Register(string key, string value)
{
    repo[key] = value;
    repo[value] = key;
}

string Interpretor::GetValue(string key)
{
    return repo[key];
}

void Interpretor::Send(string key)
{
    cout << "Sending " << key << "\t";
    client(GetValue(key));
}
