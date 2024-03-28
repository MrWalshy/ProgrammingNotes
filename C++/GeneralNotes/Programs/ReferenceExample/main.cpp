#include <iostream>

int main()
{
    int num = 30;
    int &num_ref = num;

    std::cout << "num: " << num << std::endl;
    std::cout << "num_ref: " << num_ref << std::endl;

    return 0;
}
// g++ -o main main.cpp