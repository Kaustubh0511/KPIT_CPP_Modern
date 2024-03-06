#include <iostream>
using namespace std;
#define line(msg) cout << "------------" #msg "----------------\n"

template <typename T, typename... T1>
void HOF(T fn, T1 &&...par)
{
    cout << "HOF\n";
    fn(std::forward<T1>(par)...);
}

//-----------------
class CA
{
public:
    CA() = default;
    CA(const CA &)
    {
        cout << "CA copy\n";
    }
    CA(CA &&) noexcept
    {
        cout << "CA Move\n";
    }
    ~CA() = default;
};

void f1(CA &&obj)
{
}

int main()
{
    return 0;
}