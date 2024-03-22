#ifndef APPLE_H
#define APPLE_H
// #include "AppleTree.h"

// Forward declaration needed so that the FruitMaker namespace and AppleTree class can be resolved
// without introducing a circular dependency through including AppleTree.h
namespace FruitMaker
{
    class AppleTree;
}

namespace Fruit
{
    // class AppleTree;

    class Apple
    {
        friend class FruitMaker::AppleTree;
        
        private:
        Apple();
    };
}
#endif