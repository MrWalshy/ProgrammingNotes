The `const` qualifier can be used with parameters and return types independently of whether the type is a reference or not.

## Pass by `const` value
In pass by value, the function parameter is a value type where the passed argument is *copied* into the parameter. Regardless of whether `const` is used or not, the calling code cannot see any difference.

> The only reason to use `const` in the function signature is to document that the implementation cannot modify the value of the parameter.

This is not commonly done even if the function does not modify the parameters as the function signature is mainly there to act as an interface/contract that the implementer understands.

The exception to this is when a function accepts a **pointer**, this prevents the assigning of a new value to a pointer. The pointer acts in a similar way to a reference as it cannot be bound to a new object but provides nullability. Consider:

```cpp
void setValue(int *const param);
```

This function takes a `const` pointer to an `int` as an argument, the pointer itself cannot be changed but the integer it refers to can be.

## Pass by `const` reference
In pass by reference, the `const` qualifier is important and should be added if the function is not designed to modify the reference. The reasoning is that a reference allows you to modify the provided object freely, this is error-prone as the caller might not be expecting the referred object to be modified.

> A function cannot modify an object through a `const` reference

Another advantage of `const` reference parameters is that temporary objects can be used as arguments for them.

## Returning by `const` value
Returning by `const` value has no real use in most cases as the caller will often assign the result of the function call to a variable, the `const`-ness of the variable is what decides whether the copied temporary object will be modifiable or not.

Returning by `const` will also inhibit the `move` semantic of C++11, reducing performance.

## Returning by `const` reference
When a returned reference is only meant to be read and not modified by the caller, a function should return by `const` reference.

The same concept applied to object lifetimes when returning references to them also applies to `const`:

- When returning a reference accepted as a parameter, if the parameter is a `const` reference, the returned reference must be `const` as well.
- When returning a reference to a part of an object accepted as the `const` reference parameter, the returned reference must be `const` as well.

A reference parameter should be returned as `const` if the calling code is not expected to modify it.

The following signature demonstrates a function that modifies a reference parameter, it does not use `const` because of this:

```cpp
void setItem(std::array<int, 10> &array, int item, int position);
```

In a function that does not modify the array though, it would be made a `const` reference:

```cpp
int findLargest(const std::array<int, 10> &array);
```