Arrays are contiguous data structures containing a series of elements of the same type, they can be individually accessed by their position.

- Arrays have a fixed size, this size cannot be changed once created. This gives them greater runtime performance but comes at the expense of reduced flexibility.

## Array declaration
Arrays are declared using the following syntax:

```cpp
type name[elements];
```

- `type` is the type of the elements within the array
- `name` is the identifier of the array variable
- `elements` is the length of the array, specified as an integer. It must be a constant expression known at compile time, this is because the amount of memory to allocate for the array is static and needs to be calculated ahead of time (AOT).

## Array initialisation
The elements of an array can be initialised at declaration using a pair of braces, the number of elements can be omitted in this case as it can be inferred from the number of elements initialised with:

```cpp
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[] = { 1, 2, 3, 4, 5 };
```

If the number of elements is provided, but the array is initialised with fewer elements, then the remaining values are *zero-initialised*:

```cpp
int foo[5] = { 1, 2 };
```

Arrays can also be initialised after their declaration:

```cpp
int foo[5];

foo[5] = { 1, 2, 3, 4, 5 };
```

## Accessing array values
The values of an array are accessed by their position, this is known as its index:

```cpp
arr_name[index]
```

This can be used to either read an element from the array or overwrite the value of a specific position:

```cpp
int foo[] = { 1, 2, 3, 4, 5 };
foo[0] = 10;
int x = foo[0]; // 10
```

> The first-element in an array has the position of `0`, this is known as *zero-based indexing*.

Using an index which is out of the bounds of an array is syntactically correct in C++, this is because it is defined as *undefined behaviour* in the specification. Doing this can result in runtime errors from accessing an unallocated location in memory and even cause the program to terminate with a segmentation fault due to trying to access memory not owned by the program.