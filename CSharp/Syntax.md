C# syntax is inspired by C and C++.

## Identifiers and keywords
**Identifiers** in C# are case sensitive words made up of letters, underscores, and numbers. They may start with a letter or underscore. By convention:

- Parameters, local variables, and private fields should be in camel case
- All other identifiers should be in pascal case

**Keywords** are names with a special meaning to the compiler, most keywords are reserved and cannot be used as identifiers:

```
abstract as base bool break byte case catch char checked class const continue decimal default delegate do double else enum event explicit extern false finally fixed float for foreach goto if implicit in int interface internal is lock long namespace new null object operator out override params private protected public readonly record ref return sbyte sealed short sizeof stackalloc static string struct switch this throw true try typeof uint ulong unchecked unsafe ushort using virtual void volatile while
```

To use an identifier that clashes with a keyword, qualify the identifier with the `@` prefix:

```c#
int @using = 123;
```

### Contextual keywords
Some keywords are based on their context, meaning they can be used as identifiers without the `@` symbol:

```
add alias and ascending async await by descending dynamic equals from get global group init into join let managed nameof nint not notnull nuint on or orderby partial remove select set unmanaged value var with when where yield
```

## Literals, punctuators, and operators
A **literal** is a primitive piece of data lexically embedded into the source code, these could be numbers like `12`, `12.4`, booleans like `true` and `false`, characters like `a`, `b`, or strings like `"Hello World"`.

A **punctuator** demarcates a programs structure, like the semi-colon which terminates a statement.

An **operator** transforms and combines expressions, most are denoted with a symbol like `*`, `=`, `.` etc... A period is used to denote membership or a decimal point. 

## Comments
C# has to styles of source-code documentation, single line comments and multi-line comments:

```c#
int x = 3; // single-line comment
/*
	Multi-line comment
*/
```

