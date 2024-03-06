#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "---------------------\n";

/* Concept of Universal Reference.
*/
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
void f1(int a)
{
    cout << "f1(int) a = " << a << "\n";
}

void f1(int a, int b)
{
    cout << "f1(int,int) a = " << a << " , f1 b = " << b << "\n";
}

void f1(int a, int b, CA par)
{
    cout << "f1(int,int,CA) a = " << a << " , f1 b = " << b << "\n";
}

template<typename... T>
void Wrapper(T... par)
{
    f1(std::forward<T>(par)...);
}
int main()
{
    CA obj1;
    Wrapper(10);
    Wrapper(10,20);
    Wrapper(10,20,obj1);
    return 0;
}