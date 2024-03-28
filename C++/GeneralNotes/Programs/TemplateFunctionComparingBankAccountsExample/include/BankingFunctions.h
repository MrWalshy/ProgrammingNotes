#ifndef BANKING_FUNCTIONS_H
#define BANKING_FUNCTIONS_H
namespace Banking
{
    template<typename BankAccount>
    int getMaxAmount(const BankAccount& account1, const BankAccount& account2)
    {
        if (account1.amount > account2.amount) return account1.amount;
        else return account2.amount;
    }
}
#endif