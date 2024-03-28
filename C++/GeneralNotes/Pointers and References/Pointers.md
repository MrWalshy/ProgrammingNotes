A data structure which can store a variables memory address is called a **pointer**, these always *point* to an object of a specific type. This means the type of the object being pointed to needs to be declared when declaring a pointer:

```cpp
type * pointer_name
```

Multiple declarations can be done via the comma operator, each pointer declaration will require its own asterisk though:

```cpp
type *pointer1, *pointer2;
```

The following shows an example where the two declared variables on the same line have different types, one is a pointer and the other is not:

```cpp
type *pointer, variable;
```

> Regardless of the variable type pointed to, a pointer always occupies the same size in memory. This is because a pointer does not care about the size of the pointed to data type, it is a memory address whose size is dictated by the platform (platform-dependant).

## Pointer assignment

Pointer assignment uses the same syntax as for variable assignment:

```cpp
pointer_name = &variable_name;
```

This would copy the memory address of `variable_name` into the pointer called `pointer_name`.

It is also possible to assign a pointer to a variable to another pointer variable:

```cpp
type *pointer1 = &variable_name;
type *pointer2 = pointer1; // &pointer1 would be illegal, a pointer doesn't have a memory address to point to
```

This results in both `pointer1` and `pointer2` holding the same memory address of `variable_name`.

To create a pointer which points to another pointer, use the code:

```cpp
type **pointer_name;
```

Two asterisks indicate the **type** pointed to is now a pointer.

## Accessing the content pointed to by a pointer

The **dereference operator**, an asterisk, can be used before a pointer or memory address to access the value at a given memory address:

```cpp
type variable1 = value;
type *pointer1 = &variable1;
type variable2 = *pointer1;
```

The value contained by `variable2` is the same as `variable1`.

The value of a variable can be changed by dereferencing a pointer as well:

```cpp
type variable = value1;
type *pointer = &variable;
*pointer = value2;
```