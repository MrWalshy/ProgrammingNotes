#include <iostream>
#include <string>
#include <memory>

struct Mount
{
    std::string name{"Horse"};
    int speed{15};
};

class Character
{
    public:
        // default constructor
        Character(): mount(std::make_unique<Mount>()) {}

        // copy constructor
        Character(const Character& src): mount(std::make_unique<Mount>(*src.mount)) {}

        // copy assignment operator
        Character& operator=(const Character& src)
        {
            if (this != &src)
            {
                mount = std::make_unique<Mount>(*src.mount);
            }
            
            return *this;
        }

        std::unique_ptr<Mount> mount;
};

int main()
{
    Character character1;
    Character character2;

    character1.mount->name = "Large Eagle";
    character2 = character1;
    character2.mount->name = "Bold Lion";

    std::cout << "Character 1 Mount address: " << character1.mount.get() << std::endl;
    std::cout << "Character 2 Mount address: " << character2.mount.get() << std::endl;
    std::cout << "Character 1 Mount name: " << character1.mount->name << std::endl;
    std::cout << "Character 2 Mount name: " << character2.mount->name << std::endl;
}