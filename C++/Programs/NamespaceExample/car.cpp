#include <iostream>
#include "car.h"

namespace Car
{
    namespace Lamborghini
    {
        void output()
        {
            std::cout << "Congratulations! You deserve the Lamborghini." << std::endl;
        }
    }

    namespace Porsche
    {
        void output()
        {
            std::cout << "Congratulations! You deserve the Porsche." << std::endl;
        }
    }
}