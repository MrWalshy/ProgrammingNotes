The `std::variant` is a value type used to represent a choice of types, the class takes a list of types, and the variant will be able to contain one value of any of those types. Include the `<variant>` header file to use it.

- Often referred to as a *tagged union* as its similar to a union, it can store multiple types with only one present at a time; it also tracks which type is currently stored.

During a programs execution, `variant` will contain exactly one of the possible types at a time. Like `optional`, `variant` is a value type too; when a copy of a `variant` is created, the element currently stored is copied into the new `variant`.

The C++ standard library provides two main functions for interacting with variants:

- `holds_alternative<Type>(variant)`: Returns `true` if the variant is currently holding the provided type, `false` otherwise.
- `get(variant)`: Two versions exist to get the value of the type currently stored, `get<Type>(variant)` and `get<Index>(variant)`.

Before calling `get<Type>(variant)`, the caller needs to be sure that `holds_alternative<Type>(variant)` is `true`. `get<Index>(variant)` needs to do the same, this gets the value of the index type currently stored inside variant.

```cpp
std::variant<string, float> variant = "Hello World";

std::string valueExample1 = std::get<0>(variant);
std::string valueExample2 = std::get<std::string>(variant); // preferred
```

An alternative method to retrieving a variants value is to use the `std::visit(visitor, variant)`  function which takes a variant and a functor. The callable object needs to support an overload of `operator()`, taking a type for each of the possible types stored inside `variant`.

Variants are valuable when wanting to represent a set of values of different types, typical examples include:

- A function returning different types depending on the current state of the program.
- A class that represents several states.
