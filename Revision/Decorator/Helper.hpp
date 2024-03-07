#ifndef HELPER_HPP
#define HELPER_HPP

#include "IMsgSend.hpp"
class Helper : public IMsgSend
{
    IMsgSend *msg_send;

protected:
    Helper(IMsgSend *msg_send) : msg_send(msg_send)
    {
    }

public:
    void Send(string msg) override;
    virtual ~Helper() { delete msg_send; }
};
#endif // HELPER_HPP
