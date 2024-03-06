#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
public:
    virtual void fun()
    {
        cout << "Apple\n";
    }
};

class CB : public CA
{
public:
    void fun()
    {
        cout << "Orange\n";
    }
};

int main()
{
    int par = 10;
    try
    {
        CB obcb;
        if (10 == par)
        {
            throw *(new CB());
        }
    }
    catch(CB& ob){
        cout<<"Palak\n";
        ob.fun();
    }
    catch (CA& ob)
    {
        ob.fun();
    }
    return 0;
}