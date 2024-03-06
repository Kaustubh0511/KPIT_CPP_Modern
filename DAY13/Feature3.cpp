#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <variant>
#include <map>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

class CAT
{
public:
    CAT()
    {
        cout << "CAT()\n";
    }
    void catFun()
    {
        cout << "CAT::catFun()\n";
    }
    ~CAT()
    {
        cout << "~CAT()\n";
    }
};

class DOG
{
public:
    DOG()
    {
        cout << "DOG()\n";
    }
    void dogFun()
    {
        cout << "DOG::dogFun()\n";
    }
    ~DOG()
    {
        cout << "~DOG()\n";
    }
};

class OX
{
public:
    OX()
    {
        cout << "OX()\n";
    }
    void oxFun()
    {
        cout << "OX::oxFun()\n";
    }
    ~OX()
    {
        cout << "~OX()\n";
    }
};
class Smart
{
    map<int, std::function<void(variant<CAT, DOG, OX> &)>> repo;

public:
    Smart()
    {
        repo[0] = [](variant<CAT, DOG, OX> animal)
        {
            CAT cat = std::get<0>(animal);
            cat.catFun();
        };

        repo[1] = [](variant<CAT, DOG, OX> animal)
        {
            DOG dog = std::get<1>(animal);
            dog.dogFun();
        };

        repo[2] = [](variant<CAT, DOG, OX> animal)
        {
            OX ox = std::get<2>(animal);
            ox.oxFun();
        };
    }
    void getFun(variant<CAT, DOG, OX> &animal)
    {
        repo[animal.index()](animal);
    }
} Smart;

void DoJob(variant<CAT, DOG, OX> animal)
{
    try
    {
        Smart.getFun(animal);
    }
    catch (bad_variant_access &exp)
    {
        cout << exp.what() << "\n";
    }
    line();
}
int main()
{
    DOG d;
    CAT c;
    OX o;

    DoJob(d);
    DoJob(c);
    DoJob(o);
    return 0;
}