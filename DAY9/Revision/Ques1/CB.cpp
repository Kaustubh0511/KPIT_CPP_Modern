#include "CB.h"

CB::CB()
{
    cout << "CB constructor\n";
}

CB::CB(const CB &)
{
    cout << "CB copy constructor\n";
}

CB::CB(CB &&)
{
    cout << "CB move constructor\n";
}
CB::CB(int)
{
    cout << "CB(int)\n";
}

CB::~CB()
{
    cout << "CB destructor\n";
}
