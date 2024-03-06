#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "---------------------\n";

class CA
{
public:
    CA()
    {
        cout << "Default Constructor\n";
    }
    CA(const CA &par)
    {
        cout << "Copy Constructor\n";
    }
    CA(CA &&par)
    {
        cout << "Move Constructor\n";
    }
    ~CA()
    {
        cout << "Destructor\n";
    }
};

void f1(CA obj)
{
    cout<<"Apple\n";
}

void Wrapper(CA obj){
    cout<<"Hi\n";
    f1(obj);
    cout<<"Bye\n";
}
int main()
{
    CA obj1;
    line();
    Wrapper(obj1);
    line();
    return 0;
}
