#include "Visitor.h"
#include <iostream>

void Visitor::operator()(const std::string& value)
{
    std::cout << "A string: " << value << std::endl;
}

void Visitor::operator()(const int& value)
{
    std::cout << "An int: " << value << std::endl;
}