#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

// Reference Counting.
class CA
{
    int *a;
    int *count;

public:
    CA(int val) : a(new int(val)), count(new int(1))
    {
        cout << "CA constructor a : [" << a << "]\n";
    }
    CA(const CA &par) : a(par.a), count(par.count)
    {
        ++(*count);
        cout << "CA Shallow Copy a : [" << a << "]\n";
    }
    CA &operator=(const CA &par)
    {
        if (this == &par) // Check if it is not this situation obj1 = obj1
            return *this;
        cout << "CA Shallow Assignment a : [" << a << "]\n";
        // copy and swap
        CA temp(par);
        // std::swap(this->a, temp.a); // using swap function directly
        this->Swap(temp); // using a swap function that we defined
        return *this;
    }
    void Swap(CA &tmp) // swap function is mentioned
    {
        std::swap(this->a, tmp.a);
        std::swap(this->count, tmp.count);
    }
    ~CA()
    {
        cout << "CA destructor a : [" << a << "]\n";
        --(*count);
        if ((*count) == 0)
        {
            cout << "CA actually releases a : [" << a << "]\n";
            delete a;
            delete count;
        }
    }
};

int main()
{
    CA obj1(100);    // Object was created and the a pointer and count pointer were created
    CA obj1_2(obj1); // Here a shallow copy is being created
    CA obj1_3(obj1); // Here a shallow copy is being created
    line();
    CA obj2(200);    // Object was created and the a pointer and count pointer were created
    CA obj2_2(obj2); // Here a shallow copy is being created
    CA obj2_3(obj2); // Here a shallow copy is being created
    line();
    obj1 = obj2;   // Every time an assignment operator are called
    obj1_2 = obj2; // Every time an assignment operator are called
    obj1_3 = obj2; // Every time an assignment operator are called
    line(Before);
    return 0;
}