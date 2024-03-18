#include "Transaction.h"
#include <iostream>
#define line(msg) std::cout << "----------------------" #msg "--------------------\n";

void functionality()
{
    Account acc(101, 10000);
    Transaction trans(acc);
    line();
    std::cout << "balance is " << trans.getBalance() << "\n";
    line();
    trans.debit(10000);
    std::cout << "balance is " << trans.getBalance() << "\n";
    line();
    trans.credit(10000);
    std::cout << "balance is " << trans.getBalance() << "\n";
    line();
    trans.credit(10000);
    std::cout << "balance is " << trans.getBalance() << "\n";
    line();
    trans.credit(1000);
    std::cout << "balance is " << trans.getBalance() << "\n";
    line();
    trans.debit(20000);
    std::cout << "balance is " << trans.getBalance() << "\n";
    line();
    trans.undo();
    std::cout << "balance is " << trans.getBalance() << "\n";
    line();
}

int main()
{
    functionality();
    return 0;
}