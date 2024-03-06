#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
    int x;
    int y;

public:
    CA(int x, int y) : x(x), y(y)
    {
        cout << "";
    }
    explicit operator int()
    {
        return x + y;
    }
    explicit operator CA *()
    {
        return this;
    }
    operator void*(){
        return this;
    }
};

int main()
{
    CA obj1(1, 2);
    CA obj2(11, 22);
    line();
    // int a = obj1; // conversion operator or casting operator
    line();
    int b = (int)obj2;
    line();
    CA *pt = (CA *)obj1;
    line();
    void* pt1 = obj2;
    return 0;
}