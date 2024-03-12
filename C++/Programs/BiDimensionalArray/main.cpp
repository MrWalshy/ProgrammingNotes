#include <iostream>

int main()
{
    int arr[3][3];

    // init each position in the array using x * y
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            arr[x][y] = x * y;
            std::cout << "arr[x][y]: " << arr[x][y] << std::endl;
        }
    }

    return EXIT_SUCCESS;
}