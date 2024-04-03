## L-Values and R-Values
Expressions can be seen as belonging to one of two value categories, left values (l-values) and right values (r-values):

- Literal values: `"Hello World"`, `50`, `true`
- Variable identifiers: `age`, `name`, `token`
- Function invocations: `func()`
- Values returned by compound expressions: `age + 10`

### L-values
L-value expressions are those which have an identity, like an object or function. If the address-of operator (`&`) returns an address from an expression, it is an l-value.

> L-value expressions are sometimes referred to as **locator values**.

```cpp
int x { 30 };
std::cout << &x << std::endl;
```

The `x` variable is an l-value, its address can be retrieved with the address of operator.

### R-values
R-value expressions are are any that are not an l-value, something that does not have an identity. Literal values are always r-value expressions and do not have a retrievable address:

```cpp
int* x = &30; // error, not an lvalue
```

Function calls and compound expressions made up of operators may return either an l-value or an r-value depending on their implementation.

## Binding r-values to l-values
Typically, r-values cannot be used after the expression in which they are evaluated unless they are stored in an l-value:

```cpp
20 + 2;
int x { 3 + 3 };
```

- In the first expression, `20 + 2`, both `20` and `2` are r-values. The resulting value, `22`, is also an r-value that is discarded immediately after the expression is finished. The individual numbers, `20` and `2`, are also discarded as they are temporary r-values.
- In the second assignment statement, the expression `3 + 3` evaluates to `6`. Both `3`s and the result `6` are r-values, the difference here is that the result is stored in the variable `x` (an l-value). The two `3` r-values are discarded immediately after the expression in which they are evaluated is completed.

## L-Value to R-Value conversions
L-Values and R-Values get the name from the fact that they occur on either the left or right of the assignment operator `=`. Often though, an l-value is used on the right side:

```cpp
int x { 10 };
int y { x + 20 };
```

This works because the compiler implicitly converts l-values to r-values, whether this occurs at compile-time or runtime depends on the code used and the compiler's optimisation capabilities.

In the case of the above example, the compiler can replace `x + 20` with the result `30` at compile time. This is because `x` is a named variable whose value is known at compile time and the expression `x + 20` can be evaluated at compile time. This is known as **compile-time constant folding** or **constant expression evaluation**.

## Functions and Operators
A function name is an l-value, its memory address is retrievable with the `&` operator:

```cpp
void foo() {}

int main()
{
	std::cout << &foo << std::endl;
}
```

`&foo` returns a pointer to a function, a function pointer.

Functions and operators may also return an l-value or an r-value, it depends on the function or operators return type:

- Functions returning by value return an r-value, this is a temporary object that can be copied into a variable using assignment but it cannot be modified nor assigned to. Whether the object is copied, moved, or return value optimisation applies depends on the compiler and context.
- Functions returning by reference or pointer are returning an l-value.

```cpp
int get() { return 10; }

int main()
{
	int (*ptr)() = &get; // valid as `&get` returns an lvalue
	int value = get(); // valid as `get()` returns an rvalue
	int value2 = &get(); // invalid as `get()` returns an rvalue, not an lvalue
}
```

Functions may also return a reference or pointer, these are returning lvalues:

```cpp
int num { 10 };

int& get() { return num; }

int main()
{
	int* value = &get(); // valid as `get()` returns an lvalue
}
```

## L-Value references
In function parameters, references are denoted using the `&` character:

```cpp
void foo(int& x) {}
```

This is specifically an **l-value reference**, attempting to pass an r-value to this parameter would result in a compile-time error:

```cpp
foo(10); // error
```

This is because a non-`const` parameter is one which is expected to be modified, which doesn't make sense for r-value arguments (temporary objects without a persistent identity) given the value will be lost as soon as `foo(10)` finishes executing.

If the passed in argument isn't expected to be modified, specifying it as `const` will allow for r-values to be passed in:

```cpp
void foo(const int& x) {}

foo(10); // valid
```

This is possible because r-values can be bound to `const` references in C++, this is done to extend the lifetime of the temporary object to match the lifetime of the reference.

## R-Value references
R-Value references are denoted by two ampersands, `&&`, in the function parameter:

```cpp
void foo(int& lvalueReference);
void foo(int&& rvalueReference);
```

This allows for overloading functions to accept either an l-value or an r-value, the main practical use case is for *move semantics* - the move constructor and move-assignment operators accept an r-value reference as input.

- L-Values have a longer lifespan than R-Values, they survive after the expression they are used in. This is why copy semantics use an l-value reference parameter, the copy semantics needs to respect that the source object should not be modified.
- R-Values have a short lifespan, move semantics accept objects as r-value references because it is expected that the source object will expire soon; so it allows another object to take control of the resources owned by the source.

## What `std::move()` does...
The `std::move()` function is a bit of a misnomer, it doesn't actually move anything. Instead, it casts its argument to an *r-value reference*. This then influences which function an expression calls:

```cpp
void foo(int&);
void foo(int&&);

int main()
{
	int x { 10 };

	foo(x); // foo(int&), lvalue ref
	foo(std::move(x)); // foo(int&&), rvalue ref
}
```

The casting can also be manually done with `static_cast` instead of using `std::move`:

```cpp
int x { 10 };

foo(x); // foo(int&) lvalue ref
foo(static_cast<int&&>(x)); // foo(int&&) lvalue statically cast to rvalue ref
```

`std::move()` is a simpler syntax to use though for casting to an r-value reference, so it is typically preferred.