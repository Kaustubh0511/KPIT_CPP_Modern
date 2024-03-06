#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CC
{
    static int count;
    int x{0};

public:
    CC() : x(++count)
    {
        cout << "CC c-tor\n";
    }
    CC(const CC &par) : x(++count)
    {
        cout << "CC c-tor by copy\n";
    }
    CC(CC &&) noexcept
    {
        cout << "CC Move\n";
    }
    CC &operator=(const CC &)
    {
        cout << "Assignment operator\n";
        return *this;
    }
    CC &operator=(CC &&)
    {
        cout << "Move Assignment operator\n";
        return *this;
    }
    ~CC()
    {
        cout << "CC d-tor x :"<<x<<"\n";
    }
};

int CC::count = 0;
int main()
{
    CC obj;
    CC obj1 = obj;
    line();
    CC obj2 = std::move(obj);
    line();
    return 0;
}