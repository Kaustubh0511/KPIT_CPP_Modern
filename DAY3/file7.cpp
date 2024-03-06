#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
    int *a;

public:
    CA(int val) : a(new int(val))
    {
        cout << "CA constructor a : [" << a << "]\n";
    }
    // Ownership transfer
    CA(const CA &par) : a(par.a)
    {
        CA &caRef = const_cast<CA &>(par); // const casting
        caRef.a = NULL;                    // transferring the ownership to obj2.
        cout << "CA Shallow Copy a : [" << a << "]\n";
    }
    /*CA &operator=(const CA &par)
    {
        if(this == &par) // Check if it is not this situation obj1 = obj1
            return *this;
        cout << "CA Shallow Assignment a : [" << a << "]\n";
        // delete a;
        // a = par.a;
        // CA& caRef = const_cast<CA&>(par); // const casting
        // caRef.a =NULL; // transferring the ownership to obj2.
        this->CA::~CA();
        // this->CA::CA(par); // works only in vc++
        return *this;
    }*/
    CA &operator=(const CA &par)
    {
        if (this == &par) // Check if it is not this situation obj1 = obj1
            return *this;
        cout << "CA Shallow Assignment a : [" << a << "]\n";
        //copy and swap
        CA temp(par);
        // std::swap(this->a, temp.a); // using swap function directly
        this->Swap(temp); // using a swap function that we defined
        return *this;
    }
    void Swap(CA& tmp) // swap function is mentioned
    {
        std::swap(this->a, tmp.a);
    }
    ~CA()
    {
        cout << "CA destructor a : [" << a << "]\n";
        delete a;
    }
};

int main()
{
    CA obj1(100);
    CA obj2 = obj1;
    line();
    obj1 = obj2;
    return 0;
}