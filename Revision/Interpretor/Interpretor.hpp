#ifndef INTERPRETOR_HPP
#define INTERPRETOR_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
using namespace std;

using FPTR = std::function<void(string)>;
class Interpretor
{
    map<string, string> repo;
    FPTR client;

public:
    Interpretor(FPTR client) : client(client)
    {
    }
    void Register(string key, string value);
    string GetValue(string key);
    void Send(string key);
};

#endif // INTERPRETOR_HPP
