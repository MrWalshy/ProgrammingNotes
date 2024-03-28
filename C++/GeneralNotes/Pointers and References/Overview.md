Variables can be used to access a value in memory by a name, allowing the programmer to not have to remember the memory location and size reserved.

C++ allows for the retrieval of a variables actual physical memory address by preceding the variable name with an ampersand (`&`), this is the **address-of operator**:

```cpp
&variable_name;
```