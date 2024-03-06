#include <iostream>
#include <functional>
using namespace std;
#define line(msg) cout << "-----------------" #msg "---------------------\n";

/* Concept of Template Reference/Universal Reference & perfect forwarding.
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

template <typename T>
void f1(T par)
{
    cout << "T =[" << typeid(par).name() << "]\n";
    cout << "Apple\n";
}

template <typename T>
void f2(T &par)
{
    cout << "f2 T =[" << typeid(par).name() << "]\n";
    cout << "Orange\n";
}

template <typename T>
void f3(T &&par)
{
    cout << "f3 T =[" << typeid(par).name() << "]\n";
    cout << "Universal Reference\n";
    cout << "Mango\n";
}

template <typename T>
void reciever(T p)
{
    cout << "Recieved\n";
}

template <typename T>
void surrogate(T &&p)
{
    line(inReciever);
    reciever(std::forward<T>(p));
    cout << "Orange\n";
}

void test1()
{
    CA obj1;
    line();
    int j = 10;
    f1(10);
    line();
    f1(j);
    line();
    f1(obj1);
    line();
}

void test2()
{
    CA obj1;
    line();
    int j = 10;
    // f2(10); // 10 has no reference so it cannot be passed.
    line();
    f2(j);
    line();
    f2(obj1);
    line();
}

void test3()
{
    CA obj1;
    line();
    int j = 10;
    f3(10); // Normal value
    line();
    f3(j); // Normal variable
    line();
    f3(std::ref(j)); // Reference of j
    line();
    f3(obj1); // Lvalue object.
    line();
    f3(std::ref(obj1)); // Reference object.
    line();
    f3(std::move(obj1)); // Rvalue object
}

void test4()
{
    CA obj;
    line();
    int j = 10;
    surrogate(10);
    line();
    surrogate(j);
    line();
    surrogate(obj); // If forward and universal reference then it will check if the object is lvalue or rvalue
    line();
    surrogate(std::move(obj)); // If forward and universal reference then it will check if the object is lvalue or rvalue
    line(); // If the object is lvalue then copy will be called, but if object is rvalue then move constructor will be called.
}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}