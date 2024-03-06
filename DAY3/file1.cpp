#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
    int x = 10;

public:
    explicit CA(int x) : x(x)
    {
        cout << "One param constructor\n";
    }
    void Display()
    {
        cout << "Value of X is : " << x << endl;
    }
    CA& operator=(const CA& par){
        cout<<"Assignment\n";
        this->x = par.x;
        return *this;
    }
};

void f1(CA par){

}
int main()
{
    /*CA obj1(100);// construction
    // obj1.Display();
    line();
    CA obj2 = 200;// conversion
    // obj2.Display();
    line();
    obj1 = 300; // conversion and then assignment
    // obj1.Display();
    line();*/

    //f1(10);//error on explicit constructor
    f1(CA(100));
    return 0;
}