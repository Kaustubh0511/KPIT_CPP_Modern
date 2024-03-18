#include "GatewaySecurity.hpp"

GatewaySecurity::GatewaySecurity()
{
    cout << "This is GatewaySecurity constructor\n";
}

GatewaySecurity::~GatewaySecurity()
{
    cout << "This is GatewaySecurity destructor\n";
}

void GatewaySecurity::IssueTokens(int userId)
{
    cout << "Toiken Claim Issued for " << userId << "\n";
}


