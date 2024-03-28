Temporary objects cannot be passed as arguments for reference parameters, `const` references or *r-value* references must be used instead.

- r-value references are identified by two ampersands (`&&`) and can only refer to temporary values.
When passing a pointer to a function, the pointer is a value type representing an objects location in memory. Pointers are *pass by value*, meaning any modification to the pointer will not be visible to the caller. Modifying the object a pointer points to will be reflected in the calling code though.

```cpp
void modify_pointer(int *pointer)
{
	*pointer = 1; // modifies the object the pointer refers to
	pointer = 0; // modifies the local variable, not reflected outside this func
}

// int a = 0; modify_pointer(&a);
```

Passing a pointer can be thought of as passing a reference, the main difference is that the pointer might be `null`.

Accepting a parameter as a point is used mainly for one of three reasons:

- Traversing an arrays elements. Done by providing the start pointer of the array and either the end pointer or the size of the array.
- Optionally modifying a value within the called function.
- Returning more than a single value. Often done to set the value of a pointer passed as an argument and return an error code to signal whether the operation was performed.

Generic Programming and Templates introduced in C++11 and C++17 can be used to avoid pointers for some of these use cases, eliminating some common errors such as dereferencing invalid pointers or accessing unallocated memory.