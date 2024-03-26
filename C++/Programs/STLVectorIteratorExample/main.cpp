#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {1,2,3,4,5};
    auto iterator = numbers.begin();

    std::cout << *iterator << std::endl; // deref: points to 1
    iterator++; // increment: now points to 2
    std::cout << *iterator << std::endl;

    // random access: access the 2th element after the current one
    std::cout << iterator[2] << std::endl;
    --iterator; // decrement: points to 1 again
    std::cout << *iterator << std::endl;

    // advance by multiple positions
    iterator += 4; // now points to 5
    std::cout << *iterator << std::endl;
    iterator++; // advance past last element
    std::cout << "'iterator' is after the last element: " << (iterator == numbers.end()) << std::endl;

    return EXIT_SUCCESS;
}