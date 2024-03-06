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

tuple<int, float, double> f3()
{
    cout << "f3 called\n";
    return {100, 1.2f, 3.14159};
}

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
    auto t1 = f3();
    // structured binding in cpp17
    auto [i, j, k] = t1;
    CA obj;
    obj.Display();
    auto &[a, b] = obj;
    // auto[a,b] = obj;
    // const auto &[a, b] = obj;
    cout << a << " " << b << "\n";
    return 0;
}