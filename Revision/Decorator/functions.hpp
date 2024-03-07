#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Factory.hpp"

void fucntions()
{
    IMsgSend *msg = Message_Factory();
    msg->Send("Kaustubh is the best ");
    delete (msg);
}

#endif // FUNCTIONS_HPP
