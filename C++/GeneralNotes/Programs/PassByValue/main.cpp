#include <iostream>

void new_age_in_years(int age, int years)
{
    age += years;
    std::cout << "You will be age " << age << " in " << years << " years." << std::endl;
}

int main()
{
    new_age_in_years(25, 5);

    return 0;
}