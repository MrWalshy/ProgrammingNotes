**Dynamic memory**, often called the **heap**, is an area of memory that a program can use to store objects. Objects stored in dynamic memory have their lifetimes managed by the program.

Programs interact with the operating system to request pieces of dynamic memory for object storage, these pieces of memory must be returned to the operating system.

There are two keywords in C++ for interacting with dynamic memory, `new` and `free`. The `new` expression creates a new object in dynamic memory, it returns a pointer to the requested type:

```cpp
Car* myCar = new myCar();
```

The object pointed to by `myCar` can be used until it is then deleted. This kind of object creation has some benefits:
- The object can be created while inside a function and returned successfully as the lifetime is not automatic, automatic objects are destructed when their scope ends.
- The memory space required for the object can be created ahead of time and let other functions initialise it.

To delete the object from dynamic memory, use the `delete` keyword before the variable name (which is a pointer):

```cpp
delete myCar;
```

This calls the destructor of the object pointed to by the pointer, then gives the memory back to the operating system.

This differs from automatic variables, trying to delete a pointer to an automatic variable will result in an error:

```cpp
Car myCar; // automatic variable
delete &myCar; // error and likely crash
```

Forgetting to call the `delete` function on an object created with `new` will cause two major problems:

- The memory is not returned to the operating system, which is known as a **memory leak**.
- The destructor of the object will not be called.

Multiple `delete` calls on a pointer should also not be made, this is because all calls but the first will be made on memory that they should not be accessing.

It is important that virtual destructors are defined in base classes that are derived from, this is because the destructor of the runtime type is called when calling the `delete` function on the base object and dynamic dispatch needs to occur to ensure the destructor on the derived type is called.

## Creating arrays in dynamic memory
Dynamic memory can also be created for arrays of objects, the `new[]` and `delete[]` expressions need to be used for this case:

```cpp
int n = 15;
Car* cars = new Car[n];
delete[] cars;
```

This would create enough memory space for `n` `Car` instances and initialise them, returning a pointer to the first created element. As no arguments are provided to the constructor, default constructors must also be available.

The use of `new[]` differs from `std::array` and the standard built-in array, this is because `n` can be decided at runtime.

## Returning a pointer from a function
```cpp
Logger* createLogger()
{
	if (testsRunning())
	{
		TestLogger* logger = new TestLogger();
		return logger;
	}
	else
	{
		ReleaseLogger* logger = new ReleaseLogger("Release logger");
		return logger;
	}
}
```

As the function returns a pointer to an object in dynamic memory, the calling code needs to make sure to delete this pointer and free up the memory when it is no longer needed:

```cpp
Logger* logger = createLogger();
myOperation(logger, arg1, arg2);
delete logger;
```

