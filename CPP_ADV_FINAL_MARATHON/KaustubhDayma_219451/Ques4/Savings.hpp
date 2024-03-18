#ifndef SAVINGS_HPP
#define SAVINGS_HPP

#include "Account.hpp"
class Savings : public Account<Savings>
{
    public:
	void DoDebit(int Accid, int amount);
};

#endif // SAVINGS_HPP
