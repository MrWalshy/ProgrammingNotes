Classes can also have static members indicated by the `static` keyword, these are values or functions not associated with any instance of a class. They can be used directly through the class name.

Declaring a static member looks like:

```cpp
class ClassName
{
	static Type memberName;
}
```

The static member is stored in memory, but not the memory of an instance; static members are instead stored in a similar way to a *global variable*.

In a `.cpp` file outside of the class in which the static variable is declared, its value can be defined using the syntax:

```cpp
ClassName::memberName = value;
```

> It is best practice to define a `static` variables value in a `.cpp` file rather than a header file otherwise the definition will be included anywhere inside the header, this would then create multiple definitions and the linker would complain.

Like global variables, the lifetime of a static variable is for that of the complete duration of the program. Static methods also exist, they can only call other static methods and static fields inside a class.

Static variables can also be declared inside a function, this results in it being initialised only once during the first call to the function, the space like static members is allocated once for the entire program duration, its visibility means its only accessible within the scope of the function, and the variables value persists across multiple function calls.
## Example

```cpp
// Coordinates.h
class Coordinates
{
	float latitude = 0;
	float longitude = 0;

	public:
		static const Coordinates someLocation;
}

// In some .cpp file
const Coordinates Coordinates::hearthCenter = Coordinates(0, 0);
```

The double colon (`::`) is known as the **scope resolution operator** and allows for accessing the static members of a class in this case.

> Always use the `const` qualifier when declaring static fields. In programs that use multiple threads, common bugs can occur by modifying static fields from different threads at the same time.

