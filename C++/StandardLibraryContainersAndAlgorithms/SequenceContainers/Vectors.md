A vector container is similar to an array, a data structure of contiguous elements. It differs in that its size can be dynamically modified at runtime and does not require a specific size at compile time. The `Vector` class is defined in the `<vector>` header file.

Vectors, like arrays, use a singular section of memory. When adding a new element to the vector:

- There is enough space left over and the element is directly added.
- There is not enough space, so a new section of memory is allocated with a larger size, then all of the old vectors members are copied over, and the new element is added after the last element.

Most of the methods are similar to the array container, some differences include:

- `push_back()` can be used to append elements.
- `insert()` can be used to insert elements at some position.
- `pop_back()` can be used to remove/pop the last element.
- `erase()` can be used to remove an element at a some position.

Appending or deleting the last element is fast, inserting or removing other elements is considered slow as the other elements have to be moved in memory to allow for this.

Don't confuse the `size()` and `capacity()` methods, the former represents the current number of elements in the vector while the latter is the maximum number of elements that can be inserted in the current section of memory.

The operation of which new memory is allocated is called *reallocation*, it is expensive though. Due to this, the `reserve()` member can be used to reserve enough memory for some given number of elements. The capacity can be reduced to fit the number of elements using the `shrink_to_fit()` member, this releases any memory not needed any more.

```cpp
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> myVector;
	myVector.push_back(100); // appends 100 to vector
	myVector.push_back(10); // appends 10. front is now 100 and back is 10

	myVector.front() -= myVector.back(); // subtract 10 from 100 and assign

	std::cout << "Front: " << myVector.front() << std::endl; // Front: 90
	std::cout << "Back: " << myVector.back() << std::endl; // Back: 10
}
```