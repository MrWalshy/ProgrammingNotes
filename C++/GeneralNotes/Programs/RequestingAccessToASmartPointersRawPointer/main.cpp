#include <memory>
#include <iostream>

int foo(int* ptr)
{
    return 10 + *ptr;
}

int main()
{
    auto num { std::make_unique<int>(10) };
    std::cout << "num address: " << num.get() << std::endl;
    std::cout << "num value  : " << *num << std::endl;

    int result = foo(num.get());
    std::cout << "foo() returned " << result << std::endl;
}