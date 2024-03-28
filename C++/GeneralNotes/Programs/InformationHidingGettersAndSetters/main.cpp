#include "Coordinates.h"
#include <iostream>

int main()
{
    Coordinates somewhere;
    somewhere.setLatitude(13.4f);
    somewhere.setLongitude(18.44f);

    std::cout << "Latitude: " << somewhere.getLatitude();
    std::cout << ", Longitude: " << somewhere.getLongitude() << std::endl;

    return EXIT_SUCCESS;
}
// g++ -I include -o main main.cpp Coordinates.cpp