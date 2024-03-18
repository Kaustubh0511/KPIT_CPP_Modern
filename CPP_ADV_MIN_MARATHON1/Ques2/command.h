#ifndef COMMAND_H
#define COMMAND_H

#include "Account.h"
class command
{
protected:
    double _amount{0};
    command(double amount) : _amount(amount) {}

public:
    command(const command &) = delete;
    command(command &&) = delete;
    command &operator=(const command &) = delete;
    command &operator=(const command &&) = delete;

    virtual void execute(Account &) = 0;
    virtual void unexecute(Account &) = 0;

    virtual ~command() = default;
};

#endif // COMMAND_H