#include <iostream>
#include <array>
#include "math3d.h"

int main()
{
    std::array<float, 3> v1 = {3, 0, 1};
    std::array<float, 3> v2 = {18, 250, 35};

    std::cout << "Distance between v1 and v2 is: " << Math3D::distance(v1, v2) << std::endl;

    std::array<std::array<float, 3>, 10> points = {{
        {0,0,0},
        {1,0,0},
        {1,1,0},
        {0,1,0},
        {0,1,1}
    }};
    std::cout << "Total dist: " << Math3D::totalDistance(points);

    return EXIT_SUCCESS;
}
// g++ -I include -o main main.cpp math3d.cpp