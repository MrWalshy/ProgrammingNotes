The `for` statement is a construct used for repeating code some known `N` amount of times:

```cpp
for (initialiser; condition; increment)
{
	statement(s);
}
```

The `for` loop has two parts:

- **Header**: The initialiser runs once at the start of a loop, usually used to declare new variables scoped to the loop. The condition statement is evaluated before executing the body of the loop, the body is only executed if this is true. The increment runs at the end of each loop, it is typically used to increment some value like the loop counter.
- **Body**: Contains the code to be repeated.

A `for` loop can function like a conditional `if`, it can execute a single statement or a block of statements repeatedly:

```cpp
for (init; cond; inc) statement;
```

The fields of the header are optional, so an infinite loop can be shaped like so:

```cpp
for (;;)
{
	statement(s);
}
```

## Range-based loop

An alternative `for` loop exists which can be used to iterate over a range where a **range** is some sequence of elements (like arrays):

```cpp
for (declaration : range) statement;
```

The declaration is a variable name that is declared at the start of each iteration of the loop, it stores the current element in the iterative process. The declaration's type must match that of the types of the range being iterated over.

> Type deduction can be useful for automagically deducting the type with the `auto` keyword.

## Example: Nested loop

Iterative statements can be nested inside of each other:

```cpp

```