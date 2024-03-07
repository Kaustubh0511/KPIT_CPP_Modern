#include "Director.hpp"

void Director::process_loan(int amount)
{
        if (amount <= 700000)
        {
            cout << "Loan amount is processed amount -> " << amount << "\n";
        }
        else
        {
            cout << "Loan amount is too large to be processed -> " << amount << "\n";
            RequestSuccessor(amount);
        }
    }