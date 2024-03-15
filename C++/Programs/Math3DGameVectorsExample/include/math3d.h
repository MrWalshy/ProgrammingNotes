#ifndef MATH_3D
#define MATH_3D
#include <array>

// Vector here represented as `std::array<float, 3>` of {x,y,z}
namespace Math3D
{
    int distance(int i1, int i2);
    float distance(float f1, float f2);
    float distance(const std::array<float,3> &point1, const std::array<float,3> &point2);
    float circumference(float radius);
    float totalDistance(const std::array<std::array<float,3>, 10> &points);
}

#endif