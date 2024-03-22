#ifndef HEIGHT_H
#define HEIGHT_H
namespace Measurements
{
    class Height
    {
        double inches;

        public:
        Height(double value);
        friend void printFeet(Height);
    };

    void printFeet(Height h);
}
#endif