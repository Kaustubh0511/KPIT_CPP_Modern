#ifndef BASESTACK_HPP
#define BASESTACK_HPP
#include <iostream>
using namespace std;
#define line(msg) cout << "------------" #msg "-----------\n";

class BaseStack
{
    int _size;

protected:
    BaseStack(int size) : _size(size)
    {
    }
    int top = -1;

public:
    bool isEmpty();
    bool isFull();
};

#endif // BASESTACK_HPP
