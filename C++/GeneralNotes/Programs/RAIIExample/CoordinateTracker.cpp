#include "CoordinateTracker.h"
#include "Coordinates2D.h"
#include <iostream>

CoordinateTracker::CoordinateTracker(int size) 
{
    coordinates = new Coordinates2D[size];
    std::cout << "Created new array of size " << size << std::endl;
}

CoordinateTracker::~CoordinateTracker()
{
    if (coordinates != nullptr) releaseMemory(coordinates);
    else std::cout << "Memory already released" << std::endl;
}

Coordinates2D* CoordinateTracker::allocateMemory(int size)
{
    releaseMemory(coordinates); // Release memory to avoid memory leak
    coordinates = new Coordinates2D[size];
    std::cout << "Created new array of size " << size << std::endl;
    return coordinates;
}

void CoordinateTracker::releaseMemory(Coordinates2D* coordinates)
{
    delete[] coordinates;
    std::cout << "Destroyed array" << std::endl;
}
