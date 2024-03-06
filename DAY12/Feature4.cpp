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

struct S
{
    int n;
    std::string s;
    float d;
    bool operator<(const S &rhs) const
    {
        // return std::tie(n, s, d) < std::tie(rhs.n, rhs.s, rhs.d);
        return std::tie(n, s, d) < std::tie(rhs.n, rhs.s, rhs.d);
    }
};

int main()
{
    std::set<S> set_of_S;

    S value{42, "Test", 3.14};

    auto [it, inserted] = set_of_S.insert(value);
    if (inserted)
    {
        cout << "Value was inserted sucessfully\n";
    }
    return 0;
}