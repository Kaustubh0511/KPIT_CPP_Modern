#include "CB.h"

CB::CB()
{
    cout << "Default Constructor\n";
}

CB::CB(const CB &obj)
{
    cout << "Copy Constructor\n";
}

CB::CB(CB &&)
{
    cout << "Move Constructor\n";
}

void CB::fun()
{
    cout << "I am fun of CB\n";
}

template <typename T>
CB::CB(const T &)
{
    cout << "T copy constructor\n";
}

CB::~CB()
{
}