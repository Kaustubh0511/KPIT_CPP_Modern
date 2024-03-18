#ifndef CREDITCOMMAND_H
#define CREDITCOMMAND_H

#include "command.h"


class CreditCommand:public command
{
    public:
    CreditCommand() = default;
    CreditCommand(const CreditCommand&) = delete;
    CreditCommand(CreditCommand&&) = delete;
    CreditCommand& operator=(const CreditCommand&) = delete;
    CreditCommand& operator=(const CreditCommand&&) = delete;
    ~CreditCommand() = default;
    
    CreditCommand(double amount):command(amount){}

    void execute(Account & acc) override
    {
        acc.credit(_amount);
    }
    void unexecute(Account & acc)override
    {
        acc.debit(_amount);
    }
};

#endif // CREDITCOMMAND_H