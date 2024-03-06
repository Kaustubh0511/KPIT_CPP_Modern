#include <iostream>
#include <map>
#include <stack>
using namespace std;
#define line(msg) cout << "-----------------" #msg "---------------\n";
/* Command is nothing but an object that remembers the request.
Create Account class which takes state as accid and initial amount.
with behaviours getbalance, debit and credit.
Create transaction to wrap all account behaviour.

Add another behaviour to perform undo operations.

Create debit and credit command classes to perform appropriate command operations like execute and unexecute and
also maintain the command state to perform operations on account object.
Extend debit and Credit command classes from base class Command comprising
execute and unexecute

All operations done should be through command objects in transaction helper.

Create a repository to maintain a stack of commands and allow register and retrieval.

Store command objects in the repository after every operation.

Retrive command from repository on every undo and call it's  unexecute.

Do the appropriate clean up of commands in the transaction.


*/

class Account
{
    int m_Accid{0};
    double m_balance{0.0};

public:
    // Account() = default;
    // Account(const Account &) = delete;
    // Account(Account &&) noexcept = delete;
    // ~Account() = default;

    Account(int id, double amount) : m_Accid(id), m_balance(amount)
    {
    }

    double getBalance() const
    {
        return m_balance;
    }
    void debit(double amount)
    {
        m_balance += amount;
    }
    void credit(double amount)
    {
        m_balance -= amount;
    }
};
class Command
{
protected:
    double amount;
    Command(double amount) : amount(amount)
    {
    }

public:
    virtual void execute(Account &) = 0;
    virtual void unexecute(Account &) = 0;
    virtual ~Command() = default;
};
class DebitCommand : public Command
{
public:
    DebitCommand(double amount) : Command(amount)
    {
    }
    void execute(Account &acc) override
    {
        acc.debit(amount);
    }
    void unexecute(Account &acc) override
    {
        acc.credit(amount);
    }
};
class CreditCommand : public Command
{
public:
    CreditCommand(double amount) : Command(amount)
    {
    }
    void execute(Account &acc) override
    {
        acc.credit(amount);
    }
    void unexecute(Account &acc) override
    {
        acc.debit(amount);
    }
};
class CommandRepository
{
    stack<Command *> repo;

public:
    void Register(Command *cmd)
    {
        repo.push(cmd);
    }
    Command *Retrive()
    {
        Command *cmd = repo.top();
        repo.pop();
        return cmd;
    }
    bool Isempty()
    {
        return repo.empty();
    }
};
class Transaction
{
    Account &acc;
    CommandRepository repository;

public:
    Transaction(Account &acc) : acc(acc)
    {
    }

    double getBalance() const
    {
        return acc.getBalance();
    }
    void debit(double amount)
    {
        DebitCommand *cmd = new DebitCommand(amount);
        cmd->execute(acc);
        repository.Register(cmd);
    }
    void credit(double amount)
    {
        CreditCommand *cmd = new CreditCommand(amount);
        cmd->execute(acc);
        repository.Register(cmd);
    }

    void undo()
    {
        Command *cmd = repository.Retrive();
        cmd->unexecute(acc);
        delete cmd;
    }
    ~Transaction()
    {
        while (!repository.Isempty())
        {
            Command *cmd = repository.Retrive();
            delete cmd;
        }
    }
};
int main()
{
    Account acc(101, 10000);
    Transaction trans(acc);
    cout << "Balance : " << trans.getBalance() << "\n";
    trans.debit(1000);
    trans.debit(2000);
    trans.debit(3000);
    trans.debit(4000);

    cout << "Balance : " << trans.getBalance() << "\n";
    trans.credit(1000);
    trans.credit(2000);
    cout << "Balance : " << trans.getBalance() << "\n";
    line();
    cout << "Balance : " << trans.getBalance() << "\n";
    trans.undo();
    trans.undo();
    cout << "Balance : " << trans.getBalance() << "\n";

    return 0;
}