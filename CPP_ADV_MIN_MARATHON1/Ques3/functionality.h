#pragma once

#include "CA.h"
#include "CB.h"
#include "Factory.cpp"



template <typename T>
void TestMember(Smart<T> &sm, typename Smart<T>::FPTR fp)
{
    std::cout << "TestMember started\n";
    (sm->*fp)();
    std::cout << "TestMember completed\n";
}

template<typename T>
void Test()
{
	Smart<T> sm1 = new T();
	sm1->fun();
	Smart<T> sm2 = make_smart<T>();
	sm1 = sm2;
	if(sm1)
	{
		sm1->fun();
		(*sm1).fun();
	}
	TestMember(sm1, &T::fun);
}