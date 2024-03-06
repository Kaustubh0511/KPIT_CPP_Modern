#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------" #msg "---------------------\n";

/* Concpet of packing and unpacking, this give rise to variadic template.
 */
//----------------------Most Basic Template-------------------------------------
// template<typename T>
// void printMe(T par){
//     cout<<par<<"\n";
// }
//-------------------------Sending pack to the template----------------------------------
// template <typename T1,typename... T>
// void printMe(T1 p,T... par) // pack recived
// {
//     cout << p << "\n";
// }
//-----------------------Discusion of specialization function------------------------------------
// template <typename T1,typename... T>
// void printMe(T1 p,T... par) // pack recived
// {
//     cout << p << "\n";
//     printMe(par...);//unpacking // This will give error when printMe is called without parameter.
// }

// To avoid the above error we create a specialization function.

template <typename T>
void printMe(T par)
{
    cout << par << " : end\n";
}
template <typename T1, typename... T>
void printMe(T1 p, T... par) // pack recived
{
    cout << p << "\t";
    printMe(par...);//unpacking
}

int main()
{
    // printMe(10);// Easily printed.
    // printMe(10,20,30,40); // This is going in as a pack in line 12
    line();
    printMe(10, 'c', 3.14, 22.3f);
    printMe(10,20,30,40);
    line();
    return 0;
}
