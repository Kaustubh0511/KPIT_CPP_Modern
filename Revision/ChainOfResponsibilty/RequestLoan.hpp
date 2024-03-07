#ifndef REQUESTLOAN_HPP
#define REQUESTLOAN_HPP

#include "Approver.hpp"
void RequestLoan(int amount, Approver &approver)
{
    approver.process_loan(amount);
}

#endif // REQUESTLOAN_HPP
