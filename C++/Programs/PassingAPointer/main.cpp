#include <iostream>

void modify_pointer(int *pointer)
{
    *pointer = 1; // modifying the object's value in memory
    pointer = 0; // modifying the local pointer variable, not seen outside
}

int main()
{
    int a = 0;
    int *ptr = &a;

    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "&a: " << &a << std::endl; 
    std::cout << "a before call: " << a << std::endl;

    modify_pointer(ptr);

    std::cout << "a after call: " << a << std::endl;
    std::cout << "ptr value: " << *ptr << std::endl;
    std::cout << "Did the pointer change? " << std::boolalpha << (ptr == &a) << std::endl; // SHould this be "Did the pointer not change?"
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "&a: " << &a << std::endl; 

    return 0;
}