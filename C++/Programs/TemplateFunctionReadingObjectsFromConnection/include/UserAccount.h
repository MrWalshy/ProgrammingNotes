#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H
#include <array>
#include <iostream>

class UserAccount
{
    public:
        static std::array<char, 100> serialize(const UserAccount& account);
        static UserAccount deserialize(const std::array<char, 100>& blob);
};
#endif