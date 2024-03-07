#ifndef SIGN_HPP
#define SIGN_HPP

#include "Helper.hpp"
class Signature : public Helper
{
public:
    Signature(IMsgSend *msg_send) : Helper(msg_send) {}
    void Send(string msg) override;
};

#endif // SIGN_HPP
