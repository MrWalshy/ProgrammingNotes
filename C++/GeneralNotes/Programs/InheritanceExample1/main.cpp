#include "Ferrari250GT.h"
#include <iostream>

int main()
{
    Ferrari250GT ferrari;
    std::cout << "Ferrari value: " << ferrari.getValue() << std::endl;
    // ferrari.getTankCapacity(); cannot invoke as inherited with protected specifier

    return EXIT_SUCCESS;
}
// g++ -I include/ -o main *.cpp