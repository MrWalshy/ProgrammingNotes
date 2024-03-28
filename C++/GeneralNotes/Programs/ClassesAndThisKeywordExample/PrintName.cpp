#include "PrintName.h"
#include <string>
#include <iostream>

void PrintName::setName(const std::string &name)
{
    this->name = name;
}

void PrintName::printName()
{
    std::cout << this->name << std::endl;
}