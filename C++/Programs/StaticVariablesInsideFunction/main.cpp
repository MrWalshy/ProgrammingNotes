#include <iostream>

void squares()
{
    static int count = 1;
    int x = count * count;

    std::cout << count << "*" << count;
    std::cout << ": " << x << std::endl;
    count++;
}

int main()
{
    // the `count` static variables value persists across calls. First call it is 1, second call it is 2, etc... It is only initialised once to 1
    for (int i = 1; i < 11; i++) squares();
    return EXIT_SUCCESS;
}