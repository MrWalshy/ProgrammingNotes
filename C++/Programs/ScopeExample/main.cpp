#include <iostream>

// In the global scope (outer scope)
int global_variable = 30;
int hidden_global = 10;

int main()
{
    // in the local scope (inner scope)
    int local_variable = 20;
    int hidden_global = 5;

    std::cout << "global_variable: " << global_variable << std::endl;
    std::cout << "local_variable : " << local_variable << std::endl;
    std::cout << "hidden_global  : " << hidden_global << std::endl;

    return EXIT_SUCCESS;
}
// g++ -o main main.cpp