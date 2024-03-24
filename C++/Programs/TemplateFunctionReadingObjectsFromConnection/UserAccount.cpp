#include "UserAccount.h"

std::array<char, 100> UserAccount::serialize(const UserAccount& account)
{
    std::cout << "User account has been serialised" << std::endl;
    return std::array<char, 100>(); 
}

UserAccount UserAccount::deserialize(const std::array<char, 100>& blob)
{
    std::cout << "Deserialised user account" << std::endl;
    return UserAccount();
}