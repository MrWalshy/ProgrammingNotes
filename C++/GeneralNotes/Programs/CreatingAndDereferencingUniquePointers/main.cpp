#include <iostream>
#include <memory>

struct SomeType
{
    int a;
    int b;

    SomeType(int a, int b): a{a}, b{b} 
    {
        std::cout << "Creating SomeType obj with a=" << a << " and b=" << b << std::endl;
    }

    ~SomeType()
    {
        std::cout << "Destroying SomeType obj with a=" << a << " and b=" << b << std::endl;
    }
};

int main()
{
    auto ptr1 = std::make_unique<SomeType>(10, 20);
    auto ptr2 = std::make_unique<SomeType>(30, 40);

    std::cout << "ptr1.a: " << (*ptr1).a << std::endl;
    std::cout << "ptr2.a: " << ptr2->a << std::endl;

    return EXIT_SUCCESS;
}