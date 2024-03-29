It is possible to set a function to be *deleted* when trying to call it with specific types, this results in a compile error during the the argument matching process.

To do so, the `= delete` specifier is used to indicate that the function with some specific type cannot be invoked. This does not mean the function doesn't exist, just that its forbidden to be invoked with a certain type:

```cpp
void print(int);
void print(char) = delete; // calls with a char halt compilation

// main
print(20); // ok
print('a'); // compiler error, deleted function
```

A template function can be used to prevent all non-matching overloads if that is required:

```cpp
void print(int);

template <typename T>
void print(T) = delete;
```

Only calls to `print(int)` would be legal, all other types passed would cause a compile-time error.