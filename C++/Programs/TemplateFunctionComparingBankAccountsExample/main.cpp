#include <iostream>
#include "EUBankAccount.h"
#include "UKBankAccount.h"
#include "BankingFunctions.h"

using namespace Banking;

int main()
{
    EUBankAccount euAccount1{"IBAN1", 1000};
    EUBankAccount euAccount2{"IBAN2", 2000};
    std::cout << "The greater amount between EU accounts is: " << getMaxAmount(euAccount1, euAccount2) << std::endl;

    UKBankAccount ukAccount1{"SORT1", "ACC1", 5000};
    UKBankAccount ukAccount2{"SORT2", "ACC2", 4000};
    std::cout << "The greater amount between UK accounts is: " << getMaxAmount(ukAccount1, ukAccount2) << std::endl;

    return EXIT_SUCCESS;
}
// g++ -I include -o main main.cpp