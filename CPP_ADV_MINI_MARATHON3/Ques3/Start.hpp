#ifndef START_HPP
#define START_HPP

#include <iostream>
#include <tuple>
#include <string>
#include <functional>
#include <list>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <random>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";
#include "functions.hpp"
#include "CComplex.hpp"
void Start()
{
    // used fold expression
    auto res = sum1(10, 20, 30, 40, 50, 60, 70);
    cout << res << "\n";
    line();

    auto res1 = sum1(10, 20, 30);
    cout << res1 << "\n";
    line();

    // ensure tab spaces between every display
    ShowAll(1.2, "sachin", 3.14f, 'c', 1, 2, 3);
    ShowAll(1, 2, 3);
    line();

    CComplex c1(10, 20);
    CComplex c2(20, 40);

    CComplex c3 = c1 + c2;

    CComplex c4 = c1 + 10; // 10 added to imaginary part
    CComplex c5 = 10 + c1; // 10 added to real part

    double d = (double)c4; // recivers real + imaginary

    tuple<double, double> t = c5;

    cout << c1 << c2 << c3 << c4 << c5 << "\n";
    cout << d << " " << std::get<0>(t) << " " << std::get<1>(t) << "\n";
    line();

    vector v1{10};
    pushAll(v1, 20, 30, 40, 50, 60, 70, 80);
    cout << v1 << "\n";
}

#endif // START_HPP
