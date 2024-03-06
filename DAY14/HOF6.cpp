#include <iostream>
#include <tuple>
#include <string>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

void increase(int &i, int &j)
{
    i += 10;
    j += 10;
}
int main()
{
    int x = 100, y = 200;
    line();
    cout << " x = " << x << " y = " << y << "\n";
    auto change = std::bind(increase, ref(x), y);
    change();
    cout << " x = " << x << " y = " << y << "\n";
    return 0;
}
