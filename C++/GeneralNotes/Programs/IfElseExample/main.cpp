#include <iostream>

int main()
{
    int x = 5;

    if (x > 10) std::cout << "'x' is greater than 10." << std::endl;
    else if (x > 5) std::cout << "'x' is greater than 5 but less than 10." << std::endl;
    else std::cout << "'x' is less than 5." << std::endl;

    return EXIT_SUCCESS;
}