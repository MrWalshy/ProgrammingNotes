Often, there will be multiple functions with the same name in a program. Namespaces are used to prevent conflicts between the function names by grouping them in a specific scope.

Namespaces create a scope where all names declared inside are part of the namespace:

```cpp
namespace example_namespace
{

}
```

To access an identifier inside a namespace, the name of the namespace is prepended to the identifier to be accessed using `::` to separate them:

```cpp
std::cout
```

In the `std` namespace, the `cout` variable identifier is accessed as shown above.

Namespaces may also be nested:

```cpp
namespace parent
{
	namespace child
	{
		
	}
}
```

Accessing an identifier inside nested namespaces follows the same convention of listing the namespaces separated by `::` and the identifier to access:

```cpp
parent::child::some_identifier
```

To access names in the global scope, prepend `::` to the name:

```cpp
::global_scope_identifier
```

When the compiler is compiling the program, it will only search for identifiers in the current namespace and the parent namespaces to find an identifier by default. In the case of `std::cout`, the `std` namespace would need to be specified otherwise the compiler wouldn't be able to find the `cout` identifier.

## The `using` declaration

The `using` declaration is used to tell the compiler where to look for an identifier, such as `cout` from `std`:

```cpp
using std::cout; // tells the compiler where to look when using 'cout' in code
using namespace std; // tells the compiler where to look for all identifiers from this namespace
```

If all of the declarations from a namespace are to be used, this can be indicated with the syntax:

```cpp
using namespace namespace_name;
```

When a name is declared inside the `using` declaration, the compiler looks for that name when looking for an identifier. This means `cout` could be used and the compiler will find `std::cout`.

The `using` declaration is valid as long as the code using a declaration from it is within the scope of which it is declared.

## Anonymous namespaces

An anonymous namespace is a namespace with no identifier, any identifiers within it are private to the *current translation unit* (the `.cpp` file in most cases).

To access identifiers inside an anonymous namespace, the identifier is used directly without the need for a namespace name or the `using` declaration.