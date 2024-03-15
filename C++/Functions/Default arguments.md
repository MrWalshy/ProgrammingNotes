C++ allows functions to provide default arguments, this can make calling some functions easier. The default arguments are added to the function declaration using the assignment operator and a supplied value:

```cpp
int multiply(int number, int multiplier = 1);
```

- Any default arguments must come after the non-default arguments.
This allows the method to be called with and without the second argument:

```cpp
multiply(10); // same as multiply(10, 1)
multiply(10, 2);
```

It is best practice to set default arguments in the function signature declaration and not in the definition.