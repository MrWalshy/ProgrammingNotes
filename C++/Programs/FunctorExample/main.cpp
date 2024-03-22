#include "AddX.h"
#include <iostream>

int main()
{
    AddX addFive(5);
    std::cout << "addFive(10) = " << addFive(10) << std::endl;

    return EXIT_SUCCESS;
}
// g++ -I include/ -o main main.cpp AddX.cpp