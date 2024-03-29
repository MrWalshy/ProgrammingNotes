C++ allows for functions with the same name but different parameter types, the function signature is what differs. When a function is invoked, the compiler looks in something called the **overload set** which contains all the functions with that name; the compiler picks function that best matches the arguments provided.

```cpp
void foo(int i);
void foo(float f);

// call int overload
foo(30);
// cal float overload
foo(1.5f);
```

## Ambiguous matches
The process of matching a function call to a specific overloaded function is called **overload resolution**, there are cases where the compiler cannot immediately match an overloaded function though.

```cpp
void print(int x) { std::cout << x << std::endl; }
void print(double x) { std::cout << x << std::endl; }

//main()
print('a'); // char
print('1L'); // long
```

There is no exact match for the given invocations, but implicit type casting can occur to resolve which overload should be invoked.

### The process of resolving overloaded invocations
The compiler has a process which it goes through to resolve invocations to an appropriate overload by applying different type conversions to the arguments. The result is one of three outcomes per step of this iterative process, a *step* being the applying of type conversions on the arguments and then checking for a match:

- No functions matched, compiler moves to the next step in the sequence.
- Single function matched, considered the best match. Matching process ends.
- More than one match, compiler issues an ambiguous match compile time error.

If the end of the process is reached without finding a matching overload, a compile time error is produced indicating no matching function overload could be resolved for the given invocation.

### The argument matching sequence
**Step 1**: The compiler searches for an exact match (identity conversion). The compiler first checks if any overloads parameters exactly match the type of the arguments used in the invocation:

```cpp
void print(int);
void print(double);

// main()
print(0); // exact match with print(int)
print(0.0); // exact match with print(double)
```

If there isn't an immediate match, a number of **trivial conversions** occur; a set of conversion rules that modify types without modifying values. Some such *trivial conversions* include:

- Converting non-`const` types to a `const` type.
- Converting non-reference types to a reference type, or vice versa.

Any match made via a trivial conversion is considered to be an *exact match*.

**Step 2**: If no exact match exists, the compiler will try applying *numeric promotion* to the arguments:

- Floating-point promotion: `float`s are converted to `double`.
- Integral promotions:
	- signed `char` or signed `short` is widened to `int`.
	- `unsigned char`, `char8_t`, and `unsigned short` is converted to `int` if it can hold the entire rang of the type, `unsigned int` otherwise.
	- `bool` is converted to `int`, `false` is `0` and `true` is `1`

After numeric promotion, a match means the function call is resolved:

```cpp
void print(int);
void print(double);

// main
print('a'); // 'a' promoted to int, matches print(int)
print(true); // 'true' is promoted to int, matches print(int)
print(4.5f); // '4.5f' is promoted to double, matches print(double)
```

**Step 3**: If no matches are found via numeric promotion, the compiler tries applying *numeric conversion* to the arguments:

- Integral type conversion:
	- `int` to `short`
	- `int` to `long`
	- `short` to `char`
	- `int` to `unsigned int`
- Floating-point type conversion:
	- `double` to `float`
	- `double` to `long double`
- Floating-point to integral type conversion:
	- `double` to `int`
- Integral to floating type conversion:
	- `int` to `double`
- Integral or floating point to bool type conversion:
	- `int` to `bool`
	- `double` to `bool`
- Lossy conversions like `long` to `int`. Explicit casting with `static_cast<T>(T)` is recommended in these case.

```cpp
void print(double);
void print(std::string);

// main
print('a'); // 'a' matches print(double)
```

The `char` under promotion is converted to an `int`, but no `print(int)` exists. A numeric conversion from `int` to `double` occurs which then matches `print(double)`.

**Step 4**: If no numeric conversion matches an overload, the compilers then attempts to match through any user-defined conversions.

**Step 5**: If no user-defined conversion provides a match, the compiler looks for a matching function that uses ellipsis.

**Step 6**: If no matches are found, the compiler issues a compiler error with no matches found.

### Ambiguous matches
If an *ambiguous match* occurs, the compiler finds two or more appropriate function overloads in the same step, the compiler will issue an ambiguous function call error.

```cpp
void print(int);
void print(double);

// main()
print(5L);
```

`5L` is a long, no identity conversion or numeric promotion exists for this type in the example. The compiler will attempt conversion, the `long` can be converted to both an `int` and `double`, so an ambiguous match is made as both could be called.

Resolve an ambiguous match using a explicit cast when passing the argument with `static_cast<T>(T)`.

### Matching for multiple arguments
If multiple arguments are present, the compiler applies the matching rules to each argument in turn. The chosen function is the one where each argument matches at least as well as the other functions, but one argument matches better than all other functions.