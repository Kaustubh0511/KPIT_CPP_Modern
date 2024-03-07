#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "MSP.hpp"

class dummy
{
public:
    dummy() {}
    ~dummy() { MSP::release(); }
} dummy;

#endif // DUMMY_HPP
