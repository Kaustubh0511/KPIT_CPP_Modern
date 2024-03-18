#ifndef SMARTSINGLE_HPP
#define SMARTSINGLE_HPP

#include "GatewaySecurity.hpp"
#include "Exception.hpp"

class SmartSingle
{
    GatewaySecurity *gws;
    static int count;

    static void *operator new(size_t) = delete;
    static void *operator new[](size_t) = delete;
    static void operator delete(void *) = delete;
    static void operator delete[](void *) = delete;

public:
    static int id;
    using FPTR = void (GatewaySecurity::*)(int);
    explicit SmartSingle();
    GatewaySecurity *operator->();
    int use_count();
    GatewaySecurity &operator*();
    SmartSingle &operator->*(FPTR fp);
    void operator()()
    {
        (gws->*fp)(id);
    }
    ~SmartSingle();

private:
    FPTR fp{nullptr};
};

#endif // SMARTSINGLE_HPP
