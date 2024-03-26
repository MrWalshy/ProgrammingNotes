All template parameters need to be known at compile-time for a template to be instantiated, not all of them need to be explicitly provided by the caller though. **Template Argument Deduction** is the ability for the compiler to automatically deduce the required types for a templates instantiation without the user explicitly specifying them.

This process is supported for functions in most versions of C++. C++17 introduced **deduction guides** to allow template argument deduction for class templates from the constructor.

In general, the compiler will attempt to find the type for which the provided argument and the parameter match the closest:

```cpp
template<typename T>
void foo(T parameter);

// call
foo(argument);
```

## Parameter and argument types

|                      | `foo(1): int` | `int x; foo(x): int&` | `const int x; foo(x): const int&` |
| -------------------- | ------------- | --------------------- | --------------------------------- |
| `void foo(T)`        | `T = int`     | `T = int`             | `T = int`                         |
| `void foo(T&)`       | `Error`       | `T = int`             | `T = const int`                   |
| `void foo(const T&)` | `T = int`     | `T = int`             | `T = int`                         |

The error in the examples from the table occurs because a temporary value, like `1`, can not be bound to a non-`const` reference.

When an argument is passed, the compiler tries to deduce a type which when substituted with the type parameter `T` best fits the argument.

- The compiler might not always be able to deduce a type, an error will be given and its up to the user to specify the type.

The compiler cannot deduce a type for many different reasons:

- The type is not used in the parameters.
- The type in the parameter is a derived type

A good practice when declaring a templates types is to order the types the user is expected to specify before the deduced ones:

```cpp
template<typename C, typename A, typename B>
C foo(A, B);

// usage
float f = foo(10, 20);
```

Default arguments also need to be considered carefully too, the types that the user is more likely to modify should also come earlier in the order.