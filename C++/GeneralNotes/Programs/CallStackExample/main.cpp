#include <iostream>

int i = 1;

void foo()
{
    std::cout << ++i << ") foo() invoked" << std::endl;
    std::cout << i-- << ") foo() finished" << std::endl;
}

void bar()
{
    std::cout << ++i << ") bar() invoked" << std::endl;
    foo();
    std::cout << i-- << ") bar() finished" << std::endl;
}

void foobar()
{
    std::cout << ++i << ") foobar() invoked" << std::endl;
    bar();
    std::cout << i-- << ") foobar() finished" << std::endl;
}

int main()
{
    std::cout << "Higher number means higher on the stack" << std::endl;
    std::cout << i << ") main() invoked" << std::endl;
    foobar();
    std::cout << i << ") main() finished" << std::endl;

    return EXIT_SUCCESS;
}