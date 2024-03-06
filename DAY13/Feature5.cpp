#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <variant>
#include <map>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

class Product
{
public:
    void showAge()
    {
        cout << "Product::showAge()\n";
    }
};

class Animal
{
public:
    void showAge()
    {
        cout << "Animal::showAge()\n";
    }
};

class Machine
{
public:
    void showAge()
    {
        cout << "Machine::showAge()\n";
    }
};

void DoBusiness(variant<Product, Animal, Machine> v)
{
    cout << "Business Started\n";
    std::visit([](auto obj)
               { obj.showAge(); },
               v);
    cout << "Business Ended\n";
}
int main()
{
    Product p;
    Animal an;
    Machine mn;

    DoBusiness(p);
    DoBusiness(an);
    DoBusiness(mn);
    return 0;
}
