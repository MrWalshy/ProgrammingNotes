#ifndef COORDINATES_H
#define COORDINATES_H
class Coordinates2D
{
    private:
    float latitude;
    float longitude;

    public:
    Coordinates2D();
    Coordinates2D(float latitude, float longitude);
    float getLatitude();
    float getLongitude();
};
#endif