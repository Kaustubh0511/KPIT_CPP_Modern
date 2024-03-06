#include <iostream>
using namespace std;
/*
1. YAGNI -> you arn't gonna need it
2. High Cohession
3. SRP -> Single Responsibility Principle
4. KISS -> Keep it simple and stupid
5. DRY/DIE/WET/OAOO -> dont repeat yourself/duplication is evil/We enjoying typing/Once and only once
*/

//Rejected Class
class SavingsAccount
{
public:
    void DoDebitSavings(int Accid, int amount)
    {
        // Debit
        cout<<"Open DB";
        cout << "Debit in Savings\n";
        cout<<"Close DB";
    }
};

class CurrentAccount
{
public:
    void DoDebitCurrent(int Accid, int amount)
    {
        // Debit
        cout<<"Open DB";
        cout << "Debit in Current\n";
        cout<<"Close DB";
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
