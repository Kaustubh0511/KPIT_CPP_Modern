#include <iostream>
#include <vector>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

class CA
{
private:
    int a{100};

protected:
    int b{200};

public:
    int c{300};
    void DisplayCA()
    {
        cout << "CA::Display\n";
        cout << "a = " << a << "\n";
        cout << "b = " << b << "\n";
        cout << "c = " << c << "\n";
    }
    friend class CB_Pub_friend; // vertical Access Control
};

class CB_Pub_friend : public CA
{
public:
    void DisplayCB_Pub_friend()
    {
        cout << "CB_Pub_friend::Display\n";
        cout << "a = " << a << "\n";
        cout << "b = " << b << "\n";
        cout << "c = " << c << "\n";
    }
};

class CB_Pub : public CA
{
private:
    using CA::b; // Vertical Access Control.
protected:
    using CA::c; // Using keyword is optional.

public:
    void DisplayCB_Pub()
    {
        cout << "CB_Pub_friend::Display\n";
        // cout << "a = " << a << "\n"; //inaccessible.
        cout << "b = " << b << "\n";
        cout << "c = " << c << "\n";
    }
};

class CB_Pub_Derived : public CB_Pub
{
public:
    void DisplayCB_Pub_Derived()
    {
        cout << "CB_Pub_Derived::Display\n";
        // cout << "b = " << b << "\n"; // Error inacessible.
        cout << "c = " << c << "\n";
    }
};

class CB_Prot : protected CA
{
private:
    using CA::b;

public:
    using CA::c;
    void DisplayCB_Prot()
    {
        cout << "CB_Pub_Derived::Display\n";
        cout << "b = " << b << "\n";
        cout << "c = " << c << "\n";
    }
};

class CB_Pvt : private CA
{
public:
    using CA::c;
    void DisplayCB_Prot()
    {
        cout << "CB_Pub_Derived::Display\n";
        cout << "c = " << c << "\n";
    }
};

int main()
{
    line(CA);
    CA obj1;
    obj1.c = 999;
    obj1.DisplayCA();
    line(CB_Pub_friend);
    CB_Pub_friend obj2;
    obj2.c = 88;
    obj2.DisplayCA();
    obj2.DisplayCB_Pub_friend();
    line(CB_Pub_Derived);
    CB_Pub_Derived obj3;
    // obj3.c = 98; // error inacessible.
    obj3.DisplayCA();
    obj3.DisplayCB_Pub();
    obj3.DisplayCB_Pub_Derived();
    return 0;
}