C# provides three operators to make working with `null` values easier:

- Null-coalescing operator
- Null-coalescing assignment operator
- Null-conditional operator

## Null-coalescing operator
The **null-coalescing operator**, `??`, is a binary operator which returns the left value if it is non-null, otherwise it returns the value on the right:

```c#
string s1 = null;
string s2 = s1 ?? "nothing"; // evals to "nothing"
```

If the lefthand expression is non-null, the righthand expression is never evaluated. This operator also works with nullable value types.

## Null-coalescing assignment operator
C#8 introduced the **null-coalescing assignment operator**, `??=`, which assigns the right operand to the left operand if the left operand is null:

```c#
string s1 = null;
s1 ??= "A value";
```

This is equivalent to:

```c#
string s1 = null;
if (s1 == null) s1 = "A value";
```

## Null-conditional operator
The **null-conditional operator**, `?.`, allows for calling methods and accessing members on an object like dot notation, but if the left operand is `null`, the expression evaluates to `null` instead of throwing a `NullReferenceException`:

```c#
System.Text.StringBuilder sb = null;
string s = sb?.ToString(); // evals to `null`
```

This is equivalent to:

```c#
string s = (sb == null ? null : sb.ToString());
```

Null-conditional expressions also work with indexers:

```c#
string foo = null;
char? c = foo?[1]; // null
```

This can also be used in combination with the null-coalescing operator:

```c#
System.Text.StringBuilder sb = null;
string s = sb?.ToString() ?? "nothing";
```

