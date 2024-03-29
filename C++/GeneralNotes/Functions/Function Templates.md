## Why template?
Template functions reduce code duplication when used appropriately, they allow for a single *template* of a function to be created that can be used across many different types; the template describes what the function looks like.

A defined template has overloaded functions generated as needed by the compiler at compile time by default, this is because the actual type isn't determined by the template but instead when the template is used with some actual data type.

## Defining a function template
Function templates use placeholder types called **type template parameters**/**template types** to represent the parameter types, or types used in the function body. There 3 different kinds of template parameters supported:

- Type template parameters: The template parameter represents a type.
- Non-type template parameters: The template parameter represents a constexpr value.
- Template template parameters: The template parameter represents another template.

```cpp
template <typename T> // template parameter declaration
T min(T x, T y)
{
	return (x > y) ? y : x;
}
```

## Instantiating function templates
A template function is used to generate actual functions by the compiler, that are then compiled and executed. **Function template instantiation** is the process through which this happens.

- The instantiation of the function from a function invocation is called **implicit instation**.
- Functions instantiated from a template are called a **specialisation** (commonly referred to as a **function instance**).
- The template a specialisation is produced from is a **primary template**.

When the `min(T, T)` function is instantiated, the compiler searches for an existing generated function matching the specified type(s). If none are found, it clones the template and replaces the type parameters with the actual type:

```cpp
min<int>(10, 5);

// generates
template<>
int min<int>(int x, int y)
{
	return (x > y) ? y : x;
}
```

The compiler will generate a function of a specific type instantiated per translation unit (cpp file), any further calls in the same translation unit result in calling the same generated function. As this results in duplicate function generations across translation units, the linker uses a process known as "template deduplication" to remove any duplicates and only place a single copy in the final executable.

## Using multiple template types
Sometimes, multiple template types are needed to avoid certain errors occurring. They can also introduce errors though. Template argument deduction does not follow the same rules as function overloading for argument coercion, so a call to the `min` function showed previously like the following would result in an error as it wouldn't be able to set the single type parameter `T` to an appropriate type:

```cpp
min(10, 2.5); // Error
min<double>(10, 2.5); // Ok as specified type to use
```

A better implementation would make use of multiple type parameters:

```cpp
template <typename T, typename U>
T min(T x, U y);
```

The issue here is that a narrowing conversion could occur due to choosing specifically `T` as the return type, and so data loss could occur:

```cpp
min(5, 4.8);
```

This would result in `4` being returned rather than `4.8` as the `double` undergoes a narrowing conversion to an `int` to match the first parameter.

To prevent this, use the `auto` return type to allow the compiler to deduce the return type from the return statement:

```cpp
template <typename T, typename U>
auto min(T x, U y);
```

## Abbreviated function templates
C++20 introduced abbreviated function templates, where `auto` can be used as a parameter type in a normal function. The compiler automatically converts the function into a function template with each auto parameter becoming an independent template type parameter:

```cpp
auto min(auto x, auto y);

// same as

template <typename T, typename U>
auto min(T x, U y);
```

