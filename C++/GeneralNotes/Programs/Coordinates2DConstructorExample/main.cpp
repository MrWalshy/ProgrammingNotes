#include <iostream>
#include "Coordinates2D.h"

int main()
{
    Coordinates2D coords(10, 20);
    std::cout << "latitude = " << coords.getLatitude() << ", longitude = " << coords.getLongitude() << std::endl;

    return EXIT_SUCCESS;
}
// g++ -I include -o main main.cpp Coordinates2D.cpp