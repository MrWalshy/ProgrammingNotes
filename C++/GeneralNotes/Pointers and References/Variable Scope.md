The live area of a program where a variable name has a particular meaning is known as its **scope**. A scope is delimited in C++ by curly braces, the area denoted is known as a **block**.

Any entity declared outside of any and all blocks resides in the **global scope** and can be used anywhere in the code:

```cpp
Type Global_Variable = Value;

Type main()
{
  Type Local_Variable = Value;
}
```

The same name can be declared in two different scopes and refer to different entities. A name is visible once it is declared until the end of the block in which it is declared.

## Example

```cpp
#include <iostream>

// In the global scope (outer scope)
int global_variable = 30;
int hidden_global = 10;

int main()
{
    // in the local scope (inner scope)
    int local_variable = 20;
    int hidden_global = 5;
    
    std::cout << "global_variable: " << global_variable << std::endl;
    std::cout << "local_variable : " << local_variable << std::endl;
    std::cout << "hidden_global  : " << hidden_global << std::endl;

    return EXIT_SUCCESS;
}
```

This demonstrates three different things:

- A global variable of an outer scope can be accessed in an inner scope
- A local variable can not be accessed outside of its scope
- Global variables can be hidden by variables with the same name in an inner scope