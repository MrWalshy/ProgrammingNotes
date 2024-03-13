Functions can return values to the caller for use in a program, the return type is specified at the start of a function. Within the function body, the `return` keyword is used to indicate that a value is to be returned.

```cpp
int sum(int a, int b)
{
	return a + b;
}

int main()
{
	int result = sum(10, 10);
	
	return 0;
}
```

The `return` keyword can be used in a `void` returning function to end a function early rather than return a value as well:

```cpp
void ageCheck(int age)
{
	if (age < 18)
	{
		std::cout << "You are too young." << std::endl;
		return;
	}
	else
	{
		std::cout << "You are old enough." << std::endl;
	}
	// implicit return to caller
}
```

Functions returning `void` return to their caller at the end of the functions execution by default.

> Programs can be compiled with functions expected to return a value that do not do so, it is suggested to turn on compiler warnings to warn you of this.

## Return by value

Functions who return a value type are said to *return by value*. When the `return` keyword is reached, the program creates a new object initialised from the value of the expression in the return statement:

```cpp
int sum(int a, int b)
{
	return a + b; // inits a new integer object
}
```

The caller of such a function receives a *temporary automatic object* which is created and initialised from the value returned. In the case of `int result = sum(10, 20);`, it is initialised with the integer created from summing `a` and `b`.

- The object is *temporary* as its lifetime is valid only while the full-expression in which it is created is executed.

The calling code can use the temporary value in other expressions or assign it to a value. At the end of the expression, `sum(10, 20)`, the temporary object is destroyed.

> It is preferred to return by value as its often easier to understand and as fast as returning by reference. C++11 allows the `move` semantic to be used to move instead of copy return types when they support the `move` operation. Before C++11, all mainstream compilers implemented *return value optimisation (RVO)* and *named return value optimisation (NRVO)* where the return value of a function is constructed directly in the variable into which it would have been copied on return. C++17 made this optimisation mandatory, it is known as **copy elision**.

## Return by reference

A function which returns a reference is said to *return by reference*. When a function returning a reference reaches the `return` statement, a new reference is initialised from the expression in the `return` statement.

The function call expression in the caller is **substituted** by the returned reference.

In this situation, it is very important to consider the lifetime of the object the reference refers to. Consider:

```cpp
const int& max(const int& a, const int& b)
{
	if (a > b) return a;
	else return b;
}
```

As it stands, the `max` function is returning by value and does not make a difference if `a` or `b` is returned when equal.

There is a caveat. If the reference returned is non-`const` in nature, then it could matter to the caller which reference (`a` or `b` when `a == b`) is returned as the caller may modify the the object referred to by the returned reference.

Consider this usage:

```cpp
const int& a = max(1, 2);
std::cout << a;
```

This would result in an error as `1` and `2` are temporary values which are destroyed when the full expression they are used in ends. There are four expressions making up the full expression:

- `1` is an integer literal
- `2` is also an integer literal
- `max(expression1, expression2)` is a function call expression
- `a = expression3` is an assignment expression (this is the end of the full expression)

The lifetimes of `1` and `2` end at the end of the assignment, which results in an illegal reference. Accessing an object whose lifetime is terminated is prohibited in C++, resulting in an invalid program. Assigning the value rather of the reference than the reference would be legal though (`int a = max(1, 2)`).

Another common mistake in returning references is returning the reference of a local automatic object, a local variables lifetime always ends when the function ends and thus the reference will always be illegal:

```cpp
int& sum(int a, int b)
{
	int c = a + b;
	return c;
}
```

This similarity persists when returning points, the object pointed to needs to be alive when the pointer is later dereferenced.

A common example of when returning a reference is legal is when accessing part of an object, such as using `std::array`:

```cpp
int& getFirst(std::array<int, 3> &array)
{
	return array[0];
}
```

The calling code would look like:

```cpp
int main()
{
	std::array<int, 3> array = { 1, 2, 3 };
	int& firstElement = getFirst(array);
	firstElement = 10; // modified the value of the first element
	return 0;
}
```

This is legal as the returned reference is to an element inside the array which continues existing, the array outlives the returned reference.

Two guidelines for using return by reference correctly:
- Never return a reference to a local variable (or part of it).
- Never return a reference to a parameter accepted by value (or a part of it).

When returning a reference received as a parameter, the argument passed must live longer than the returned reference.