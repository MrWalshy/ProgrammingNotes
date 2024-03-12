A function body is a code block which can contain valid statements, one of those is a **variable definition**. This statement inside a function declares as **local variable**. 

The difference between a local and global variable is in the *scope* in which it is declared, and thus who can access it.

> Local variables can only be seen in the function they are declared in, global variables can be accessed by any function which can see them.

Local variables are preferred due to **encapsulation**, only the code inside the function can access and modify the variable which makes it invisible to the rest of the program. Encapsulation is typically used for three separate reasons:

- Restricting access to data.
- Bundling data and functionality that operates on it.
- Key concept in creating abstractions.

> Always use the `const` qualifier, wherever possible, with global variables to prevent unintended modification. Avoid mutable globals.

## Working with variable objects
There is a distinct relationship between variables, objects, and the lifetime of objects in C++:

- An **object** is a piece of data in the program's memory.
- A **variable** is a name given to an object.

The scope of a variable and the lifetime of the object referred to are distinct concepts, the scope of a variable indicates where that specific variable can be used. The lifetime of an object is the time during execution where the object is valid to access and use.

The following demonstrates trying to access an object when its lifetime has ended, alongside accessing an object still in its lifetime:

```cpp
// returns a pointer, accepts a pointer as input
int* foo(const int* other)
{
	int fooLocal = 0 + *other; // legal access of a variable still within its lifetime
	return &fooLocal; // bad as fooLocal lifetime ends after function ends
}

int main()
{
	int mainLocal = 10;
	int* fooPointer = foo(&mainLocal);
	// should access content of fooPointer, it's not valid
	return 0;
}
```

The lifetime of a variable starts when it is initialised and ends when its containing block ends. Even if a pointer or reference to the variable can be accessed, it should not be used unless it is still valid. `fooPointer` is pointing to a variable that is no longer valid in the above example, so it should not be used.

When a local variable is created in a function scope, the compiler automatically creates an object when the function reaches that declaration; the variable refers to that object.

When a global variable is declared, it is declared in a scope without a clear duration and thus is valid for the entire duration of the program. Due to this, the compiler creates global variable objects when the program starts before any functions are executed (including `main()`).

The compiler also handles the termination of an object's lifetime when execution exits from the scope a variable is declared in, or when the program terminates in the case of global variables. This termination of an objects lifetime is typically called **destruction**.

Variables declared in a scope block (local or global) are called **automatic variables** as the compiler handles initialising and terminating the lifetime of the object associated with the variables.

When a local variable is declared, the compiler automatically initialises an object  using **default initialisation** when execution reaches that statement, the object is destroyed at the end of the function:

```cpp
void foo()
{
	int a;
}
```

> The default initialisation of primitive types like integers does nothing, this means `a` will have an unspecified value in the above example.

If there are multiple local variable definitions, the objects are initialised in order of declaration:

```cpp
void foo()
{
	int a;
	int b;
}
```

This also means that variable `b`, in the above example, is destroyed before the one that `a` refers to as it is initialised after `a`.

If execution never reaches a variable declaration, the variable will never have an object initialised and thus never destroyed:

```cpp
void foo()
{
	if (false)
	{
		int a;
	}
	int b;
}
```

