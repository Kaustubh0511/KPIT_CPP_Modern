#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include "Interpretor.hpp"
using namespace std;

void Reciever(string msg)
{
    cout << "\t\t : " << msg << "\n";
}

void start()
{
    Interpretor inter(&Reciever);
    string msg1 = "hi";
    string msg1_1 = "Namaste";
    inter.Register(msg1, msg1_1);

    string msg2 = "how are you";
    string msg2_1 = "kaise ho aap";
    inter.Register(msg2, msg2_1);

    string msg3 = "your name";
    string msg3_1 = "aap ka naam";
    inter.Register(msg3, msg3_1);

    string msg4 = "I won't reveal";
    string msg4_1 = "mein nhi bolun";
    inter.Register(msg4, msg4_1);

    inter.Send(msg1);
    inter.Send(msg2);
    inter.Send(msg3_1);
    inter.Send(msg4_1);
}

#endif // FUNCTIONS_HPP
