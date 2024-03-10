#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "Smart_Single.h"

void function()
{
    Smart_Single smts1;
    try
    {
        smts1->fun1();
        smts1->fun2();
        smts1->fun3();
        cout << smts1.use_count() << "\n";
    }
    catch (CustomException ce1)
    {
        cout << ce1.what() << "\n";
    }

    Smart_Single smts2;
    cout << smts2.use_count() << "\n";
    Smart_Single smts3;
    cout << smts3.use_count() << "\n";
}
void TestMember(Smart_Single &sm, Smart_Single::FPTR fp)
{
    (sm->*fp)();
}

void Test()
{
    Smart_Single smts4;
    TestMember(smts4, &Single::fun1);
}

#endif // FUNCTION_HPP
