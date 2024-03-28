#include "UserAccount.h"
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

// void Accounting::computeAnalytics(std::map<std::string, Accounting::UserAccount>& accounts)
void Accounting::computeAnalytics(std::map<std::string, UserAccount>& accounts)
{
    // extract the accounts
    std::vector<Accounting::UserAccount> newAccounts;
    auto getSecondInPair = [](const std::pair<std::string, Accounting::UserAccount>& user) { return user.second; };
    std::transform(accounts.begin(), accounts.end(), std::back_inserter(newAccounts), getSecondInPair);

    // remove those older than 15 days
    auto greaterThan15 = [](const Accounting::UserAccount& user) { return user.daysSinceRegistered > 15; };
    auto newEnd = std::remove_if(newAccounts.begin(), newAccounts.end(), greaterThan15);
    newAccounts.erase(newEnd, newAccounts.end());

    // print data
    for (const Accounting::UserAccount& account : newAccounts)
    {
        std::cout << account.balance << std::endl;
    }
}
