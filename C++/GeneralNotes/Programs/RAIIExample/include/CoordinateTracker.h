#ifndef COORDINATE_TRACKER_H
#define COORDINATE_TRACKER_H
#include "Coordinates2D.h"

class CoordinateTracker
{
    public:
    CoordinateTracker(int size);
    ~CoordinateTracker();
    Coordinates2D* allocateMemory(int size);
    void releaseMemory(Coordinates2D* coordinates);
    Coordinates2D* coordinates;
};
#endif