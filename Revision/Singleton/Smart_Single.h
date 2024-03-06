#ifndef SMART_SINGLE_H
#define SMART_SINGLE_H

#include "Singleton.h"
#include"Exception.h"
class Smart_Single
{
    Single *s;
    static int count;
    static void* operator new(size_t) = delete;
    static void* operator new[](size_t) = delete;
    static void operator delete(void*) = delete;
    static void operator delete[](void*) = delete;
public:
    explicit Smart_Single();
    Single *operator->();
    int use_count();
    Single &operator*();
    ~Smart_Single();
};

#endif // SMART_SINGLE_H
