#include <iostream>
#include <tuple>
#include <string>

using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

// variadic template
template <typename FN>
void print_args(FN fn)
{
}

template <typename FN, typename T, typename... Args>
void print_args(FN fn, T val, Args &&...pck)
{
    fn(std::forward<T>(val));
    print_args(fn, std::forward<Args>(pck)...);
}

// fold expression
    template <typename T1, typename... Args>
    void print_args(T1 fn, Args... pck)
    {
        (fn(std::forward<Args>(pck)), ...);
    }
int main()
{
    print_args([](const auto &args)
               { cout << args << '\t'; },
               "hello", 123, 3.14159, 'c');
    return 0;
}