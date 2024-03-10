#ifndef SMART_SINGLE_H
#define SMART_SINGLE_H

#include "Singleton.h"
#include "Exception.h"
// #include <functional>
class Smart_Single
{
    Single *s;
    static int count;
    static void *operator new(size_t) = delete;
    static void *operator new[](size_t) = delete;
    static void operator delete(void *) = delete;
    static void operator delete[](void *) = delete;

public:
    using FPTR = void (Single::*)();
    explicit Smart_Single();
    Single *operator->();
    int use_count();
    Single &operator*();
    Smart_Single &operator->*(FPTR fp);
    void operator()()
    {
        (s->*fp)();
    }
    ~Smart_Single();

private:
    FPTR fp{nullptr};
};

#endif // SMART_SINGLE_H
