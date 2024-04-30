## Char type
The C# `char` type aliases the `System.Char` type, it represents a Unicode character occupying two bytes of memory (UTF-16). Literals are specified using single quotes:

```c#
char c = 'A';
```

### Escape sequences

An **escape sequence** expresses a character that cannot be expressed or interpreted literally, it is a backslash followed by a character with a special meaning:

| Char | Meaning         | Value  |
| ---- | --------------- | ------ |
| `\'` | Single quote    | 0x0027 |
| `\"` | Double quote    | 0x0022 |
| `\\` | Backslash       | 0x005C |
| `\0` | Null            | 0x0000 |
| `\a` | Alert           | 0x0007 |
| `\b` | Backspace       | 0x0008 |
| `\f` | Form feed       | 0x000C |
| `\n` | New line        | 0x000A |
| `\r` | Carriage return | 0x000D |
| `\t` | Horizontal tab  | 0x0009 |
| `\v` | Vertical tab    | 0x000B |
The `\u` and `\x` escape sequences can be used to specify any Unicode character via its four-digit hexadecimal code:

```c#
char copyright = '\u00A9';
```

## String type
The C# `string` type, which aliases `System.String`, represents an immutable sequence of Unicode characters. String literals are specified within double quotes:

```c#
string s = "Hello World";
```

A `string` is a reference type, but its equality operators follow value-type semantics. Escape sequences can also be used inside strings.

C# allows *verbatim* string literals, these do not support escape sequences and can make it easier where repeated characters like backslashes are needed. They can also span multiple lines. A verbatim string is prefixed with the `@` symbol:

```c#
string verbatim = @"Hello world,
second line
third line \\\\";
```

To include a double-quote in a verbatim literal, write it twice:

```c#
string quote = @"The quote is ""To C# is to program"".";
```

### String concatenation
The `+` operator can be used to concatenate two strings:

```c#
string s = "a" + "b"; // ab
string s = "a" + 5; // a5
```

Where an operand is a non-string type, the `ToString()` method is automatically called on that value.

### String interpolation
Strings preceded with the `$` character are *interpolated strings*, these can include expressions within braces to insert values into the string:

```c#
int x = 4;
Console.WriteLine($"The square of {x} is {x * x}");
```

Interpolated strings are single-line unless the verbatim string operator is specified:

```c#
int x = 4;
Console.WriteLine($@"The square of {x} 
is {x * x}");
```

To include a brace character in the literal, repeat it.