#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H
#include <map>
#include <string>

namespace Accounting
{
    struct UserAccount
    {
        int balance;
        int daysSinceRegistered;
    };

    void computeAnalytics(std::map<std::string, UserAccount>& accounts);
}
#endif