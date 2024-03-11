A **variable** is named storage referring to a memory location used to hold a value. C++ is *strongly-typed* and requires each variable explicitly specifies its data type.

The indicated type is used by the compiler to decide the amount of memory the variable needs reserving and how to interpret its value.

## Syntax - Declaration

To declare a new variable, use:

```cpp
type variable_name;
```

Multiple variables can be declared on the same line using the comma operator:

```cpp
type var1, var2, var3;
```

Variables without an initial value are undetermined until an assignment occurs.

## Syntax - Initialisation
**Variable initialisation** is used to declare a variable with a given value.

The **C-like initialisation** is as follows:

```cpp
type variable_name = value;
```

**Constructor initialisation**, used with classes, looks like:

```cpp
type variable_name (value);
```

**Uniform initialisation** or **list initialisation** allows for the initialisation of variables and objects of different types using *brace initialisation*:

```cpp
type variable_name {value};
```
## Naming rules

C++ variable names can contain:

- Alphanumeric symbols (letters of the alphabet and numbers)
- Upper and lower case letters
- Underscores

A number cannot be the first character of a variable name though.

## Type deduction

When a variable is initialised at declaration, the compiler can use **type deduction** to infer the required type.

Due to this process, the `auto` keyword can be used in these cases to replace the type name during initialisation:

```cpp
auto variable_name = value;
```

Another way of doing this is using the `decltype` specifier which deduces the type of a given variable and uses to it specify the type of a new variable:

```cpp
type variable1 = value;
decltype(variable1) variable2;
```

- Type deduction with `auto` and `decltype` was introduced in the C++11 standard to simplify and facilitate variable declaration when the type is not known.
