// Given a map that has a username as a key and a user account as a value, print the balances of 
// the new users in descending order. A user is considered new if they registered no more than 15 days ago.
#include <map>
#include "UserAccount.h"
#include <string>

int main()
{
    std::map<std::string, Accounting::UserAccount> users = {
        {"Alice", Accounting::UserAccount{500, 15}},
        {"Bob", Accounting::UserAccount{1000, 50}},
        {"Charlie", Accounting::UserAccount{600, 17}},
        {"Donald", Accounting::UserAccount{1500, 4}}
    };
    Accounting::computeAnalytics(users);
}
// g++ -I include/ -o main main.cpp UserAccount.cpp