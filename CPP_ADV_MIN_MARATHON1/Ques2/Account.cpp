#include "Account.h"
 

double Account::getbalance() const {
    return total_balance;
}

void Account::debit(double amount){
    total_balance-=amount;

}
void Account::credit(double amount){
    total_balance+=amount;
}
