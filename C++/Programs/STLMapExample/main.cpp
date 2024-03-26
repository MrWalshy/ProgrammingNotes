#include <string>
#include <map>
#include <iostream>

// program to find balance of a user given their username
int main()
{
    std::map<std::string, int> balances;
    balances.insert(std::make_pair("Alice", 50));
    balances.insert(std::make_pair("Bob", 50));
    balances.insert(std::make_pair("Charlie", 50));

    auto bobPosition = balances.find("Bob");
    if (bobPosition != balances.end()) std::cout << "Bob exists and has a balance of " << bobPosition->second << std::endl;

    return EXIT_SUCCESS;
}