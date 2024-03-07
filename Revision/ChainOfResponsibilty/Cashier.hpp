#ifndef CASHIER_HPP
#define CASHIER_HPP

#include "Approver.hpp"

class Cashier : public Approver
{
public:
    void process_loan(int amount);
};

#endif // CASHIER_HPP
