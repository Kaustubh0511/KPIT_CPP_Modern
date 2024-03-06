#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
public:
    static void *operator new(size_t) = delete;
    static void *operator new[](size_t) = delete;
    static void operator delete(void *) = delete;
    static void operator delete[](void *) = delete;
    CA() = default;
    CA(const CA &) = delete;            // Preventing the use of copy constructor
    CA &operator=(const CA &) = delete; // Preventing the use of assignment operator.
    ~CA() = default;                    // pointing to vtable, delete himself, stack unwind.
    void addFun(double x, double y)
    {
    }
    void addFun(int, int) = delete;

    void subFun(double x, double y)
    {
    }

    template <typename T>
    void subFun(T, T) = delete;
};
int main()
{
    CA obj1;
    // CA obj2(obj1); // This is prohibited by the compiler, as it calls the deleted copy constructor.
    CA obj3;
    // obj1 = obj3; // This is prohibited by the compiler as it calls the deleted assignment operator.
    // CA *obj4 = new CA(); // This is prohibited by the compiler as it calls the deleted new operator.
    // delete obj4; // This is prohibited by the compiler as it calls the deleted "delete" operator.
    // CA *obj5 = new CA[5]; // This is prohibited by the compiler as it calls the deleted new operator.
    // delete[] obj5; // This is prohibited by the compiler as it calls the deleted "delete" operator.
    // obj1.addFun(10,20); // This is prohibited by the compiler as addFun for int is deleted, hence int ot double conversion is prohibited.
    obj1.addFun(1.0, 2.0);
    obj1.addFun(1.0f, 2.0f);

    // obj1.subFun(1, 2); // This is prohibited by the compiler as addFun for a typename is deleted, hence int to double conversion is prohibited.
    obj1.subFun(1.0, 2.0);
    // obj1.subFun(1.0f, 2.0f); // This is prohibited by the compiler as addFun for typename is deleted, hence float to double conversion is prohibited.
    return 0;
}