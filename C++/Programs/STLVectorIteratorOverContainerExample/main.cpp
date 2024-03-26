#include <vector>
#include <iostream>

int main()
{
    std::vector<int> balances = {10,34,32,83,45,44,93,73,79};

    for (auto position = balances.begin(); position != balances.end(); position++)
    {
        std::cout << "Balance: " << *position << std::endl;
    }

    return EXIT_SUCCESS;
}