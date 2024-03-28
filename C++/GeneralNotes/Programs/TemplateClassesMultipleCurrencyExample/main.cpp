#include "currency.h"
#include "UserAccount.h"
#include <iostream>

int main()
{
    UserAccount<GBP> gbpAcc1(GBP(100));
    UserAccount<GBP> gbpAcc2(GBP(200));

    std::cout << "gbpAcc1: " << gbpAcc1.balance.value << std::endl;
    std::cout << "gbpAcc2: " << gbpAcc2.balance.value << std::endl;

    std::cout << "Adding 200 to gbpAcc1" << std::endl;
    gbpAcc1.addToBalance(GBP(200));
    std::cout << "gbpAcc1: " << gbpAcc1.balance.value << std::endl;

    return EXIT_SUCCESS;
}