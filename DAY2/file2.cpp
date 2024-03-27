#include <iostream>
#include <vector>
using namespace std;
/*
1. YAGNI -> you arn't gonna need it
2. High Cohession
3. SRP -> Single Responsibility Principle
*/
// Rejected Class (voilates SRP)
class Account
{
public:
    void DoDebitSavings(int Accid, int amount)
    {
        // Debit
        cout << "Debit in Savings\n";
    }
    void DoDebitCurrent(int Accid, int amount)
    {
        // Debit
        cout << "Debit in Current\n";
    }
};
using Container = vector<Account>;

void CreateObject(Container &data)
{
}

int main()
{
    Container acc;
    CreateObject(acc);
    // acc.DoDebitCurrent(101, 100);
    // acc.DoDebitSavings(102, 100);
    return 0;
}
