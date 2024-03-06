#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <functional>
#include <mutex>
#include <sstream>
#include <future>
#include <tuple>
#include <set>
using namespace std;
#define line(msg) cout << "--------------" #msg "------------\n";

// inline variables is a feature of cpp17
struct MyClass1
{
    static const int sValue;
};

inline int const MyClass1::sValue = 777;

struct MyClass2
{
    inline static const int sValue = 777;
};
inline int g_x = 42;

int main()
{
    std::cout << MyClass2::sValue << endl;
    return 0;
}