// #include <iostream>
// #include <tuple>
// #include <string>
// #include <functional>
// #include <list>
// #include <numeric>
// #include <algorithm>
// #include <cstdlib>
// #include <random>
// using namespace std;
// #define line(msg) cout << "----------------" #msg "----------------------\n";
// template <typename... T1>
// struct a
// {
//     /* data */
// };
// template <typename... t2>
// struct b
// {
//     /* data */
// };

// template <typename... T, typename... PCK>
// void Wrapper(a<T...> fun, b<PCK...> par)
// {
    // Call the first function with the first argument
//     fun(par);
// }

// int main()
// {
//     auto lmbd = [](int par)
//     { std::cout << par * par << '\n'; };
//     auto lmbd1 = [](int par)
//     { std::cout << par + par << '\n'; };
//     auto lmbd2 = [](int par)
//     { std::cout << par - par << '\n'; };
//     std::function<void(int)> flmbd = lmbd;
//     Wrapper(a<decltype(lmbd), decltype(lmbd1), decltype(lmbd2)>{}, b<decltype(10), decltype(20), decltype(30)>{});

//     return 0;
// }

#include <iostream>
#include <tuple>
#include <utility>

template <typename Tuple, std::size_t... Idx>
void call_with_indices(Tuple&& tuple, std::index_sequence<Idx...>) {
    (std::get<Idx>(std::forward<Tuple>(tuple))(), ...);
}

template <typename TupleLambdas, typename TupleArgs, std::size_t... LambdaIndices, std::size_t... ArgIndices>
void invoke_helpers(const TupleLambdas& lambdas, const TupleArgs& args, std::index_sequence<LambdaIndices...>, std::index_sequence<ArgIndices...>) {
    (std::get<LambdaIndices>(lambdas)(std::get<ArgIndices>(args)), ...);
}

template <typename TupleLambdas, typename TupleArgs, std::size_t N, std::size_t M>
void invoke_helpers(const TupleLambdas&, const TupleArgs&, std::index_sequence<N>, std::index_sequence<M>) {}

template <typename... Lambdas, typename... Args>
void Wrapper(std::tuple<Lambdas...> lambdas, std::tuple<Args...> args) {
    constexpr auto size = std::tuple_size_v<std::tuple<Lambdas...>>;
    static_assert(size == std::tuple_size_v<std::tuple<Args...>>, "Number of functions and arguments must be equal");

    auto lambda_indices = std::make_index_sequence<size>{};
    auto arg_indices = std::make_index_sequence<size>{};
    invoke_helpers(lambdas, args, lambda_indices, arg_indices);
}

int main() {
    auto lmbd = [](int par) { std::cout << par * par << '\n'; };
    auto lmbd1 = [](int par) { std::cout << par + par << '\n'; };
    auto lmbd2 = [](int par) { std::cout << par - par << '\n'; };

    Wrapper(std::make_tuple(lmbd, lmbd1, lmbd2), std::make_tuple(10, 20, 30));

    return 0;
}