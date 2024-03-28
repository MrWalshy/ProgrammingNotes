#include <array>
#include <vector>
#include <iostream>

int main()
{
    // === array example ===
    std::array<int, 10> arr;

    // initialise array using for loop
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = i + 1;
    }
    arr.front() = 10;
    arr.back() = 1;

    std::cout << "arr.front(): " << arr.front() << std::endl;
    std::cout << "arr.back(): " << arr.back() << std::endl;

    // === vector example ===
    std::vector<int> users;
    users.reserve(100);
    users.resize(10);

    for (int i = 0; i < users.size(); i++)
    {
        users[i] = i + 1;
    }
    std::cout << "users.front(): " << users.front() << std::endl;
    std::cout << "users.back(): " << users.back() << std::endl;

    return 0;
}