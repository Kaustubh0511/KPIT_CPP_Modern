#include <iostream>
#include <string>
using namespace std;
/**
 * BANK
 * go -> ask loan -> meet cashier(loan cahiye)-> approver of loan(cashier)(upto 2 lakh)-> if more than 2-> goto manager (only upto 4 lakh)-> more tan 4l -> goto directer(upto 7L).
 *
 * # approvers base class -> LL(self refretial str) ->
 * cashiers
 * manager
 * director
 *
 * customer
 *
 */

/*
Abstract Factory
IMomento
Bank = Chain of Responsibility
Singleton
Decorator
*/

class Approver
{

    Approver *successor{nullptr}; // sahi tarika null object pattern
    // either aggreagfation or composition
    // aggre -> somethin which is going to die with  me but not born with me
    // compo ->  born with me , die with me
    // association -> no control on others killing

    // CHAIN OF RESPONSIBILITIES
protected:
    void RequestSuccessor(int amount)
    {
        if (successor != nullptr)
        {
            successor->process_Loan(amount);
        }
    }

public:
    void set_successor(Approver *successor)
    {
        this->successor = successor;
    }
    operator Approver *()
    {
        return this;
    }
    virtual void process_Loan(int amount) = 0;
};

class Cashier : public Approver
{
public:
    void process_Loan(int amount)
    {
        if (amount <= 200000)
        {
            cout << "LOAN PROCESSED BY CASHIER AMOUNT -> " << amount << "\n";
        }
        else
        {
            cout << "LOAN CANNOT BE PROCESSED BY CASHIER AMOUNT -> " << amount << "\n";
            RequestSuccessor(amount);
        }
    }
};

class Manager : public Approver
{
public:
    void process_Loan(int amount)
    {
        if (amount <= 400000)
        {
            cout << "LOAN PROCESSED BY MANAGER AMOUNT -> " << amount << "\n";
        }
        else
        {
            cout << "LOAN CANNOT BE PROCESSED BY MANAGER AMOUNT -> " << amount << "\n";
            RequestSuccessor(amount);
        }
    }
};

class Director : public Approver
{
public:
    void process_Loan(int amount)
    {
        if (amount <= 700000)
        {
            cout << "LOAN PROCESSED BY DIRECTER AMOUNT -> " << amount << "\n";
        }
        else
        {
            cout << "LOAN CANNOT BE PROCESSED BY DIRECTER AMOUNT -> " << amount << "\n";
            RequestSuccessor(amount);
        }
    }
};

void RequestLoan(int amount, Approver &approver)
{
    approver.process_Loan(amount);
}

int main()
{
    Cashier john;
    Manager james;
    Director cliff;

    john.set_successor(james);
    james.set_successor(cliff);

    RequestLoan(150000, john);
    cout << "-------------------------------------------\n";
    RequestLoan(250000, john);
    cout << "-------------------------------------------\n";
    RequestLoan(450000, john);
    cout << "-------------------------------------------\n";
    RequestLoan(750000, john);
    cout << "-------------------------------------------\n";
}