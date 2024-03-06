#include "functionality1.hpp"

using FPTR = std::function<void(int &)>;
void Walk(FPTR fn, int *arr, int s)
{
    for (size_t i = 0; i < s; i++)
    {
    }
}

void ClientFun(int par)
{
    cout << par << "\t";
}

void func1()
{
}

template <typename T1, typename... Args>
void print_args(T1 fn, Args... pck)
{
    (fn(std::forward<Args>(pck)), ...);
}