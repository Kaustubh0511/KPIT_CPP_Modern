#include <iostream>
#include <functional>
using namespace std;
#define line(msg) cout << "------------" #msg "--------------\n";

void Vendor(std::function<void()> obj)
{
    cout << "Start\n";
    obj();
    cout << "End\n";
}
//-----------------------------
void fun()
{
    cout << "Client fun\n";
}

class FUNC
{
public:
    void operator()()
    {
        cout << "Func fun\n";
    }
};
int main()
{
    Vendor(fun);
    Vendor(FUNC());
    Vendor([]()
           { cout << "Lambda\n"; });
    return 0;
}