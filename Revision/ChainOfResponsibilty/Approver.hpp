#ifndef APPROVER_HPP
#define APPROVER_HPP

#include <iostream>
using namespace std;
#define line(msg) cout << "----------------" #msg "----------------\n";
class Approver
{
    Approver *successor{nullptr};

protected:
    void RequestSuccessor(int amount);

public:
    void set_successor(Approver *successor);
    operator Approver *() { return this; }
    virtual void process_loan(int amount) = 0;
};

#endif // APPROVER_HPP
