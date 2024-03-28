#include <iostream>

const int& max(const int &a, const int &b)
{
    if (a > b) return a;
    else return b;
}

int main()
{
    // const int& a = max(1, 2); // illegal as 1 and 2s lifetime ends with the full expression and thus a legal reference cannot exist.
    const int a = max(1, 2); // legal as only assigning the returned value of the reference rather than a reference itself
    std::cout << "a: " << a << std::endl;
    return 0;
}