#include <iostream>

int main()
{
    // Right-angle triangle
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}