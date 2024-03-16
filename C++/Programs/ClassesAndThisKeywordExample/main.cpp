#include "PrintName.h"

int main()
{
    PrintName namePrinter;
    namePrinter.setName("MrWalshy");
    namePrinter.printName();

    return 0;
}
// g++ -I include -o main main.cpp PrintName.cpp