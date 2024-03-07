#include <iostream>
#include <tuple>
#include <string>
#include <functional>
#include <list>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <string_view>
#include <chrono>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

void f1(string s1)
{
    cout << s1.substr(7, 6) << '\n';
}

void f2(const string &str)
{
    cout << str.substr(7, 6) << '\n';
}

void f3(string_view str) // there is no new memory allocated, whatever operations to do will not create any new space in the memory.
{
    cout << str.substr(7, 6) << '\n';
}
int main()
{
    string st = "Sachin Ramesh Tendulkar";
    // f1(st);
    // f2(st);
    // f3(st);

    string my_string = "0123456789-Sachin-0123456789-0123456789-0123456789";
    // cout << my_string << "\n";
    std::string_view st_view{my_string.c_str(), my_string.size()};

    // cout << my_string << "\n";
    // cout << st_view.substr(11, 6) << "\n";
    // cout << my_string << "\n";

    const size_t count = 100000;
    auto start = std::chrono::steady_clock::now();

    for (size_t i = 0; i < count; i++)
    {
        auto s = my_string.substr(11, 6);
    }
    std::chrono::duration<double> duration_taken = std::chrono::steady_clock::now() - start;

    auto start1 = std::chrono::steady_clock::now();

    for (size_t i = 0; i < count; i++)
    {
        auto s = st_view.substr(11, 6);
    }
    std::chrono::duration<double> duration_taken1 = std::chrono::steady_clock::now() - start1;

    cout << "duration taken : " << duration_taken.count() << " seconds \n";
    cout << "duration taken 1 : " << duration_taken.count() << " seconds \n";

    return 0;
}