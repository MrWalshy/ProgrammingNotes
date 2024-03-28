#include "Apple.h"
#include "AppleTree.h"

int main()
{
    AppleTree tree;
    Apple apple = tree.createApple();
    return 0;
}
// g++ -I include/ -o main main.cpp Apple.cpp AppleTree.cpp