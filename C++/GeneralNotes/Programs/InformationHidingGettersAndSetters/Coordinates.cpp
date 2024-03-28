#include "Coordinates.h"

void Coordinates::setLatitude(float latitude)
{
    this->latitude = latitude;
}

void Coordinates::setLongitude(float longitude)
{
    this->longitude = longitude;
}

float Coordinates::getLatitude()
{
    return this->latitude;
}

float Coordinates::getLongitude()
{
    return this->longitude;
}