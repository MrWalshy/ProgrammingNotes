**Type aliases** are useful for making complex types simpler to understand and work with, they can be used wherever a regular type can.

Consider the following example:

```cpp
std::pair<std::string, std::string> contact;
```

The variable name does indicate what the type represents, but it would also then require specifying the complex type in parameters to functions:

```cpp
void logContact(std::pair<std::string, std::string>& contact)
{
	std::cout << "Name: " << contact.first << ", Number: " << contact.second << std::endl;
}
```

Instead, an alias to this type can be created to simplify its representation.

## Creating aliases with `using`
A `using` statement can be used to create a type alias:

```cpp
using Contact = std::pair<std::string, std::string>;
```

In the example function, this type can be used as a parameter:

```cpp
void logContact(Contact& contact);
```

Variables can also be declared using the aliased type:

```cpp
Contact fred { "Fred", "+447897938293"};
```

Qualifiers like `*` for pointers, `&` for references, and `const` for constants can also be used with aliased types.

### Alias scope
Aliases, like other declarations, have a scope in which they can work. If they are global, they can be used anywhere. They can also be defined within a block, to scope them locally. Aliases follow the normal scoping rules:

```cpp
using GlobalIntAlias = int;

int main()
{
	using LocalIntAlias = int; // can only be used within the scope of main()
}
```

### Project wide aliases
When defining aliases that need to be used across many files, it can be helpful to define them within a header file that is included as needed. Once the header is included, its aliases can be used as normal. If a change is needed, the alias then only needs adjusting in the header.

## `std::conditional`
The `<type_traits>` header file contains a helper called `std::conditional`, this can be used to help choose between one of two types at compile time. It accepts three template parameters:

1. A boolean value known at compile time.
2. The type to use if the boolean is true.
3. The type to use if the boolean is false.

The resulting type is obtained from the `type` static member:

```cpp
constexpr bool foo{true};

using Integer = std::conditional<foo, int64_t, int32_t>::type;
```

Alternatively, the `std::conditional_t` helper can be used to resolve the type directly:

```cpp
using Integer = std::conditional_t<foo, int64_t, int32_t>;
```

## `decltype`
Sometimes, it may be useful to ask the compiler to determine what type an expression returns. The `decltype` specifier is used for this purpose, in doing so it also creates an alias that can be used:

```cpp
using Number = decltype(3.14); // Number is an alias for double
```

An added benefit is that it can be used almost anywhere a type is expected, such as for variable declarations:

```cpp
std::string foo() { return "bar"; }

int main()
{
	decltype(foo()) value;
}
```

Although it looks like `foo()` will be invoked inside the `decltype()` specifier, it is not. The compiler instead uses the expression to deduce what the type should be, `std::string` in this case.

## `std::declval`
Complex expressions are common in C++, this can make it tricky to use `decltype` for type alias declarations:

```cpp
struct Foo
{
	Foo(int x, float y) {}
	float get() {}
};

int main()
{
	using SomeType = decltype(Foo(10, 20.f).get());
}
```

To simplify this, the `std::declval<T>()` function from the `<utility>` header can be used to create a *pretend* instance of a type without actually constructing an object. It does this by returning an rvalue reference to the pretend instance of type `T`. This allows for `T` to be used where an object of that type is required:

```cpp
using SomeType = decltype(std::declval<Foo>().get());
```

As no object is actually constructed, no constructor arguments need to be passed to the function either.

## `typedef`
C implements type aliases using `typedef`, C++ also inherited this feature. The `using` approach is preferred in C++ though.

```cpp
typedef int Integer;
```

