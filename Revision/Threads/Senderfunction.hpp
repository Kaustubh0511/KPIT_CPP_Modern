#ifndef SENDERFUNCTION_HPP
#define SENDERFUNCTION_HPP

#include <string>
#include <map>
#include <future>

using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

void Origin(promise<string> &prm,string msg)
{
    msg = "Origin - " + msg + " - Orgin";
    prm.set_value(msg);
}

#endif // SENDERFUNCTION_HPP
