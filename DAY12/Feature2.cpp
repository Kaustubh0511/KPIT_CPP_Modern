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

struct CB
{
    int i{100};
    int j{200};

    operator tuple<int, int>()
    {
        return {i + 1, i + 2};
    }
    operator tuple<int &, int &>()
    {
        return {i, j};
    }
};

int main()
{
    CB obj;
    int x, y;
    std::tie(x, y) = obj;
    cout << "x = " << x << ", y = " << y << "\n";
    line();
    return 0;
}