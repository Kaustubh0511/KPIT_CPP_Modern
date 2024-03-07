#include "Factory.h"

IFactory *FactoryDecider::getFactoy(int choice)
{
    if (10 == choice)
    {
        return new IEFactory();
    }
    else if (20 == choice)
    {
        return new ChromeFactory();
    }
    // return new OperaFactory();
    return nullptr;
}