#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "DB.hpp"

template <typename T>
class Account
{
    DB *db{nullptr};

public:
    void setDB(DB *d)
    {
        this->db = d;
    }
    void DoJob(int Accid, int amount)
    {
        db->OpenDB();
        ((T *)this)->DoDebit(Accid, amount);
        db->CloseDB();
    }
};

#endif // ACCOUNT_HPP
