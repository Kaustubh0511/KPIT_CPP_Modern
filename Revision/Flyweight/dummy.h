#ifndef DUMMY_H
#define DUMMY_H

#include "MSP.h"

class dummy
{
public:
    dummy() {}
    ~dummy() { MSP::release(); }
} dummy;

#endif // DUMMY_H
