#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

Point Point::operator+(const Point &other)
{
    Point newPoint(x + other.x, y + other.y);
    return newPoint;
}

bool Point::operator<(const Point &other)
{
    if (x < other.x) return true;
    else if (x == other.x && y < other.y) return true;
    return false;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}