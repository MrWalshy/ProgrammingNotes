#include <iostream>

const int POSITION = 10; // desired fibonacci number
const int ALREADY_COMPUTED = 2; // starting point, first fibonacci numbers are 0 and 1

void print_tenth_fibonacci()
{
    int n_1 = 0; // n_1 initialised
    int n_2 = 1; // n_2 initialised
    int current = n_1 + n_2; // current initialised

    for (int i = ALREADY_COMPUTED; i < POSITION; i++)
    {
        n_1 = n_2;
        n_2 = current;
        current = n_1 + n_2;
    }
    // current destroyed
    // n_2 destroyed
    // n_1 destroyed
    std::cout << "Tenth fibonacci number: " << current << std::endl;
}

int main()
{
    print_tenth_fibonacci();
}