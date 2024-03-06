#include <iostream>
#include <functional>
#include <map>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------\n"

class IMomneto
{
public:
    virtual void hyderate() = 0;
    virtual void dehyderate() = 0;
};

class careTaker
{
public:
    static map<IMomneto *, map<int, IMomneto>> repo;
};

class CProduct
{
    string name;
    double price;

public:
    void Display()
    {
        cout << name << "------------" << price << "\n";
    }
};

class CEmployee
{
    int id;
    string name;
    string dept;

public:
    void Display()
    {
        cout << id << "---------------" << name << "--------------" << dept << "\n";
    }
};

int main()
{
    return 0;
}