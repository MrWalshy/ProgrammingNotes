#include <iostream>
#include <utility>
#include <string>

using Contact = std::pair<std::string, std::string>;

void logContact(const Contact& contact)
{
    std::cout << "Name: " << contact.first << ", Number: " << contact.second << std::endl;
}

int main()
{
    Contact fred { "Fred", "+447432403852"};
    logContact(fred);
}