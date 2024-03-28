## Function Template

Two features introduced by C++11 make it easier to write template functions, these features are *trailing return types* and `decltype`.

The `decltype` keyword accepts an expression and returns the type of the expression:

```cpp
int x;
decltype(x) y;
```

The variable `y` in the example above is declared as an integer, this is because the type of expression `x` is used.

**Trailing return types** allow specifying the return type at the end of the function signature. The syntax involves declaring a function using the keyword `auto` in-place of the standard return type position, after the rest of the signature an *arrow* and *return type* follows:

```cpp
// regular
int max(int a, int b);

// trailing
auto max(int a, int b) -> int;
```

This is not beneficial for regular functions, but is useful when writing templates and when combined with `decltype`. This is because `decltype` has access to the variables defined in a functions parameters, and the return type can be computed from them:

```cpp
template<typename User>
auto getAccount(User user) -> decltype(user.getAccount());
```

This is an example of a **forward declaration** of a function template.

> When a user wants to provide a definition, it must provide the same template declaration followed by the function body.

Without the trailing return type, the type returned by `user.getAccount()` must be specified. By using the trailing return type instead, the type returned can differ based on the different `User` types that might be used.

C++14 introduced the ability to use just `auto` in the function declaration without the need for the trailing return type:

```cpp
auto max(int a, int b)
```

The return type will be automatically deduced by the compiler but to do so, the compiler needs to see the function definition - functions that return `auto` cannot be forward declared. A caveat is that `auto` always returns a value and never returns a reference.

### Passing function templates as arguments to other functions

Function templates can also be referenced rather than called, allowing them to be passed as parameters to other functions. This is done by only specifying the template function name and template parameters:

```cpp
template<typename T>
void sort(std::array<T, 5> array, bool (*function)(const T&, const T&));
```

The `sort` function takes an array of 5 elements and a pointer to a function which compares two elements of the same type in the array:

```cpp
template<typename T>
bool less(const T& a, const T& b)
{
	return a < b;
}
```

Calling `sort` with an instance of `less` for integers would look like:

```cpp
std::array<int, 5> array = {4,3,5,1,2};
sort(array, &less<int>); // pointer to instance of 'less' for integers
```