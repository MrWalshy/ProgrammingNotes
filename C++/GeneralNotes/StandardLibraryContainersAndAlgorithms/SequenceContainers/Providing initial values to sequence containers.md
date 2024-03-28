All sequence containers are empty at creation, using member functions for each element would be tedious. Instead, all containers can be initialised with a sequence of elements when they are created:

```cpp
#include <vector>

int main()
{
	std::vector<int> numbers = { 1, 2, 3 };
}
```

The initial sequence is provided using an **initialiser list**, a set of comma-separated values specified within curly braces.