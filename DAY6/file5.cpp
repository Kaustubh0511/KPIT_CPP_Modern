#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

class CA
{
    int size;
    int *arr{nullptr};

public:
    CA(int val) : size(1), arr(new int[size])
    {
        cout << "One Param\n";
        arr[0] = val;
    }
    CA(int val1, int val2) : size(2), arr(new int[size])
    {
        cout << "Two Param\n";
        arr[0] = val1;
        arr[1] = val2;
    }
    // Init Constructor
    // CA(std::initializer_list<int> lst) : size(lst.size()), arr(new int[size])
    // {
    //     cout<<"Init constructor\n";
    //     initializer_list<int>::iterator it1 = lst.begin();
    //     auto it2 = lst.end();
    //     size_t index = 0;
    //     while (it1 != it2)
    //     {
    //         arr[index++] = *it1;
    //         it1++;
    //     }
    // }
    CA(std::initializer_list<int> lst) : size(lst.size()), arr(new int[size])
    {
        cout << "Init constructor\n";
        size_t index = 0;
        for (auto &i : lst)
        {
            arr[index++] = i;
        }
    }
    // CA(std::initializer_list<int> lst) = default; // Can be only done to the constructor that can be synthesized by the compiler.
    ~CA() noexcept
    {
        delete[] arr;
    }

    friend std::ostream &operator<<(std::ostream &os, const CA &par)
    {
        for (size_t i = 0; i < par.size; i++)
        {
            os << par.arr[i] << '\t';
        }
        os << "\n";
        return os;
    }
};
int main()
{
    CA obj1{1}; // Will target init constructor
    line();
    CA obj2{11, 22, 33, 44}; // Will target init constructor
    line();
    CA obj3 = {111}; // Will target init constructor
    line();
    CA obj4 = {1111, 2222}; // Will target init constructor
    line();
    CA obj5(11111);
    line();
    CA obj6 = 999;
    line();
    CA obj7(123, 456);
    line();
    cout << obj1 << obj2 << obj3 << obj4 << obj5 << obj6 << obj7;
    line();
    return 0;
}
