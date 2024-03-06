#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
using namespace std;

class Single
{
    friend class Smart_Single;
    static Single *head;

private:
    Single();
    ~Single();
    static Single *make_single();
    static void release();

public:
    void fun1();
    void fun2();
    void fun3();
};
#endif // SINGLETON_H
