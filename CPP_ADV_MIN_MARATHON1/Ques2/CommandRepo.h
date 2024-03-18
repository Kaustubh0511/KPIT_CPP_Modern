#ifndef COMMANDREPO_H
#define COMMANDREPO_H

#include <stack>
#include "command.h"

class CommandRepo
{
private:
    std::stack<command *> repo;// To store all the commands

public:
    CommandRepo() = default;
    CommandRepo(const CommandRepo &) = delete;
    CommandRepo(CommandRepo &&) = delete;
    CommandRepo &operator=(const CommandRepo &) = delete;
    CommandRepo &operator=(const CommandRepo &&) = delete;
    ~CommandRepo() = default;

    void Register(command* cmd)
    {
        repo.push(cmd);
    }
    command* retrive()
    {
        command *cmd=repo.top();
        repo.pop();
        return cmd;
    }
    bool IsEmpty()
    {
        return repo.empty();
    }
};

#endif // COMMANDREPO_H