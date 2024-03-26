#include "Visitor.h"
#include <iostream>
#include <variant>

int main()
{
    std::variant<std::string, int> variant = 42;
    Visitor visitor;

    std::cout << "Variant contains ";
    std::visit(visitor, variant);

    variant = "Hello world";
    std::cout << "Variant contains ";
    std::visit(visitor, variant);

    return EXIT_SUCCESS;
}
// g++ -I include/ -o main main.cpp Visitor.cpp