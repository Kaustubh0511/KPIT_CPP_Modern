#ifndef ENCRYPTOR_HPP
#define ENCRYPTOR_HPP

#include "Helper.hpp"

class Encryptor : public Helper
{
public:
    Encryptor(IMsgSend *msg_send) : Helper(msg_send) {}
    void Send(string msg) override;
    
};

#endif // ENCRYPTOR_HPP
