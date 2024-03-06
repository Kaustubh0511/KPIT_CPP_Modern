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
        cout << "this : [" << this << "]\n";
        cout << "x : [" << &x << "]\n";
        cout << "y : [" << &y << "]\n";
    }
    void *operator&()
    {
        return &y;
    }
};

int main()
{
    CA obj(10, 20);
    line();
    cout << "&obj : [" << &obj << "]\n";
    cout << "addressof(obj) : [  " << addressof(obj) << "]\n";
    return 0;
}