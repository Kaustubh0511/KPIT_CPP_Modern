#include <iostream>
#include <tuple>
#include <string>
#include <vector>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

template <typename T1, typename... T>
void pushAll(vector<T1> &vec, T... psh)
{
    (vec.push_back(psh), ...);
}
template <typename Tp>
ostream &operator<<(ostream &os, vector<Tp> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        os << vec[i] << "\t";
    }
    os << "\n";
    return os;
}
int main()
{
    vector v1{10}; // cpp17 feature.
    pushAll(v1, 20, 30, 40, 50, 60);
    cout << v1;
    return 0;
}
