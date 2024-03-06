#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <functional>
#include <mutex>
#include <sstream>
#include <future>
#include <tuple>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

class CA
{
public:
    int i{0};
    int j{0};

    void Display()
    {
        cout << "Display i = " << i << ", j = " << j << "\n";
    }
    operator tuple<int, int>()
    {
        return {i, j};
    }
};

int main()
{
    int x = 10, y = 20;
    cout << "x = " << x << ", y = " << y << "\n";
    line();
    std::tie(x, y) = std::make_tuple(y, x);
    cout << "x = " << x << ", y = " << y << "\n";
    line();
    CA obj{111, 222};
    std::tie(x, y) = (tuple<int, int>)obj; // Can be also written as  => tuple<int,int> t1 = obj  => std::tie(x,y) = t1;
    cout << "x = " << x << ", y = " << y << "\n";
    line();
    // CA obj1{98, 100};
    CA obj1;
    tuple<int, int> t2 = obj1;
    std::tie(x, y) = t2;
    cout << "x = " << x << ", y = " << y << "\n";
    line();
    return 0;
}