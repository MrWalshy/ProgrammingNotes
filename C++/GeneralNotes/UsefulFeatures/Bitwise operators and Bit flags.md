Every variable and object is stored as binary under the hood, bit manipulation can be used to gain certain advantages due to this when working with numbers.

## Fixed width integers
It is common when working with individual bits to choose a fixed-width unsigned integer, the `uint8_t` type available in `<cstdint>` can be used to represent an 8 bit unsigned integer.

To see the underlying binary representation of a number, the `std::format` function can be used. The `:b` format specifier is used for showing an integer in binary form, `:08b` formats a number in binary with a width of 8 and 0s used to left-pad:

```cpp
uint8_t i { 0 };
std::cout << std::format("{:08b}", i);
// 00000000
```

> The `std::bitset` and `std::byte` types have been introduced in recent versions of the C++ specification but are not yet widely adopted.

## Bitwise operators
**Bitwise operators** are those which work upon the individual bits of a binary number, the three most common are:

- `|`: Bitwise OR
- `^`: Bitwise XOR (Exclusive OR)
- `&`: Bitwise AND

### Bitwise OR
The bitwise OR operator uses the binary representation of two operands to create a new resulting object of the same type. If either operand has a `1` in a bit position, the resulting number also has a `1` in that bit position:

```
0101 | 0011 = 0111
```

### Bitwise XOR
The exclusive or (XOR) operator works similar to the OR operator:

- If both bits in the same position are the same value, then the resulting bit in that position is `0`
- If both bits in the same position are different values, then the resulting bit in that position is `1`

```
0010 ^ 1000 = 1010
```

### Bitwise AND
The bitwise AND operator returns a new object of the same type where bit is set to `1` if both of the operands have a `1` in the same position:

```
1001 & 1101 = 1001
```

## Bit flags
Some libraries make heavy use of bitwise operations, they do this by using them as flags which enable or disable certain features.

### Using bitwise operators for bit flags
Different ways exist to use bit flags, the standard library provides the `std::bitset` type while others use enums.

The steps involved in this include:

1. Choosing a numeric type for the flags, the type has to have enough bits to cover every flag. A `uint8_t` has 8 bits, which accommodates 8 flags.
2. A distinct value needs to be chosen for each flag. Each number chosen for a flag needs to have a single bit set to `1` with all others set to `0`. For an 8 bit int, that would be the numbers `1`, `2`, `4`, `8`, `16`, `32`, `64`, and `128`.

If more bits are needed, the `uint16_t`, `uint32_t`, and `uint64_t` types can also be used for 16, 32, and 64 bits respectively.

```cpp
#include <cstdint>

const uint8_t NONE{0};           // 00000000
const uint8_t RESIZABLE{1};      // 00000001
const uint8_t MOVABLE{2};        // 00000010
const uint8_t CLOSABLE{4};       // 00000100
const uint8_t FULLSCREEN{8};     // 00001000
const uint8_t ALWAYS_ON_TOP{16}; // 00010000
```

These flags can be combined using the `|` operator:

```cpp
uint8_t flags = RESIZABLE | MOVABLE; // 00000011
```

### Checking if a bit flag was set
To check if a bit flag was set, the bitwise `&` operator can be used.:

```cpp
uint8_t flags = RESIZABLE | MOVABLE; // 00000011

if (flags & RESIZABLE)
{
	std::cout << "RESIZABLE was set";
}
else
{
	std::cout << "RESIZABLE was not set";
}
```

This works as the two bit patterns are being compared to see if the patterns have the same active bits:

```cpp
00000011 & 00000001 = 00000001
```

This indicates that the `RESIZABLE` flag was set in this case, any number other than `0` is `true` when treated as a boolean in the if statement. `0` is treated as `false`.