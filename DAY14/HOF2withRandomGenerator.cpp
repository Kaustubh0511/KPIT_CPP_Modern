#include <iostream>
#include <tuple>
#include <string>
#include <cstdlib>
#include <random>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

int main()
{
    // c++14
    random_device rd;
    std::mt19937 gen(rd()); // mersene twister engine

    std::uniform_int_distribution<> dis(10, 50);
    for (size_t i = 0; i <= 4; i++)
    {
        cout << dis(gen) << "\t";
    }
    cout << "\n";
    return 0;
}
