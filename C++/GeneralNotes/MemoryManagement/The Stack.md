## The call stack
In C++, and many other languages, a **call stack** exists in which function calls *stack* upon each other:

```cpp
void foo() {}
void bar() { foo(); }
void foobar() { bar(); }
```

When `foobar()` is invoked from the main function, the first part of the call stack looks like:

```cpp
foobar()
main()
```

A **stack frame** is added for each invoked function, and removed when that function finishes. Each stack frame is responsible for tracking the invoked function and the local variables defined within it.

The `foobar()` function then invokes the `bar()` function, which updates the stack with a new frame:

```cpp
bar()
foobar()
main()
```

The `bar()` function then invokes `foo()`:

```cpp
foo()
bar()
foobar()
main()
```

Once the function at the top of the stack has finished, it is removed from the stack and any automatic variables defined within it are destroyed by calling the destructor of the type:

```cpp
bar()
foobar()
main()
```

This process continues until no more functions are on the stack, when the main function finishes, the program exits:

```cpp
foobar()
main()

// foobar finished
main()

// main finished, program exits
```

## Stack allocated memory
Each frame on the stack has memory available to store locally defined variables, this is the same for all objects that are not defined using dynamic memory. When the function finishes execution, it is removed from the stack and any local automatic variables are destroyed to release their memory.

Typically, the size of the stack is decided by the operating system and compiler settings. Commonly, this size is 1-2MB of space. This is enough space for small objects, but often isn't enough for large objects or collections. Going over the stacks limit, whether by too many function calls (too many stack frames) or through too many allocated large objects, a **stack overflow** will occur and cause the program to crash or encounter bugs.

This process of automatic variables being destroyed upon a functions exit is why a pointer or reference to a local variable cannot be returned without causing undefined behaviour:

```cpp
int* foo()
{
	int bar{10};
	return &bar;
}

int main()
{
	int* num { foo() };
	std::cout << num << std::endl; // garbled output or something else
}
```

The undefined behaviour occurs because the pointer returned no longer points to valid allocated memory for the `int` object, the memory for it was deallocated. This results in a **dangling pointer**.

Returning by value prevents this from occurring by copying or moving the object, modern compilers often have optimisations for move semantics to reduce the performance effect associated with this when it is possible to use the move semantics (`std::move`):

```cpp
std::string foo()
{
	std::string fooStr { "Hello World" };
	return fooStr;
}

int main()
{
	std::string result { foo() };
}
```

- When the expression after the `return` keyword is evaluated in `foo()`, the value will be copied or moved.
- If copied, the copy constructor will typically be used to create a new object of the same type and then copy the state of the object `fooStr` into it.
- If move semantics are used instead, a transfer of *memory ownership* occurs. The memory containing the object owned by `fooStr` will be assigned to `result`. The original `fooStr` object may remain valid, but in an unspecified state and should be re-initialised with a new value before using again; the object it once owned is now owned by `result`.
- The caller will receive the returned value, which can then be assigned to a variable or used in an expression.
- If the returned object was a temporary object (rvalue), its destructor will typically be called at the end of the expression it is within. These temporary objects would be created during the evaluation of the `return` expression. The return value of `foo()` is a temporary object, rvalue, but move semantics are used to prevent an unnecessary copy of the object when it is stored in `result`.

