C++20 introduced the `std::format()` function, and C++23 introduced `std::print()`, for interpolating strings.

## `std::format()`
To use `std::format()`, include the `<format>` header file. It's basic usage involves inserting placeholder values using curly braces, `{}`, with the arguments to insert into the template following it:

```cpp
std::string str1 { std::format("This {} is interpolated.", "string") };
std::string str2 { std::format("This {} is {}.", "string", "interpolated") };
```

Any expression resulting in a value of a type supported by `std::format` can be used as an argument:

- Integral types like `int`, `long`, etc...
- Floating-point types like `float` and `double`.
- Character types like `char`, `wchar_t`, etc...
- Any pointer type (`T*`) where `T` is a supported type.
- User-defined types which have appropriate formatting supporting via a custom `std::format` overload or by specialising the `std::formatter` template

## `std::print()`
The `std::print()` function combines the `std::format()` with the ability to directly send the formatted string to a stream like `std::cout`:

```cpp
std::print("This is {}.", "interpolated");
```

## Including braces in a template string
To include braces in a template string that don't represent an interpolated value, wrap them in a pair of braces:

```cpp
std::string str { std::format("A {} brace looks like {{}", "left") };
// A left brace looks like {
```

## Positional arguments
By default, the placeholders marked with `{}` sequentially match the arguments passed in. This can be controlled by inserting integers between the braces to indicate which argument they should represent, the positions are zero-based:

```cpp
std::string str { std::format("{1} apples is {0}", "free", 5) };
// 5 apples is free
```

This also allows for the same value to be used multiple times:

```cpp
std::string str { std::format("{0}, {1}, {0}", "yippee", "yay") };
// yippee, yay, yippee
```

## Format specifiers
**Format specifiers** are additional options that can be supplied within a placeholder to indicate how the interpolated value should be formatted, these are passed after a `:` character within the braces. If the placeholder is positional, the position comes before the colon.

```cpp
std::string str { std::format("The {1} is {0:+}", 10, "number") };
// The number is +10
```

- The `+` specifier prefixes a `+` symbol to positive numbers.

### Minimum width
Passing a positive integer as the format specifier sets a minimum width for the inserted value, if the value does not meet the specified minimum width then blank spaces are inserted to fill it:

```cpp
std::string str1 { std::format("Great score: {:2}", 8) };
// Great score:  2
std::string str2 { std::format("Great score: {:2}", 12) };
// Great score: 12
```

### Fill formatting
When the argument to a format string is an integer, a minimum width can be prefixed with a `0` to fill additional space with leading zeros:

```cpp
std::string str { std::format("Great score: {:02}", 8) };
// Great score: 08
```

Any value can be used as a fill character, this also works with strings:

```cpp
std::string str { std::format("| {:-<12} | ", "Left")};
// | Left-------- |
```

### Alignment
The width specifier can be prefixed with an additional character to specify how the interpolated value should be aligned within that width:

- `<`: Left alignment
- `^`: Centre alignment
- `>`: Right alignment

```cpp
std::string aligned { 
	std::format("| {:<12} |\n| {:^12} |\n| {:>12} |", "Left", "Centre", "Right") 
};
// | Left         |
// |    Centre    |
// |        Right |
```

### Floating point precision
The precision of a floating point number can be set, this is done by specifying a `.` followed by the number of significant figures to include:

```cpp
std::string pi { std::format("Pi (2 s.f): {:.2}", 3.141592f) };
// Pi (2 s.f): 3.14
```

### Using variables in format specifiers
Format specifiers in a placeholder can also interpolate arguments into them:

```cpp
std::string str { std::format("I have {0:{1}} apples", 3, 4) };
std::string str2 { std::format("I have {:{}} apples", 3, 4) };
// I have    3 apples
```

The positional argument is optional even when doing this, the integer `4` has been interpolated into the position for the width argument.

## Date and time formatting with `chrono`
Most of the `chrono` types support using `std::format()`, by default a date following by a timestamp is interpolated:

```cpp
std::chrono::time_point tp { std::chrono::system_clock::now() };
std::string timeStr { std::format("{}", tp) };
```

> Supported format specifiers: [std::formatter<std::chrono::sys_time> - cppreference.com](https://en.cppreference.com/w/cpp/chrono/system_clock/formatter)