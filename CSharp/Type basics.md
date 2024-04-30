A *type* is a blueprint for a value, variables are given a type:

```c#
int x = 3;
string y = "Hello";
```

A variable represents a storage location that can contain different values over time, a *constant* is a variable whose value does not change:

```c#
const int x = 3;
```

## Predefined/built-in types
A predefined type is supported by the compiler, they have literal and object representations in the language:

```c#
int x = 32; // signed int to 32bits
string y = "Hello World"; // sequence of characters
bool z = false; // true or false
```

The `ToString()` method can be called on any type to obtain a string representation of it.

## Custom types
A custom type is one that is user-defined, a class typically serves as the blueprint:

```c#
public class UnitConverter
{
	int ratio; // Field

	public UnitConverter(int unitRatio) // constructor
	{
		ratio = unitRatio;
	}

	public int Convert(int unit) // method
	{
		return unit * ratio;
	}
}
```

### Instance vs static members
Instance members belong to each unique object instantiated from the class, static members are those which don't belong to any specific instance and cannot operator on an instances members:

```c#
public class UnitConverter
{
	int ratio; // Field
	public static int CONVERSIONS = 0;

	public UnitConverter(int unitRatio) // constructor
	{
		ratio = unitRatio;
	}

	public int Convert(int unit) // method
	{
		CONVERSIONS++;
		return unit * ratio;
	}
}
```

These static fields or methods can be accessed using the qualified name:

```c#
Console.WriteLine(UnitConverter.CONVERSIONS);
```

### The `public` keyword
The `public` keyword indicates a member of a class is exposed for use by other classes. Members without an access modifier are `private` by default and can only be accessed in the class they are defined in.

### Defining a namespace
A namespace can be used to organise types, these are useful for larger programs:

```c#
using System;

namespace Animals
{
	public class Ostrich
	{
		// ...
	}
}
```

## Type conversions
C# can convert between compatible types, conversions can be *implicit* or *explicit*:

```c#
int x = 12345;
long y = z; // implicit cast from int to long
short z = (short)x; // explicit cast from int to short
```

Implicit conversions are allowed when the compiler cannot guarantee a successful conversion and no information is lost in conversion.

## Value vs Reference types
C# types have some general categories:

- Value types: Comprise most built-in types as well as custom defined `struct` and `enum` types.
- Reference types: Comprise all class, array, delegate, and interface types including the predefined `string` type.
- Generic type parameters
- Pointer types

### Value types
A *value type* is one which represents a value, the content of an `int` is just 32 bits of data for example.

A custom value type can be defined with the `struct` keyword:

```c#
public struct Point
{
	public int X;
	public int Y;
}
```

Assigning a value-type instance to another variable always *copies* the instance, the original isn't used:

```c#
Point p1 = new Point();
p1.x = 10;

Point p2 = p1;
p2.x = 20;

Console.WriteLine(p1.x); // 10
Console.WriteLine(p2.x); // 20
```

### Reference types
A reference type is a complex type, it has two parts: an *object* and a *reference* to the object. The content of a reference-type variable is a reference to the object that contains the value, all classes are reference types:

```c#
public class Point
{
	public int X;
	public int Y;
}
```

Unlike value types, assigning a reference copies the reference and not a new copy of the object:

```c#
Point p1 = new Point();
p1.x = 10;

Point p2 = p1;
p2.x = 20;

Console.WriteLine(p1.x); // 20
Console.WriteLine(p2.x); // 20
```

Both `p1` and `p2` refer to the same object in memory.

### `Null`
The `null` literal can be assigned to any reference type variable, it indicates that it does not refer to an object:

```c#
string s = null;
Console.WriteLine(s == null); // true
```

Attempting to call a method on a `null` object will cause a runtime error called a `NullReferenceException`:

```c#
s.ToString(); // error
```

Ordinarily, value-types cannot have a `null` value and result in a compile-time error:

```c#
int x = null; // error
```

### Storage overhead
A value-type takes precisely the amount of memory required to store its fields:

```c#
public struct Point
{
	public int X;
	public int Y;
}
```

Each `int` takes 4-bytes, so this value-type occupies 8-bytes of memory.

> The CLR actually positions fields within the value type at an address that is a multiple of the fields size up to 8 bytes. It is actually 16 bytes of memory, with the 7 bytes following the first field being wasted space. This behaviour can be overridden by applying the `StructLayout` attribute.

Reference types require separate allocations of memory for both the reference and object, the object consuming as many bytes as its fields alongside administrative overhead and the reference requiring an extra 4 or 8 bytes depending on whether the .NET runtime is on a 32-bit or 64-bit platform.

## Predefined type taxonomy
The predefined types in C# are:

- Value types
	- Numeric
		- Signed integer (`sbyte`, `short`, `int`, `long`)
		- Unsigned integer (`byte`, `ushort`, `uint`, `ulong`)
		- Real number (`float`, `double`, `decimal`)
	- Logical (`bool`)
	- Character (`char`)
- Reference types
	- String (`string`)
	- Object (`object`)

The predefined C# types alias the .NET types in the `System` namespace:

```c#
int i = 10;
System.Int32 j = 10;
```

The set of predefined value types, excluding `decimal`, are known as *primitive types* in the CLR. This is because they are supported directly via instructions in compiled code.

The `System.IntPtr` and `System.UIntPtr` types are also primitive.

