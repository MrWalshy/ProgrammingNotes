A variable represents a storage location with a modifiable value, it can be a *local variable*, *parameter* (*value*, *ref*, *out*, or *in*), *field* (*instance* or *static*), or *array element*.

## The stack and the heap
Variables are stored in the stack or the heap, each has different lifetime semantics.

### Stack
The stack is a block of memory in which local variables and parameters are stored, it grows and shrinks as method or function calls are entered or exited.

Consider the following method:

```c#
static int Factorial(int x)
{
	if (x == 0) return 1;
	return x * Factorial(x - 1);
}
```

The invocation of `Factorial(3)` would create a stack like the following:

```c#
Factorial(x = 1)
Factorial(x = 2)
Factorial(x = 3)
```

Each method invocation gets its own stack frame, which stores the local variables and parameters. When the method ends, it is popped off the stack. So after the `Factorial(x = 1)` invocation has ended, the stack would look like:

```c#
Factorial(x = 2)
Factorial(x = 3)
```

### Heap
The heap is where objects (reference types) are stored. When a new object is created, it is stored on the heap and a reference to it is returned.

During execution, a garbage collector belonging to the runtime periodically deallocates objects from the heap to prevent the program from running out of memory. An object is eligible for deallocation as soon as it is no longer referenced anywhere in the program by something that is alive.

Value-type instances and object references live wherever the variable was declared. If it is as a field within a class type or an array element, it lives on the heap.

Static fields are also stored on the heap, these are not garbage collected until the process (program) ends.

## Default values
All instances of a type have a default value associated with them, for the predefined types it is the result of a bitwise zeroing of memory.


| Type                                       | Default value |
| ------------------------------------------ | ------------- |
| Reference types (and nullable value types) | `null`        |
| Numeric and enum types                     | `0`           |
| `char` type                                | `\0`          |
| `bool` type                                | `false`       |
The default value for any type can be obtained with the `default` keyword:

```c#
Console.WriteLine(default(decimal)); // 0
```

Optionally, the type can be omitted when it can be inferred from the context:

```c#
decimal d = default;
```

The default value for a custom value type, a `struct`, is the same as the default value for each field defined by the type.

## Parameters
Methods can have a sequence of parameters known as a parameter list, arguments can be passed to each parameter in the list when invoking the method.

How parameters are passed can be controlled with specific modifiers.


| Parameter modifier | Passed by             | Variable must be definitely assigned |
| ------------------ | --------------------- | ------------------------------------ |
| (None)             | Value                 | Going in                             |
| `ref`              | Reference             | Going in                             |
| `in`               | Reference (read-only) | Going in                             |
| `out`              | Reference             | Going out                            |
### Pass by value
C# arguments are passed by value by default, a copy of the value is created when it is passed to the method:

```c#
int x = 10;
Foo(x); // passes a copy of x
Console.WriteLine(x);

static void Foo(int num)
{
	num++;
	Console.WriteLine(num);
}
```

With reference types, a copy of the reference is passed. This means the parameter will hold a reference to the same object as that outside the method:

```c#
Point p = new Point();
Foo(p);
Console.WriteLine(p.X); // 10

class Point { public int X, Y; }
static void Foo(Point point)
{
	point.x = 10;
	point.y = 5;
}
```

### The `ref` modifier
Passing by reference allows for the parameter to point to the same memory location as the argument passed to the method. The `ref` modifier is one way of allowing this:

```c#
int x = 10;
Foo(ref x); // Foo works with the object of x directly
Console.WriteLine(x); // 11

static void Foo(ref int num)
{
	num++;
	Console.WriteLine(num);
}
```

`ref` parameters require an argument to be supplied.
### The `out` modifier
An `out` argument is like a `ref` argument, except:

- It doesn't need to be assigned before going into the function.
- It must be assigned before the function ends.

The `out` modifier is commonly used when multiple return values are desired:

```c#
string forename, surname;
Split("Bob Aidley", out forename, out surname);
Console.WriteLine(forename); // Bob
Console.WriteLine(surname); // Aidley

void Split(string name, out string forename, out string surname)
{
	int i = name.LastIndexOf(' ');
	forename = name.Substring(0, i);
	surname = name.Substring(i + 1);
}
```

### Out variables and discards
Variables can be declared on the fly when invoking methods with the `out` parameter:

```c#
Split("Bob Aidley", out string forename, out string surname);
```

