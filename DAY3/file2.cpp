#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
    int x;
    int y;

public:
    CA(int x) : x(x),y(y)
    {
        cout << "One param constructor\n";
    }
    CA(int x,int y) : x(x),y(y)
    {
        cout << "Two param constructor\n";
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
    CA obj1(100);// construction
    obj1.Display();
    line();
    CA obj2 = 100;//Conversion
    line();
    CA obj3(100,200);
    line();
    CA obj4 = (111,222);
    line();
    obj1 = 234;
    line();
    obj1 = (22,33);
    line(Brace Initialisation);
    int x{10};
    int y = {20};
    CA obj5 {100};//construction
    line();
    CA obj6 = {10}; //Conversion
    line();
    CA obj7 {10,20};//Conversion
    line();
    CA obj8 = {131,242};//Conversion
    line();
    obj1 = {100}; //Conversion and assignment
    line();
    obj1 = {1,2}; //Conversion and assignment
    line();
    return 0;
}