#include <iostream>

int main()
{
	std::cout << "Hello world!" << std::endl;

	// chaining the << operator
	std::cout << "Name: "
		<< "Fred, "
		<< "Aged 22"
		<< std::endl;

	return EXIT_SUCCESS;
}