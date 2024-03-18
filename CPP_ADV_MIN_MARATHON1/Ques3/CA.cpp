#include "CA.h"

CA::CA()
{
    cout << "CA constructor\n";
}
CA::CA(const CA &obj)
{
    cout << "CA copy constructor\n";
}

void CA::fun()
{
    cout << "I am fun of CA\n";
}
template <typename T>
CA::CA(const T &obj)
{
    cout << "T copy constructor\n";
}

CA::CA(CA &&)
{
    cout << "CA move constructor\n";
}

CA::~CA()
{
    cout << "CA destructor\n";
}