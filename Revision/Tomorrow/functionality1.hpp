#ifndef FUNCTIONALITY_HPP
#define FUNCTIONALITY_HPP

#include <iostream>
#include <tuple>
#include <string>
#include <functional>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------------\n";

using FPTR = std::function<void(int &)>;
void Walk(FPTR f, int *arr, int size);

void ClientFun(int par);

void ClientFun1(int par);

void ClientFun2(int &par);

void func1();

void func2();

void func3();




#endif // FUNCTIONALITY_HPP
