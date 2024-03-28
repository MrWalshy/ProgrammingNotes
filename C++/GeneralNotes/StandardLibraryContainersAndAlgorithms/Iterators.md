Iterators are a way in which an elements position in a container is represented, they provide a consistent way of operating on a containers elements while abstracting the containers details.

Iterators belong to a range, the iterator representing the start of the range can be accessed by the `begin()` function. The iterator representing the end of the range can be obtained with the `end()` function.

- The range where the first element is included, but where the last one is excluded, is referred to as *half-open*.

The interface of an iterator is composed of four functions:

1. `*`: Provides access to the element at the position currently referenced.
2. `++`: Moves to the next element.
3. `==`: Used to compare two iterators to check if they are pointing at the same position, two iterators can only be compared if they are part of the same range (position of elements of the same container).
4. `=`: Used to assign an iterator.

Every C++ container class must include the type of iterator which provides access to its members as a member type alias named `iterator`. A vector of integer would be the type `std::vector<int>::iterator`.

```cpp
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numbers = { 1, 2, 3 };
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << "Number: " << *it << std::endl;
	}
}
```

Range-based iterators (`for (type identifier : container)`) actually work based on iterators, the compiler will rewrite them to be an iterator; range-based for loops work with any type providing the `begin()` and `end()` functions and return iterators.

Iterators can be grouped into four categories:
- **Input**: Iterator which steps forward, can be used only in a single pass. Iterator can be copied, but when a copy is incremented or dereferenced to access an element, all other other copies are invalidated and cannot be used anymore. Input iterators provided the `==` and `!=` operators to check for equality with the `end()` value
- **Forward**: Iterator which steps forward, can be used in multiple passes. The same iterator can be dereferenced several times to access the element it points to, when a forward iterator is incremented or dereferenced it doesn't invalidate any copies. This allows for making copies which refer to different elements in a container. Two iterators referring to the same element are guaranteed to be equal.
- **Bidirectional**: Iterator that can step forward and backward. These are forward iterators with the `operator--` (position decrement) member function available to move backwards.
- **Random-access**: Iterator that can step forward and backwards to arbitrary positions in constant time. These are bidirectional with the addition of being able to randomly access any position without a linear scan. These are provided by the `operator[]` member function to access elements at generic indexes, the binary `operator+` and `operator-` can be used to step forwards and backwards by some quantity.

## Reverse iterators
Sometimes, reverse iteration is needed; the *reverse iterator* allows for this. A reverse iterator wraps a bidirectional iterator and swaps the operation increment with the operation of decrement, and vice versa.

The range of a container can be reversed by calling one of two methods on a container:

- `rbegin()`: Returns the position of the last element of the container.
- `rend()`: Returns the position before the first element of the container.

```cpp
std::vector<int> numbers = {1,2,3,4,5};

for (auto rit = numbers.rbegin(); rit != numbers.rend(); rit++)
{
	std::cout << "The number is: " << *rit << std::endl;
}
```

### Insert iterators
**Insert iterators**, also known as **inserters**, insert new values into a container instead of overwrite them. There are three types which differ on the position they insert elements at:

- **Back inserter**: Appends a value at the end of the container by calling the `push_back()` function.
- **Front inserters**: Inserts a value at the beginning of the container by calling the `push_front()` function.
- **General inserts**: Inserts a value at a given position by calling the `insert()` function.

## Stream iterators
**Stream iterators** allow using streams as a source to read elements from or as a destination to write to. Iterator functions include:

- `IStream`: Reads elements from an input stream.
- `OStream`: Writes values to an output stream.

As there is no container for these iterators, the `end()` method cannot be called to get the `end` iterator. A default constructed stream iterator counts as the end of any stream range.

Stream iterators could be used to read integers from the standard input as an example:

```cpp
std::istream_iterator<int> iterator = std::istream_iterator<int>(std::cin);
std::istream_iterator<int> end;

for (; iterator != end; iterator++)
{
	std::cout << "The number is: " << *iterator << std::endl;
}
```

- an include for `<iterator>` is needed.

## Iterator invalidation
Iterators can be invalidated in various ways, so it is important to check the invalidation contract when using a containers iterators.

- In the case of a container that moves elements when one is inserted or removed, this will invalidate an iterator as its not pointing at its intended target. This is especially the case with vectors, where all of the iterators might be invalidated due to the allocation of a new memory segment on some insertions.
- In the case of lists (linked lists), only the predecessor and successor nodes are updated but the element stays at the same position. This means any insertions or deletions do not invalidate an iterator.