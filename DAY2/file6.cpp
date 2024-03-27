#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

/*
1. YAGNI -> you arn't gonna need it
2. High Cohession
3. SRP -> Single Responsibility Principle
4. KISS -> Keep it simple and stupid
5. DRY/DIE/WET/OAOO -> dont repeat yourself/duplication is evil/We enjoying typing/Once and only once
6. LSP -> Liskov's Substition Principle
*/

// interface
class IX
{
public:
    virtual void fx1() = 0;
    virtual void fx2() = 0;
};

class CX : public IX
{
public:
    void fx1() override
    {
        cout << "Hi\n";
    }
    void fx2() override
    {
        cout << "Hi2\n";
    }
};

int main()
{
    CX obj;
    obj.fx1();
    obj.fx2();
    line();
    IX *px = &obj; // LSP
    px->fx1();     // px -> vptr -> vtable[0];
    px->fx2();     // px -> vptr -> vtable[1]();
    line();
    IX &pxRef = obj;
    pxRef.fx1(); // pxRef.vptr -> vtable[0]();
    pxRef.fx2(); // pxRef.vptr -> vtable[1]();

    return 0;
}
