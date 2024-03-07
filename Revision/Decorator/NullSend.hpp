#ifndef NULLSEND_HPP
#define NULLSEND_HPP

#include "IMsgSend.hpp"
class NullSend : public IMsgSend
{
public:
    void Send(string) override
    {
        // do nothing
    }
    
};

#endif // NULLSEND_HPP
