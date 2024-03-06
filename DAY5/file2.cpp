#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"
// g++ -fno-elide-constructors
/* Rvalue object is a middle man
Lvalue Object is the object that we create
Lvalue referece cannot access Rvalue object.
Move does shollow copy with ownership transfer.
*/
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
void f1(CA obj) // Here we have lvalue object only
{
    cout << "Apple\n";
}

void f2(CA &obj) // Here we have lvalue reference
{
    cout << "Orange\n";
}

void f3(CA &&obj) //Here we have Rvalue Reference
{
    cout << "Mango\n";
}
int main()
{
    CA obj;// Default Constructor.
    line();
    f1(obj); // Copy is called & Apple is printed.
    line();
    f2(obj); // Nothing is called & only orange is printed
    line();
    f1(std::move(obj)); // Move is called & Apple is printed
    line();
    // f2(std::move(obj)); // Error is produced because rvalue reference cannot access lvalue refernce
    line();
    // f3(obj); // Error is produced because lvalue object cannot access rvalue refernce
    line();
    f3(std::move(obj)); // Only mango is printed.
    line();
    return 0; //Destructor is called.
}