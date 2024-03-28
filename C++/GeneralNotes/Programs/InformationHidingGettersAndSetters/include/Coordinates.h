#ifndef COORDINATES_H
#define COORDINATES_H
class Coordinates
{
    private:
    float latitude;
    float longitude;

    public:
    void setLatitude(float);
    void setLongitude(float);
    float getLatitude();
    float getLongitude();
};
#endif