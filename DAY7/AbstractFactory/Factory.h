#ifndef FACTORY_H
#define FACTORY_H
// #include "file1.h";
#include "IE.h"
#include "Chrome.h"
#include "Opera.h"


class FactoryDecider
{
    public:
    static IFactory* getFactoy(int choice = 10);
};
#endif // FACTORY_H
