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

It is best practice to set default arguments in the function signature declaration and not in the definition, i.e., in the header file rather than an implementation file. Once declared, default arguments also cannot be redeclared so they are only written once (in the header file).

## Explicitly using default arguments
Sometimes, you may want to pass an argument to certain parameters but not others that all have default values. Use a pair of braces in positions where you would like the default values to be used:

```cpp
void foo(int x = 1, int y = 2, int z = 3) {}

foo({}, {}, 5); // invoked as foo(1,2,5)
```
