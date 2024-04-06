The `constexpr` and `consteval` specifiers can be used to ensure expressions are evaluated at compile time, this can improve performance by removing the need for expensive expressions to be calculated at runtime.

## Compile Time Constants (`constexpr`)
As templates are instantiated at compile time, any arguments to the templates must be known at compile time as well. The `constexpr` specifier indicates that a variable or function can be evaluated at compile time, it is short for *constant expression*.

- **Compile time evaluation**:
	- When applied to a variable, `constexpr` specifies that the variable's value is computed at compile time.
	- When applied to a function, `constexpr` specifies that the function can be executed at compile time if invoked with constant expressions as arguments.
- **Constant expressions**:
	- A variable declared with `constexpr` must be initialised with constant expressions (like literals) known at compile time.
	- A function used with `constexpr` must have a return value computable at compile time when called with constant expressions as arguments.

Variables declared using `constexpr` cannot be reassigned to at runtime, their value is calculated at compile-time and then treated as a constant for the remainder of the programs lifetime. They also cannot have a value assigned to them by a function *unless* that function is also declared with `constexpr`. This also adds rules to the function that it cannot be used for anything that cannot be done at compile time, including calling other functions unless they are also declared as `constexpr`:

```cpp
constexpr int square(int x) { return x * x; }

int main()
{
	constexpr int num = 5;
	constexpr int result = square(num);
}
```

This can be useful in templates, like when trying to pass the value of a variable (non-type parameter) to a template:

```cpp
template<typename T, int Size>
struct SomeContainer
{
	int size{Size};
};

int main()
{
	constexpr int defaultSize { 10 };
	SomeContainer<int, defaultSize> aContainer;
}
```

A function declared with the `constexpr` could be used instead;

```cpp
constexpr int getDefaultSize() { return 10; }

int main()
{
	SomeContainer<int, getDefaultSize()> aContainer;
}
```

## Immediate functions

