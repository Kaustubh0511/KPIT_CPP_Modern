#include <iostream>
#include "Struct.hpp"
#include "functions.hpp"

using namespace std;
#define line(msg) cout << "-----------------------" #msg "------------------\n";

int main()
{
    // snippet 1
    print_args([](const auto &arg)
               { cout << arg << '\t'; },
               "hello", 123, 3.141, 'c');
    cout << "\n";
    line();

    // snippet 2
    CB obj;
    cout << GetVal(&CB::a, obj) << "\n";
    cout << GetVal(&CB::b, obj) << "\n";
    cout << GetVal(&CB::c, obj) << "\n";
    GetVal(&CB::PrintX, obj, 123);
    GetVal(obj, 888);
    line();

    // snippet 3
    std::list<int> lst(7);
    Change_List(lst);
    return 0;
}