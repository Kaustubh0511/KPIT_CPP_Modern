#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    int _AccId{0};
    double total_balance{0};
public:

    Account() = default;
    Account(const Account&) = delete;
    Account(Account&&) = delete;
    Account& operator=(const Account&) = delete;
    Account& operator=(const Account&&) = delete;
   
    double getbalance() const;

    void debit(double);
    void credit(double);


    Account(int AccId,double balance):_AccId(AccId),total_balance(balance){}
    ~Account()=default;
    
};

#endif // ACCOUNT_H