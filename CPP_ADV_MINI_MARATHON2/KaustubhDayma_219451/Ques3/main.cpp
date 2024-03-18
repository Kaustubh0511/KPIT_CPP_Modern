#include "functions.hpp"
#include "MyMethod.hpp"

int main()
{
    line();
    // call addFun using apply
    int result1 = std::apply(add, make_tuple(1, 2));
    cout << "Called addFun usning Apply and the result is : " << result1 << "\n";
    line();

    // call sum2 using apply
    int result2 = std::apply(Sum2, make_tuple(10, 20));
    cout << "Called Sum2 usning Apply and the result is : " << result2 << "\n";
    line();

    // overload an ostream operator to print tuple
    std::tuple myTuple(25, "Hello", 9.31f, 'c');
    std::cout << myTuple << "\n";
    line();

    MyMethod<int, double, float, char> obj;
    obj.AddFun(10, 20);
    obj.AddFun(1.0, 2.0);
    obj.AddFun(1.0f, 2.0f);
    obj.AddFun('a', 'c');
    obj.AddFun();
    return 0;
}