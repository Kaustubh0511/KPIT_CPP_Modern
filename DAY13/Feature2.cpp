#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <variant>
#include <map>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

int main()
{
    auto x = 10;
    decltype(x * 1.1) y = 100.01f;
    cout << "Y is : " << y << "\n";

    tuple<int, double> tup(100, 3.14159);
    variant<int, double, float, char> v = 100;
    try
    {
        cout << "Current index in v: " << v.index() << "\n";
        int idx = v.index();
        cout << "Index is : " << idx << "\n";
        auto res = std::get<0>(v);
        cout << "Res : " << res << "\n";
        v = 3.14159;
        cout << "Current index in v: " << v.index() << "\n";
        v = 1.2f;
        cout << "Current index in v: " << v.index() << "\n";

        v = to_string(1)[0];
        cout << "Current index in v: " << v.index() << "\n";

        v = 's';
        double d = std::get<double>(v);
        cout << "Current index in v : " << v.index() << '\n';
    }
    catch (bad_variant_access &exp)
    {
        cout << exp.what() << "\n";
    }
    return 0;
}

