Sometimes, exceptional conditions may occur in the program when it is running; these are called **exceptions**, they are a response to a circumstance outside of what is expected during the programs runtime and must be handled to prevent the program crashing.

Exceptions can be thrown using the `throw` keyword, this process is known as **raising an exception**.

The `try` keyword, followed by a block of statements, is used when some code might throw one or more exceptions. The `try` block is followed by one or more `catch` clauses which handle the possible exceptions:

```cpp
try
{
	statement1;
}
catch (exception-declaration-1)
{
	statement2;
}
catch (exception-declaration-3)
{
	statement3;
}
```

## Example

```cpp
#include <iostream>

int main()
{
	int x = 10;
	try
	{
		std::cout << "Inside try" << std::endl;
		
		if (x > 0) throw x;
	}
	catch (int x)
	{
		std::cout << "Inside catch, exception caught" << std::endl;
	}
	std::cout << "Outside try-catch" << std::endl;
	
	return EXIT_SUCCESS:
}
```