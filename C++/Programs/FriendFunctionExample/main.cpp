#include "Height.h"

using namespace Measurements;

int main()
{
    Height h(83);
    printFeet(h);
    
    return 0;
}
// g++ -I include/ -o main main.cpp Height.cpp