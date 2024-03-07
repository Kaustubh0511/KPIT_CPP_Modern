#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Approver.hpp"
class Manager : public Approver
{
public:
    void process_loan(int amount);
    
};
#endif // MANAGER_HPP
