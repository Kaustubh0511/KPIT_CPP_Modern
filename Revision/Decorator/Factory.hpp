#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Encoder.hpp"
#include "Encryptor.hpp"
#include "Sign.hpp"
#include "Helper.hpp"
#include "IMsgSend.hpp"
#include "NullSend.hpp"

IMsgSend *Message_Factory()
{
    return new Encryptor(new Encoder(new Signature(new NullSend())));
}

#endif // FACTORY_HPP
