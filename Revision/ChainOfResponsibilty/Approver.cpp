#include "Approver.hpp"

void Approver::RequestSuccessor(int amount)
{
    if (successor != nullptr)
    {
        successor->process_loan(amount);
    }
}

void Approver::set_successor(Approver *successor)
{
    this->successor = successor;
}


