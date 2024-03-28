The **Map** and **Multimap** containers manage key/value pairs as elements, the elements are sorted automatically according to the provided comparator and applied to the key; the value does not influence the elements order.

Maps allow associating a single value with a key, multimaps allow associating multiple values with the same key. The classes are defined in the `<map>` header file.

- `insert()`: Inserts a value into a map with an associated key. Returns a pair containing the position at which the element was inserted and a Boolean set to `true` if the element was inserted and `false` if an element with the same key already exists.
- `find()`: Looks for a key in a map and returns the position of the key/value pair if it exists, or the same result of calling `end()` if it doesn't exist.
- `at()`: Returns a value associated with a given key, throws an exception if no associated value exists.
- `operator[]`: An alternative to `at()` for returning a value associated with a key. If no such key exists, a new key/value pair is inserted with the given key and a default value for the value. Cannot be used on a `const std::map` as it may modify the map by inserting into it.

Using the `position` returned by calling `find()`, the key can be accessed with `position->first` and the value with `position->second`:

```cpp
#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<int, std::string> map;
	map.insert(std::make_pair(1, "some text"));

	auto position = map.find(1);
	if (position != map.end())
	{
		std::cout << "Found! Key is " << position->first << ", value is " << position->second << std::endl;
	}
}
```

- `std::make_pair(key, value)` is used to create a pair for inserting into a map.