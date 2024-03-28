#include "Coordinates2D.h"

Coordinates2D::Coordinates2D(float latitude, float longitude) : latitude(latitude), longitude(longitude) {}

float Coordinates2D::getLatitude()
{
    return this->latitude;
}

float Coordinates2D::getLongitude()
{
    return (*this).longitude;
}