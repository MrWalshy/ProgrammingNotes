#include "Height.h"
#include <iostream>

Measurements::Height::Height(double inches): inches(inches) {}

void Measurements::printFeet(Height h)
{
    std::cout << "Your height in inches is: " << h.inches << std::endl;
    std::cout << "Your height in feet is: " << h.inches * 0.083 << std::endl;
}