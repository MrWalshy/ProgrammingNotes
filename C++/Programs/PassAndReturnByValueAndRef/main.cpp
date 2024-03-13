#include <iostream>
#include <array>

// pass by value and return by value, return by ref would cause an error if trying to use the reference of a temp object. No need to pass by value.
int sum(int a, int b)
{
    return a + b;
}

// returned reference is to object that remains alive as its from the array
// - returned reference is needed if wanting to modify the value in the array
// looks like the array arguments don't need to be references as they are objects, the returned reference works maybe due to their lifetimes?
// - the solution for this activity states that it should be references for the array arguments
/*
    Returns the greater of the two elements at a given index between two arrays, index must be less than 10.
*/
int& greatest_of(std::array<int, 10> &arr1, std::array<int, 10> &arr2, int index)
{
    if (arr1[index] > arr2[index]) return arr1[index];
    else return arr2[index];
}

int main()
{
    std::array<int, 10> numbers1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::array<int, 10> numbers2 = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    int &greatest = greatest_of(numbers1, numbers2, 3);

    std::cout << "numbers2[3]: " << numbers2[3] << std::endl;
    std::cout << "greatest: " << greatest << std::endl;

    greatest = 50;
    std::cout << "modified greatest: " << greatest << std::endl;
    std::cout << "numbers2[3]: " << numbers2[3] << std::endl;
}