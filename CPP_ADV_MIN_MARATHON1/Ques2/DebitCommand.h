#ifndef DEBITCOMMAND_H
#define DEBITCOMMAND_H

#include "command.h"


class DebitCommand:public command
{
    public:
    DebitCommand() = default;
    DebitCommand(const DebitCommand&) = delete;
    DebitCommand(DebitCommand&&) = delete;
    DebitCommand& operator=(const DebitCommand&) = delete;
    DebitCommand& operator=(const DebitCommand&&) = delete;
    ~DebitCommand() = default;


    DebitCommand(double amount):command(amount){}

    void execute(Account & acc) override
    {
        acc.debit(_amount);
    }
    void unexecute(Account & acc)override
    {
        acc.credit(_amount);
    }
};

#endif // DEBITCOMMAND_H