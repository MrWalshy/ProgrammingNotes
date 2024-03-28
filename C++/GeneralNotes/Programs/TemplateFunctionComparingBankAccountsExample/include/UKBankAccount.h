#ifndef UK_BANK_ACCOUNT_H
#define UK_BANK_ACCOUNT_H
#include <string>

namespace Banking
{
    struct UKBankAccount
    {
        std::string sortCode;
        std::string accountNumber;
        int amount;
    };
}
#endif