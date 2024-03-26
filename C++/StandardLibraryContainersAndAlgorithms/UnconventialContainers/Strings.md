A `string`, provided by the `<string>` header, is used to manipulate mutable sequences of contiguous characters. The C++ string classes are STL containers and behave similarly to vectors.

There are several string implementations in the standard library:
- `string`
- `wstring`
- `u16string`
- `u32string`

All are a specialisation of the `base_string` base class and have the same interface, the most commonly used is `string`.

C++ strings can be converted into *null-terminating strings*, an array of characters terminated by the special null character (`\0`) via the use of the `data()` or `c_str()` functions; they are also known as C-strings as they are used to represent sequences of characters in the C language, commonly used when a C++ program needs to interoperate with a C library.

C-strings are represented with the `const char*` type, they are also the type used by string literals.

Methods include:
- `size()`
- `empty()`
- `capacity()`
- `operator[]`: Access character at specific index.
- `at()`: Like `operator[]`.
- `front()`: First character.
- `back()`: Last character.
- `clear()`: Empties the string, same as assigning an empty literal
- `empty(start, numOfChars)`: Like `clear()` but operates using a start index and number of characters to delete.

```cpp
std::string chapter = "Learning about strings";
std::cout << "Length: " << chapter.length() << ", second char is " << chapter[1] << std::endl;
```

Comparison operators are also provided for strings, like `<` and `>`.

Strings are like vectors, so characters can be added to and removed from them.

Convenience functions are also provided. `std::stoi(str)`, the *string-to-int* function, converts a string to an integer. `std::stod(str)`, the *string-to-double* function, converts a string to a double. The `std::to_string()` can be used to convert values to a string.