In some cases, you might not want all of the outputs from the method. Discards can be used to ignore these ones, symbolised by an underscore:

```c#
Split("Bob Aidley", out string forename, out _);
```

### The `in` modifier
`in` parameters are similar to a `ref` parameter, except the argument cannot be modified by the method; doing so results in a compile-time error. This modifier is useful for passing large value types to a method without the overhead of copying the argument prior, while still protecting the original variable from being modified.

Overloading solely on the presence of `in` is allowed as well:

```c#
void Foo(SomeBigStruct a) {}
void Foo(in SomeBigStruct a) {}
```

Calling the second overload requires using the `in` modifier:

```c#
SomeBigStruct x = ...;
Foo(x); // calls Foo(SomeBigStruct a)
Foo(in x); // calls Foo(in SomeBigStruct a)
```

When there are no overloads, there is no ambiguity. This allows for the `in` modifier to be optional for the caller:

```c#
void Bar(in SomeBigStruct a) {}
Bar(x); // calls the `in` variant
Bar(in x); // calls the `in` variant
```

### The `params` modifier
The `params` modifier is used to allow the last parameter of a method to accept any number of arguments of a particular type. The parameter must be declared as a single-dimension array:

```c#
int total = Sum(10, 10, 20); // 40

int Sum(params int[] numbers)
{
	int sum = 0;
	for (int i = 0; i < numbers.Length; i++)
	{
		sum += numbers[i];
	}
	return sum;
}
```

If no arguments are passed, a zero-length array is created. Alternatively, a single-dimension array can be passed to a `params` parameter.

### Optional parameters
Methods, constructors, and indexers can have optional parameters. One is optional if it specifies a default value in its declaration:

```c#
void Foo(int x = 10) { Console.WriteLine(x); }
Foo(); // 10
Foo(20); // 20
```

The compiler will actually embed the default value into any calls that omit the value, so `Foo()` is equivalent to `Foo(10)` in the compiled code.

- A default value must be specified by a constant expression, parameterless constructor of a value type, or a `default` expression
- Optional parameters cannot be marked with `ref` or `out`
- Mandatory parameters must occur before optional parameters in both the method declaration and the method call. The exception is the `params` argument, which always comes last.

### Named arguments
When invoking a method, arguments can be identified by name rather than position if desired:

```c#
Foo(y:2, x:1);
void Foo(int x, int y) {}
```

They can be passed in any order when passed using the parameters name.

Named and positional arguments can be used together, but positional arguments must be before named arguments unless used in the correct position:

```c#
Foo(x:1, 20);
Foo(10, y:30);
```

## Ref locals and returns
### Ref locals
An esoteric feature of C# is a local variable can be defined that references an element in an array or field in an object from C# 7:

```c#
int[] numbers = { 0, 1, 2, 3, 4 };
ref int numRef = ref numbers[2];
```

This variable is a reference to `numbers[2]`, modifying `numRef` modifies the array element. The target for a `ref` local must be an array element, field, or local variable; it cannot be a property.

These are intended for micro-optimisation and are typically used with `ref` returns.

### Ref returns
A `ref` local can be returned from a method, this is called a `ref` return.

```c#
class Program
{
	static string x = "original";
	static ref string GetX() => ref x; // returns a ref

	static void Main()
	{
		ref string xRef = ref GetX(); // assign to ref local
		xRef = "new value";
		Console.WriteLine(x); // new value
	}
}
```

- If the `ref` modifier is omitted by the caller, it reverts to an ordinary value.
- ref returns can be used when defining a property or indexer as well. Such properties are implicitly writable even though no `set` accessor exists. Modification is preventable by using `ref readonly`: `static ref readonly string Prop => ref x;`


## Implicitly typed local variables
The `var` keyword can be used to infer a variables type from its initialisation expression:

```c#
var x = "Hi"; // string
var y = (float)Math.PI; // float
```

These implicitly typed variables are statically typed, so their type cannot be modified:

```c#
var x = 10;
x = "hi"; // compile-time error
```

## Target-typed new expressions
C#9 introduced **target-typed new expressions** to reduce lexical repetition in code:

```c#
System.Text.StringBuilder sb1 = new System.Text.StringBuilder();
System.Text.StringBuilder sb2 = new();
```

The compiler is able to infer the type of the object if the situation the `new` expression is used in is unambiguous.