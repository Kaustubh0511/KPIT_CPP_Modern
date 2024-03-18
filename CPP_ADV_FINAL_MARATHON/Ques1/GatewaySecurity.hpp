#ifndef GATEWAYSECURITY_HPP
#define GATEWAYSECURITY_HPP
#include <iostream>
using namespace std;
#define line(msg) cout << "-----------------------" #msg "---------------\n";

class GatewaySecurity
{
    friend class SmartSingle;
    static GatewaySecurity *head;
    GatewaySecurity(GatewaySecurity &&) = delete;
    GatewaySecurity(const GatewaySecurity &) = delete;

private:
    GatewaySecurity();
    static GatewaySecurity *Register();
    static void Release();
    ~GatewaySecurity();

public:
    void IssueTokens(int userId);
};

#endif // GATEWAYSECURITY_HPP