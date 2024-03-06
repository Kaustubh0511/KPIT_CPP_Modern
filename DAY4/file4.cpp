#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
public:
    void fun()
    {
        cout << "Apple\n";
    }
};

class Smart_Ptr
{
    CA *ptr;
public:
    Smart_Ptr(CA *pt = NULL) : ptr(pt) 
    {
    }
    void fun()
    {
        cout << "Orange\n";
    }
    CA *operator->() // This is overloaded becuase we have to use the function class CA.
    {
        return ptr;
    }
};

int main()
{
    Smart_Ptr *sm = new Smart_Ptr(new CA());
    sm->fun();
    (*sm)->fun();
    return 0;
}