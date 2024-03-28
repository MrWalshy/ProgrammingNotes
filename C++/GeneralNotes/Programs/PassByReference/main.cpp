#include <iostream>

void byref_in_5_years(int& age)
{
    age += 5;
}

int main()
{
    int age = 15;
    byref_in_5_years(age);
    if (age > 18) std::cout << "Older than 18 in 5 years." << std::endl;

    return 0;
}