#include "math3d.h"
#include <cmath>
#include <array>

const float PI = 3.14f;

namespace Math3D
{
    int distance(int i1, int i2)
    {
        return std::abs(i2 - i1);
    }

    float distance(float f1, float f2)
    {
        return std::abs(f2 - f1);
    }

    float circumference(float radius)
    {
        return 2 * PI * radius;
    }

    float distance(const std::array<float, 3> &point1, const std::array<float, 3> &point2 = {0,0,0})
    {
        float calculatedDistance =
            std::pow(distance(point1[0], point2[0]), 2) +
            std::pow(distance(point1[1], point2[1]), 2) +
            std::pow(distance(point1[2], point2[2]), 2);
        return std::sqrt(calculatedDistance);
    }

    float totalDistance(const std::array<std::array<float,3>, 10> &points)
    {
        float dist = 0;
        // sub 1 off the max as adding the current vector and 1 ahead
        for (int i = 0; i < 10 - 1; i++)
        {
            dist += distance(points[i], points[i+1]);
        }
        return dist;
    }
}