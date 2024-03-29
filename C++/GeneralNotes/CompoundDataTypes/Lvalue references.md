A C++ reference is an alias to an existing object. Once a ref is defined, any operation on the reference is applied to the object it refers to.

C++ contains two types of references, lvalue references and rvalue references (related to move semantics).

## Lvalue reference types
Prior to C++11, only lvalue references existed and thus they were commonly just called a reference. They act as an alias for an existing lvalue (like a variable or function).

lvalue reference types are declared using an ampersand in the type declaration:

```cpp
int // normal int type
int& // lvalue reference to an int object
```

## Lvalue reference variables
An **lvalue reference variable** is a variable acting as a reference to another lvalue, this is done by defining a variable with an lvalue reference type:

```cpp
int x { 1 }; // normal int variable
int& ref { x }; // ref is lvalue ref variable used as an alias for variable 'x'
```

The reference can be declared with the ampersand on the type or the identifier, the type is preferred:

```cpp
int &x;
int& y; // preferred
```

## Modifying values through an lvalue reference
An lvalue reference can be used to also modify the value of the object it references:

```cpp
int x { 1 };
int& y { x };
// x = 1, y = 1

y = 10;
// x = 10, y is a ref to x so 10 also
```

