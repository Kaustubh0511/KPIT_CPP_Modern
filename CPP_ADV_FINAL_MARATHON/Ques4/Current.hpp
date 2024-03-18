#ifndef CURRENT_HPP
#define CURRENT_HPP

#include "Account.hpp"
class Current : public Account<Current>
{
public:
    void DoDebit(int Accid, int amount);
};

#endif // CURRENT_HPP
