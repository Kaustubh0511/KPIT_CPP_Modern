#include "Singleton.h"

Single::Single()
{
    cout << "Singleton Constructor\n";
}

Single::~Single()
{
    cout << "Singleton Destructor\n";
}

void Single::fun1()
{
    cout << "Singleton::fun1()\n";
}
void Single::fun2()
{
    cout << "Singleton::fun2()\n";
}
void Single::fun3()
{
    cout << "Singleton::fun3()\n";
}
