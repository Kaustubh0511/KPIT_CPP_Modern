#include "BaseStack.hpp"

bool BaseStack::isEmpty()
{
    return top == -1;
}

bool BaseStack::isFull()
{
    return top == _size;
}
