#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include "Approver.hpp"
class Director : public Approver
{
    public:
    void process_loan(int amount);
};

#endif // DIRECTOR_HPP
