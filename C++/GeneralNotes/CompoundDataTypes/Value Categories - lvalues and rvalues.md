To help determine how expressions in C++ should be evaluated and where they can be used, they have two properties: a *type* and a *value category* .

> List of value categories: [Value categories - cppreference.com](https://en.cppreference.com/w/cpp/language/value_category)
## The type of an expression

The **type** of an expression is equivalent to the type of the value, object, or function resulting from evaluating the expression. The compiler uses the type of an expression to determine whether it is valid in a given context. An expressions type must be determinable at compile time to allow type checking and type deduction to work, its value may be determined at compile time (for `constexpr`) or runtime (if not `constexpr`).

```cpp
auto x = 5 + 5; // int + int => int type
auto y = 5 + 5.5; // int + double => double type
```

## The value category of an expression

The **value category** of an expression indicates whether an expression resolves to a value, function, or an object of some kind. This is how the compiler knows which expressions can legally appear on either side of an assignment statement:

```cpp
int x = 5; // valid, 5 can be assigned to x
5 = x; // error: value of x cannot be assigned to a literal value 5
```

Prior to C++11, two value categories existed (`lvalue` and `rvalue`). C++11 introduced three additional value categories (`glvalue`, `prvalue`, `xvalue`) to support *move semantics*.

## Lvalue and rvalue expressions
An **lvalue**, short for *left value* or *locator value*, is an expression which evaluates to an identifiable object, function, or bit-field. This implies that entities in the language (functions, objects, etc...) have an identity that can be differentiated from other entities (typically by comparing addresses).

Any entity with an identity is accessible via an identifier, reference, or pointer; they typically have lifetimes longer than a single expression or statement.

```cpp
int x { 10 };
int y { x };
```

The expression `x` is an lvalue expression, this is because it evaluates the the variable `x` (declared on the previous line, it has an identifier).

lvalues have two subtypes:
- **Modifiable lvalue**: An lvalue whose value can be modified
- **Non-modifiable lvalue**: An lvalue whose value cannot be modified because the lvalue is `const` or `constexpr`.

```cpp
int x {};
const int d {};

int y { x }; // x is a modifiable lvalue expression
const int e { d }; // d is a non-modifiable lvalue expression
```

An **rvalue** is an expression which is not an lvalue, it is short for *right value*, and evaluates to a value. Common rvalues include:

- Literals (except C-style string literals, these are lvalues). C-style strings are lvalues because they decay to a pointer to maintain backwards compatability with C.
- Return values of functions that return by value (returned value is temporary and not identifiable)
- Return values of operators that return by value (returned value is temporary and not identifiable)

An rvalue does not have an identity, so it has to be used immediately, and only exists within the scope of the expression it is used in (it's a temporary value).

```cpp
int foo() { return 1; }

// main()
int x { 1 }; // 1 is an rvalue expression
int y { x }; // x is a modifiable lvalue expression
int z { foo() }; // foo() is an rvalue expression

double d { x + 2.0 }; // x + 2.0 is an rvalue expression
int a { static_cast<int>(d) }; // result of static cast d to int is an rvalue expression
```

The reason for why a value can be assigned to a variable but not the other way around is because the left operand of an assignment must be a *modifiable lvalue* and the right operand must be an *rvalue expression*:

```cpp
int x = 1; // legal: x is modifiable lvalue expression, 5 is rvalue expression
1 = x; // error: 1 is rvalue expression, x is modifiable lvalue expression
```

A quick and easy way to check if an expression is an lvalue or rvalue is to use the *address of* operator, this is because `&` requires its operand to be an lvalue. If `&(expression)` compiles, `expression` must be an lvalue.

## lvalue to rvalue conversions
During assignment, it is possible to use an lvalue expression in the assignment as the right-hand operand. This is because lvalue expressions will implicitly convert to rvalue expressions in contexts where an rvalue is expected but an lvalue was provided:

```cpp
int x { 1 };
int y { x };
int z { 10 };
// x is an lvalue expr, implicit convert to rvalue expr of '1' and then assigned to y

x = z;
// z is an lvalue expr, implict convert to rvalue expr of 10, then assigned to x
```





