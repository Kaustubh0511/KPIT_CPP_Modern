#include"Car.h"

class Dummy
{
public:
    Dummy()
    {
        VendorRepository::Enroll(new Vendor("OLA", 2));
        VendorRepository::Enroll(new Vendor("Uber", 4));
        VendorRepository::Enroll(new Vendor("Rapido", 5));
        VendorRepository::Enroll(new Vendor("IRTC", 1.6));
        VendorRepository::Enroll(new Vendor("FabHotels", 2.5));
    }
}dummy;

void Test()
{
    Helper hl;
    try
    {
        hl.Subscribe(new Car(101,4,50,"Uber"));
    }
    catch(const char* e)
    {
        std::cout << e << '\n';
    }
    try
    {
        hl.Subscribe(new Car(102,4,50,"OLA"));
    }
    catch(const char* e)
    {
        std::cout << e << '\n';
    }
    try
    {
        hl.Subscribe(new Car(103,4,50,"Rapido"));
    }
    catch(const char* e)
    {
        std::cout << e << '\n';
    }
    try
    {
        hl.Subscribe(new Car(104,4,50,"IRTC"));
    }
    catch(const char* e)
    {
        std::cout << e << '\n';
    }
    try
    {
        hl.Subscribe(new Car(105,4,50,"FabHotels"));
    }
    catch(const char* e)
    {
        std::cout << e << '\n';
    }
    
    hl.List();
std::cout<<"\n________________________________________________\n";
    hl.Unsubscribe(104);

    hl.List();
std::cout<<"\n________________________________________________\n";
    hl.List("OLA");
    
    
    
}


int main()
{
    Test();
}