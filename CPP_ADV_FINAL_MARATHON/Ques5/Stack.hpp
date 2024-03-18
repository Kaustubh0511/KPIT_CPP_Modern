#ifndef STACK_HPP
#define STACK_HPP
#include "BaseStack.hpp"

template <typename T, int size>
class Stack : public BaseStack
{
    T arr[size];

public:
    Stack() : BaseStack(size)
    {
        cout << "Not specialized\n";
    }
    void Push(T val)
    {
        arr[++top] = val;
    }
    T Pop()
    {
        return arr[top--];
    }
    T Peek()
    {
        return arr[top];
    }
};

template <int size>
class Stack<int, size> : public BaseStack
{
    int arr[size];

public:
    Stack() : BaseStack(size)
    {
        cout << "Specialized for Integer\n";
    }
    void Push(int val)
    {
        arr[++top] = val;
    }
    int Pop()
    {
        return arr[top--];
    }
    int Peek()
    {
        return arr[top];
    }
};

template <typename T, int size>
class Stack<T *, size> : public BaseStack
{
    T *arr[size];

public:
    Stack() : BaseStack(size)
    {
        cout << "Partial specialized for pointers T = [" << typeid(T).name() << "]\n";
    }
    void Push(T *val)
    {

        arr[++top] = val;
    }
    T Pop()
    {
        return *arr[top--];
    }
    T Peek()
    {
        return *arr[top];
    }
};

#endif // STACK_HPP
