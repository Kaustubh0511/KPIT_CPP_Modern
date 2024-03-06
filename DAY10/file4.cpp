#include <iostream>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------\n"

class CA
{
public:
    void Bharath(int x)
    {
        cout << "Bharath x : " << x << "\n";
    }
    void India(int x)
    {
        cout << "India x : " << x << "\n";
    }
    void Hindustan(int x)
    {
        cout << "Hindustan x : " << x << "\n";
    }
    void Alhind(int x)
    {
        cout << "Alhind x : " << x << "\n";
    }
};

int main()
{
    CA obj;
    line();
    std::function<void(int)> fn1 = std::bind(&CA::Bharath,obj,placeholders::_1);
    fn1(10);
    fn1(20);
    fn1(30);
    
}