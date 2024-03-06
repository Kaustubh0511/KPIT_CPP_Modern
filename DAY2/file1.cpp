#include <iostream>
using namespace std;

class CA
{
public:
    CA()
    {
        Apple();
    }
    void DoJob()
    {
        this->Apple();
    }
    virtual void Apple() { cout << "CA::Apple Ooty\n"; }
    ~CA()
    {
        Apple();
    }
};

class CB : public CA
{
public:
    CB()
    {
    }
    void Apple() override { cout << "CB::Apple Shimla\n"; }
    ~CB()
    {
    }
};

int main()
{
    CB obj1;
    obj1.DoJob();
    obj1.CA::~CA();
    obj1.DoJob();
}