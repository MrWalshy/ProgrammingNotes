The built-in data types and literals are the atoms of the language, the basic building blocks. Expressions build upon these.

## Arithmetic
Basic arithmetic operators are supported:

```cpp
add + num;
subtract - num;
multiply * num;
divide / num;
```

- The subexpressions on either side of the operator are called **operands**.
- The operators shown above are **binary operators**, this is because the operator is **infix** (between the two operands) and so are also known as *infix operators*. **Prefix** and **postfix** operators come before and after operands.

The `-` operator is both infix and prefix, it can be used for subtraction (as above) or to negate a number:

```js
-negateMe;
```

All of these operators only work on numbers, except the `+` operator which can also concatenate two strings.

## Comparison and equality
Comparison operators always return a boolean value, only numbers can be compared using these operators:

```js
less < than;
lessThan <= orEqual;
greater > than;
greaterThan >= orEqual;
```

Equality and inequality tests can be used upon any types:

```cpp
1 == 2; // false
"cat" != "dog"; // true
```

## Logical operators
The prefix not operator, `!`, returns `false` if its operand is true and vice versa:

```js
!true; // false
!false; // true
```

Control flow constructs disguised as expressions, `and` and `or`, are represented as logical infix operators:

```js
true and true; // true
false and true; // false
```

- Determines if two values are both `true`.
- Returns the left operands if it's `false`, or the right operand otherwise.

`or` expressions determine if either of two values (or both) are `true`, returning the left operand if it is `true` and the right operand otherwise:

```cpp
false or false; // false
false or true; // true
```

`and` and `or` are control flow structures as they **short-circuit**, not even evaluating the right operand in some cases.

## Precedence and grouping
The same precedence and associativity as C is assumed with the languages operators. The grouping operator, `()`, can be used to override this:

```js
var average = (min + max) / 2;
```

