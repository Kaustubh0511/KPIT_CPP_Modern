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

tuple<int, float, double> f1()
{
    cout << "f1 called\n";
    tuple<int, float, double> tup = make_tuple<int, float, double>(100, 1.2f, 3.14159);
    return tup;
}

auto f2()
{
    cout << "f2 called\n";
    tuple<int, float, double> tup(100, 1.2f, 3.14159);
    return tup;
}

tuple<int, float, double> f3()
{
    cout << "f3 called\n";
    return {100, 1.2f, 3.14159};
}

int main()
{
    tuple<int, float, double> t1 = f3();
    auto t2 = f2();

    cout << std::get<0>(t1) << "\t" << std::get<1>(t1) << "\t" << std::get<2>(t1) << "\n";
    line();
    int i;
    float j;
    double k;
    std::tie(i, j, k) = t2;
    cout << i << "\t" << j << "\t" << k;
    cout << std::get<0>(t2) << "\t" << std::get<1>(t2) << "\t" << std::get<2>(t2) << "\n";
    std::get<0>(t2) += 100;
    cout << std::get<0>(t2) << "\t" << std::get<1>(t2) << "\t" << std::get<2>(t2) << "\n";
    line();

    int i1;
    double k1;
    std::tie(i1, std::ignore, k1) = t2;
    cout << i1 << "\t" << k1;
    line();

    int &i2 = std::get<0>(t2);
    i2 += 1000;
    cout << std::get<0>(t2) << "\t" << std::get<1>(t2) << "\t" << std::get<2>(t2) << "\n";
    line();
    return 0;
}