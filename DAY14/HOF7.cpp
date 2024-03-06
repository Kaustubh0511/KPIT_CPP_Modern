#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

void EraseVector(vector<int> &vec, std::function<bool(int)> fn)
{
    // vector<int>::iterator it1 = vec.begin();
    // vector<int>::iterator it2 = vec.end();

    // while (it1 != it2)
    // {
    //     if (fn(*it1))
    //     {
    //         vec.erase(it1);
    //     }
    //     else
    //     {
    //         ++it1;
    //     }
    // }
    vec.erase(std::remove_if(vec.begin(), vec.end(), fn), vec.end());
}
int main()
{
    vector<int> vec{11, 22, 33, 44, 55, 66};
    // EraseVector(vec, [](int par)
    //             { return par % 2 == 1; });

    for (auto &v : vec)
    {
        cout << v << "\t";
    }
    cout << '\n';
    return 0;
}