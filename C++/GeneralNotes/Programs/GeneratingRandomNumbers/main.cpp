#include <iostream>
#include "Random.h"

int main()
{
    std::cout << "Seed: ";
    Random::printSeed();
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Random num between 1 and 10: "
            << Random::integer(1, 10) << std::endl;
    }
}
// g++ -I include/ -o main main.cpp Random.cpp