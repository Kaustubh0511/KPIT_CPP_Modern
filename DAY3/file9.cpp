#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

// technique handle-body
struct Handle
{
    int *a;
    int count;
};
class CA
{
    Handle *handle;

public:
    CA(int val) : handle(new Handle{new int(val), 1})
    {
        cout << "CA constructor a : [" << handle->a << "]\n";
    }
    CA(const CA &par) : handle(par.handle) // copy constructor
    {
        ++(handle->count);
        cout << "CA Shallow Copy a : [" << handle->a << "] " << handle->count << "\n";
    }
    CA &operator=(const CA &par)
    {
        if (this == &par) // Check if it is not this situation obj1 = obj1
            return *this;
        cout << "CA Shallow Assignment a : [" << handle->a << "]\n";
        // copy and swap
        CA temp(par);
        // std::swap(this->a, temp.a); // using swap function directly
        this->Swap(temp); // using a swap function that we defined
        return *this;
    }
    void Swap(CA &tmp) // swap function is mentioned
    {
        std::swap(handle, tmp.handle);
    }
    ~CA()
    {
        cout << "CA destructor a : [" << handle->a << "]\n";
        --(handle->count);
        if ((handle->count) == 0)
        {
            cout << "CA actually releases a : [" << handle->a << "]\n";
            delete handle->a;
            delete handle;
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
    obj1_3 = obj2; // Every time an assignment operator are called*/
    line(Before);
    return 0;
}