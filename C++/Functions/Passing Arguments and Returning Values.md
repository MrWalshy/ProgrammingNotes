The caller of a function can pass data as arguments to a functions parameters, the parameters form part of the signature. A function can also return data to its caller, this is not part of the signature but is part of the function header.

## Passing arguments
The parameter list of a function is like that in other statically typed languages, each parameter requires a type and local variable name where each parameter is separated by a comma:

```cpp
void two_ints(int, int);
```

A function declaration does not require the names to be specified, they are optional here. They must be specified in its definition though. The parameters can be named though in the declaration if wanted:

```cpp
void two_ints(int a, int b);
```

The body of the function can access the values of the function parameters once the function has been invoked. To call a function that takes parameters, pass the values for each parameter in a comma-separated list within the parenthesis:

```cpp
two_ints(10, 20);
```

Arbitrary expressions which evaluate to a value can also be passed as an argument as it is the value they evaluate to which will be assigned to the functions local variable:

```cpp
two_ints(5 + 5, 10 + 10);
```

The order in which the expressions are evaluated is not specified though, this means a call like `two_ints(i++, i++)` given `int i = 0` could result in either `two_ints(0, 1)` or `two_ints(1, 0)` being invoked.

> It's better to declare expressions that change a programs state as its own statement, call functions ideally with expressions which do not mutate state.

### Pass by value
When a functions parameter is a value type, the function takes an argument by value - the argument is *passed by value*.

- Value type parameters will have a new local object created each time the function is invoked.
- The lifetime of a value type parameter object is to the end of the function's scope.
- When a value type is passed, a new copy of the original value is created as an object for the argument; this prevents the original variable/value from the caller from being modified.

Passing by value should be preferred over other options unless required, this creates a layer of separation between the invoker and invoked function where the invoking code cannot see what changes the function makes on its parameters.

1. As the calling function, we know that the variables we passed to the functions will not be modified by it.
2. As the called function, we know that even if we modify the provided parameters, there will be no impact on the called function.

C++11 added a `move` semantic which can overcome the limitation where pass by value may be expensive as it creates a whole new object, it can be efficient and fast though for small values.

```cpp
#include <iostream>

void doSomething(int a)
{
	a += 10;
	std::cout << "It's number " << a << std::endl;
}

int main()
{
	int a = 5;
	doSomething(a);
	// a is still 5 here, modifications inside doSomething() do nothing to 'a' here
	return 0;
}
```

## Pass by reference

If the parameter type of a function is a reference type, the functions takes an argument by reference; the argument is *passed by reference*.

Passing an argument by reference does not create a new object, it is just a new variable (name) referring to an object which already exists. This means the function has access to the object that the calling code provided, it can modify and read it.

> Unless the function must modify the variable, always use `const` references.

```cpp
#include <iostream>

void byref_in_5_years(int& age)
{
    age += 5;
}

int main()
{
    int age = 15;
    byref_in_5_years(age);
    if (age > 18) std::cout << "Older than 18 in 5 years." << std::endl;

    return 0;
}
```

- The speed of the program is not affected when passing by reference, unlike pass by value, as the memory size of the object passed does not change (it is not duplicated).

Pass by reference is the preferred method when copying an object since pass by value can be expensive.

> When passing by reference but not modifying the passed object, always use the `const` qualifier.