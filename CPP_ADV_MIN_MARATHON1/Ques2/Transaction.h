#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"
#include "command.h"
#include "CommandRepo.h"
#include "DebitCommand.h"
#include "CreditCommand.h"
#include "exception.h"
#include <iostream>
class Transaction
{
private:
    Account &acc; // Account Object
    CommandRepo repository; 

public:
    Transaction(Account &acc) : acc(acc) {}
    double getBalance() const { return acc.getbalance(); }
    void debit(double amount)
    {
        try
        {
            if ((acc.getbalance() - amount) < 0)
            {
                throw exception("not enough balance!!\n");
            }

            DebitCommand *cmd = new DebitCommand(amount);
            cmd->execute(acc);
            repository.Register(cmd);
        }
        catch (exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }
    void credit(double amount)
    {
        CreditCommand *cmd = new CreditCommand(amount);
        cmd->execute(acc);
        repository.Register(cmd);
    }
    void undo()
    {
        command *cmd = repository.retrive();
        cmd->unexecute(acc);
        delete cmd;
    }
    ~Transaction() //Deleting the stack
    {
        while (!repository.IsEmpty())
        {
            command *cmd = repository.retrive();
            delete cmd;
        }
    }
};

#endif // TRANSACTION_H
