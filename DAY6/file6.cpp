#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

// Constructor Delegation example
class CA
{
    int size{0}; // Universal Initialization(Brace Initialization).
    int *arr{nullptr};

public:
    CA(int val) : CA{val}
    {
        cout << "One param\n";
    }
    CA(int val1, int val2) : CA{val1, val2}
    {
        cout << "Two param\n";
    }
    CA(std::initializer_list<int> lst) : size(lst.size()), arr(new int[size])
    {
        cout << "Init constructor\n";
        size_t index = 0;
        for (auto &i : lst)
        {
            arr[index++] = i;
        }
    }
    ~CA()
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
    return 0;
}
