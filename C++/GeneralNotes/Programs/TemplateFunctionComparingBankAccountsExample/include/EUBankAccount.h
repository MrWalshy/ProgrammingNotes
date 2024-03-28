#ifndef EU_BANK_ACCOUNT_H
#define EU_BANK_ACCOUNT_H
#include <string>

namespace Banking
{
    struct EUBankAccount
    {
        std::string IBAN;
        int amount;
    };
}
#endif