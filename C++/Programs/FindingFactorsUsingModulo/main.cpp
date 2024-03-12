#include <iostream>

int main()
{
    // A factor of 7 is a number evenly divisible by 7, has a remainder of 0
    unsigned int count;
    unsigned int FACTOR = 7;
    unsigned int MAX_RANGE = 100;

    for (int i = 1; i < MAX_RANGE; i++)
    {
        if (i % FACTOR == 0)
        {
            std::cout << i << " is a factor of 7." << std::endl;
            count++;
        }
    }
    std::cout << "Between 1 and " << MAX_RANGE << ", there are " << count << " factors of 7.";

    return EXIT_SUCCESS;
}