#include <iostream>

class Coordinates
{
    public:
    Coordinates() 
    {
        std::cout << "Called constructor." << std::endl;
    }

    ~Coordinates()
    {
        std::cout << "Called destructor." << std::endl;
    }
};

int main()
{
    Coordinates c;
}