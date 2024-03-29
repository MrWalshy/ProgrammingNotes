The primitive types consist of:
- **Integer**: The `int` type stores a whole number ranging from `-214783648` to `214783647`, taking up 4 bytes of memory space (32 bits).
- **Character**: The `char` type stores character data and typically takes 1 byte of memory space, it is guaranteed to be big enough to represent any UTF-8 single byte code unit. `char16_t` and `char32_t` are used for UTF-16 and UTF-32 respectively.
- **Boolean**: The `bool` type holds one of two values, `true` or `false`.
- **Floating-point**: The `float` type stores single precision floating point values, typically taking up 4 bytes of memory space.
- **Double floating-point**: The `double` type stores double precision floating point values, typically takes up 8 bytes of memory space.
- **Void**: The `void` type represents a lack of value, a valueless data type used for functions that do not return a value.
- **Wide character**: The `wchar_t` type allows for greater size when representing character sets, typically 2 to 4 bytes long.

The `char` and `wchar_t` types hold numeric values corresponding to the characters in the machine's character set.

## Separator for large numbers
A separator can be used to make large numbers easier to read:

```cpp
int num { 1'000'000 };
```

The single quote character (`'`) is used for this purpose.

## Boolean logical operator order of evaluation
- NOT (`!`) before AND (`&&`)
- AND (`&&`) before OR (`||`)