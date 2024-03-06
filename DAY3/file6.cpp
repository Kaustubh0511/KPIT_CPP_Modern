#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------"#msg"----------------\n"
//DTO /value-object

class CA
{
    int *a;

public:
    CA(int val) : a(new int(val))
    {
        cout << "CA constructor a : [" << a << "]\n";
    }
    CA(const CA &par) : a(new int(*par.a))
    {
        cout << "CA deep Copy a : [" << a << "]\n";
    }
    CA &operator=(const CA &par)
    {
        cout << "CA Deep Assignment a : [" << a << "]\n";
        *a = *par.a;
        return *this;
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
    line();
    // CA obj2(200);
    CA obj2 = obj1;
    line();
    obj1 = obj2;
    line();
    return 0;
}