#include <iostream>
#include "car.h"
using namespace std;
using namespace Car;

int main()
{
    int magicNumber;
    do
    {
        cout << "Please enter a number: ";
        cin >> magicNumber;

        if (magicNumber == 1) Lamborghini::output();
        else if (magicNumber == 2) Porsche::output();
        else cout << "Please enter a number between 1 and 2" << std::endl;
    } while (magicNumber != 1 && magicNumber != 2);

    return EXIT_SUCCESS;
}
// g++ -I include/ -o main main.cpp car.cpp