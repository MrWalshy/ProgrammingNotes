The `pair` and `tuple` classes store a collection of heterogenous elements, the `pair` class can hold two values of two types and the `tuple` class extends this to of any length.

- `pair` is defined in the `<utility>` header and `tuple` in the `<tuple>` header.

## Pairs

The constructor for `pair` takes two types as template parameters, used to specify the types for the first and second values. The elements can be accessed directly using the `first` and `second` data members, or with the `get<0>()` and `get<1>()` functions:

```cpp
std::pair<int, int> somePair(1, 10);
int secondValue = somePair.second;
int firstValue = std::get<0>(somePair);
```

The `make_pair()` convenience function can be used to make a pair without explicitly specifying types too:

```cpp
std::pair<std::string, int> nameAndAge = std::make_pair("John", 32);
```

Pairs are used by the following to manage key/value elements:
- unordered maps
- unordered multimaps
- maps
- multimaps

## Tuples
Tuples are similar to pairs, the constructor allows for providing a variable number of template arguments though. The elements can only be accessed with the `std::get<N>()` function, a convenience function for creating them also exists called `make_tuple()`.

```cpp
#include <iostream>
#include <tuple>
#include <string>

int main()
{
	std::tuple<std::string, int, float> james = std::make_tuple("James", 7, 1.9f);
	std::cout << "Name: " << std::get<0>(james) << ". Agent number: " << std::get<1>(james) << std::endl;
}
```