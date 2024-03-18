#include "SmartSingle.hpp"

int SmartSingle::id = 0;
void TestMember(SmartSingle &sm, SmartSingle::FPTR fp)
{
    (sm->*fp)();
}

void Test(int _id)
{
    SmartSingle ss1;
    line();
    SmartSingle::id = _id;
    try
    {
        ss1->IssueTokens(_id);
        cout << ss1.use_count() << "\n";
    }
    catch (CustomException ce1)
    {
        cout << ce1.what() << "\n";
    }

    line();
    SmartSingle ss2;
    TestMember(ss2, &GatewaySecurity::IssueTokens);
    cout << ss2.use_count() << "\n";
    line();

    SmartSingle ss3;
    ss3->IssueTokens(_id);
    cout << ss3.use_count() << "\n";
    line();

    SmartSingle ss4;
    (*ss4).IssueTokens(_id);
    cout << ss4.use_count() << "\n";
    line();
}
