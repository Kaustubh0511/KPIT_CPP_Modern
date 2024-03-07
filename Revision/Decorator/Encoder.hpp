#ifndef ENCODER_HPP
#define ENCODER_HPP

#include "Helper.hpp"
class Encoder : public Helper
{
public:
    Encoder(IMsgSend *msg_send) : Helper(msg_send) {}
    void Send(string msg) override;
    
};

#endif // ENCODER_HPP
