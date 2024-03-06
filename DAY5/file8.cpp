#include <iostream>
using namespace std;
#define line(msg) cout << "--------" #msg "--------------";

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

class CB
{
public:
    CB()
    {
        cout << "CB constructor\n";
    }
    CB(int)
    {
        cout << "CB(int)\n";
    }
    CB(int, int)
    {
        cout << "CB(int, int)\n";
    }
    CB(CA par)
    {
        cout << "CB(CA)\n";
    }
};

template <typename T1>
class Smart_Ptr
{
    T1 *pt;

public:
    template <typename... T>
    Smart_Ptr(T &&...pck) : pt(new T1(std::forward<T>(pck)...))
    {
    }
    T1 *operator->()
    {
        return pt;
    }
    ~Smart_Ptr()
    {
        delete pt;
    }
};

int main()
{
    CA obj;
    Smart_Ptr<CB> sm1;
    line();
    Smart_Ptr<CB> sm2(10);
    line();
    Smart_Ptr<CB> sm3(10, 20);
    line();
    Smart_Ptr<CB> sm4(obj);
    line();
    Smart_Ptr<CB> sm5(std::move(obj));
    line();
    return 0;
}