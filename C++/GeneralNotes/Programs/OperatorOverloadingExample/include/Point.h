#ifndef POINT_H
#define POINT_H
class Point
{
    public:
        Point();
        Point(int x, int y);

        Point operator+(const Point &other);
        bool operator<(const Point &other);

        int getX();
        int getY();

    private:
        int x;
        int y;
};
#endif