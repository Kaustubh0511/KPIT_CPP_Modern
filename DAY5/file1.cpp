#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"
// g++ -fno-elide-constructors
/* Rvalue object is a middle man
Lvalue Object is the object that we create
*/
class CA
{
    int *a;

public:
    CA() : a(new int(1000))
    {
        cout << "Constructor a = [" << a << "]\n";
    }
    CA(const CA &obj) : a(new int(*obj.a))
    {
        cout << "Deep Copy a = [" << a << "]\n";
    }
    CA(CA &&par) : a(par.a) // Shallow copy // This is the move constructor that gives the address of the Rvalue.
    {
        //this  == RValue object.
        // Par === temp object from factory.
        par.a = NULL;
        cout << "Move constructor a =[" << a << "]\n";
    }
    ~CA()
    {
        cout << "Destructor a = [" << a << "]\n";
        delete a;
    }
};

CA Factory()
{
    CA temp;
    cout << "DoBusiness\n";
    return temp;
}
int main()
{
    CA obj = Factory();
    line();
    CA obj1(obj);
    line();
    return 0;
}