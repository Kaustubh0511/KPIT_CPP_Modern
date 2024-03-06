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

struct CB
{
    int n{100};
    string s{"sachin"};
    float d{1.2f};
};

template <int index>
auto getVal(const CB &cb)
{
    if constexpr (0 == index)
        return cb.n;
    else if constexpr (1 == index)
        return cb.s;
    else
        return cb.d;
}
int main()
{
    CB obj;
    int x = getVal<0>(obj);
    string st = getVal<1>(obj);
    float ft = getVal<2>(obj);
    return 0;
}