#include "Cashier.hpp"

void Cashier::process_loan(int amount)
{
    if (amount <= 200000)
    {
        cout << "Loan processed by cashier amount -> " << amount << "\n";
    }
    else
    {
        cout << "Loan cannot be processed by cashier amount -> " << amount << "\n";
        RequestSuccessor(amount);
    }
}