#include "Manager.hpp"

void Manager::process_loan(int amount)
{
    if (amount <= 400000)
    {
        cout << "Loan amount is processed amount -> " << amount << "\n";
    }
    else
    {
        cout << "Loan amount is too large to be processed -> " << amount << "\n";
        RequestSuccessor(amount);
    }
}