## Numeric modifiers

The numeric types fall into three categories:
- Signed (both positive and negative)
- Unsigned (only positive, including 0)
- Floating-point

Signed and unsigned types come with different sizes, meaning each can represent a smaller or larger range of values.

A `signed` keyword exists for indicating a type is signed, it is only needed if the type is unsigned though. For example, `signed int` and `int` are the same types. These are different from `unsigned int`.

> If the `unsigned` keyword is specified without a type, it defaults to `int`.

Integers may come in different sizes:

- `int`
- `short int`: Guaranteed to be at least 16 bits (`-32768` to `32767` when signed, `0` to `65535` when `unsigned`)
- `long int`
- `long long int`