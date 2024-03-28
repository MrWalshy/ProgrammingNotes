A **set** is a container of unique sorted elements, **multisets** allow duplicate elements. Both are defined in the `<set>` header file.

Both have `size()` and `empty()` member functions to check how many elements are contained and whether any elements are contained.

Insertion and removal is done using the `insert()` and `erase()` functions, they do not take a position argument though as the order is determined by a comparator. Insertion and removal are both fast.

As sets are optimised for element lookup, special search functions are provided:

- `find()`: returns the position of the first element equal to the provided value, or position past the end of the set when the element is not found.
- When using `find()`, always compare with the result of calling `end()` to check whether the element was found

```cpp
#include <iostream>
#include <set>

int main()
{
	std::set<int> numbers;
	numbers.insert(10);

	if (numbers.find(10) != numbers.end())
	{
		std::cout << "10 is in numbers" << std::endl;
	}
}
```

The `count()` member returns the number of elements equal to the value provided.

A custom comparator for sorting can be provided if wanted:

```cpp
#include <iostream>
#include <set>
#include <functional>

int main()
{
	std::set<int> ascending = { 5, 3, 4, 2, 1 };
	std::cout << "Ascending numbers:";
	for (int number : ascending) std::cout << " " << number;
	std::cout << std::endl;
	// Ascending numbers: 1 2 3 4 5

	std::set<int, std::greater<int>> descending = { 5, 3, 4, 2, 1 };
	std::cout << "Descending numbers:";
	for (int number : descending) std::cout << " " << number;
	std::cout << std::endl;
	// Descending numbers: 5 4 3 2 1
}
```

