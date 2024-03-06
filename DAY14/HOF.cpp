#include <iostream>
#include <tuple>
#include <string>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

using FPTR = std::function<void(int &)>;
void Walk(FPTR f, int *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        f(arr[i]);
    }
}

//---------------------------------------

void ClientFun(int par)
{
    cout << par << "\t";
}
void ClientFun1(int par)
{
    cout << par * 10 << "\t";
}

void ClientFun2(int &par)
{
    par *= 2;
}
int main()
{
    int arr[6] = {11, 22, 33, 44, 55, 66};
    Walk(&ClientFun, arr, 6);
    cout << "\n";
    Walk(&ClientFun1, arr, 6);
    cout << "\n";
    Walk(&ClientFun2, arr, 6);
    Walk(&ClientFun, arr, 6);
    cout << "\n";
    int k = 11;
    Walk([k](int &par)
         { par *= k; },
         arr, 6);
    Walk(&ClientFun, arr, 6);
    cout << "\n";
    return 0;
}