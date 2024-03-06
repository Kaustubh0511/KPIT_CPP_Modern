#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "-------------------";

class CA
{
public:
    CA()
    {
        cout << "Default\n";
    }
    CA(CA &&par)
    {
        cout << "Move\n";
    }
    CA(const CA &par)
    {
        cout << "Copy\n";
    }
    ~CA()
    {
    }
};

int main()
{
    int par = 10;
    try
    {
        CA* ob = new CA();
    }
    catch (int )
    {
    }
    return 0;
}