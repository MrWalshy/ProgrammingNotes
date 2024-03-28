#include <iostream>
#include "Coordinates2D.h"
#include "CoordinateTracker.h"

int main()
{
    CoordinateTracker tracker(10);
    
    std::cout << "tracker.coordinates[0] = " << tracker.coordinates[0].getLatitude();
    std::cout << ", " << tracker.coordinates[0].getLongitude() << std::endl;

    Coordinates2D newCoordinate(5, 10);
    tracker.coordinates[0] = newCoordinate;

    std::cout << "tracker.coordinates[0] is now: " << tracker.coordinates[0].getLatitude() << ", " << tracker.coordinates[0].getLongitude() << std::endl;

    return EXIT_SUCCESS;
}
// g++ -I include -o main main.cpp Coordinates2D.cpp CoordinateTracker.cpp