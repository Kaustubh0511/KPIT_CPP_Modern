#include <iostream>
using namespace std;
/*
1. YAGNI -> you arn't gonna need it
2. High Cohession
3. SRP -> Single Responsibility Principle
4. KISS -> Keep it simple and stupid
*/

//Approved Class
class SavingsAccount
{
public:
    void DoDebitSavings(int Accid, int amount)
    {
        // Debit
        cout << "Debit in Savings\n";
    }
};

class CurrentAccount
{
public:
    void DoDebitCurrent(int Accid, int amount)
    {
        // Debit
        cout << "Debit in Current\n";
    }
};

int main()
{
    SavingsAccount sa;
    sa.DoDebitSavings(101, 100);
    CurrentAccount ca;
    ca.DoDebitCurrent(102, 150);
    return 0;
}
