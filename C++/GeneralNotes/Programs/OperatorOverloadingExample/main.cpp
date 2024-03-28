#include "Point.h"
#include <iostream>

int main()
{
    // set the boolalpha format flag so 1 is printed as true and 0 as false
    std::cout << std::boolalpha;

    Point p1;
    Point p2(10,10);
    Point p3 = p1 + p2;

    std::cout << "p1: " << p1.getX() << "," << p1.getY() << std::endl;
    std::cout << "p2: " << p2.getX() << "," << p2.getY() << std::endl;
    std::cout << "p3: " << p3.getX() << "," << p3.getY() << std::endl;

    std::cout << "p1 < p2: " << (p1 < p2) << std::endl;
    std::cout << "p2 < p3: " << (p2 < p3) << std::endl;

    return EXIT_SUCCESS;
}
// g++ -I include -o main main.cpp Point.cpp