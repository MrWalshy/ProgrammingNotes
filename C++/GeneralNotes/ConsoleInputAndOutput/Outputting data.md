To output data to the console, use the `std::cout` function provided by the `iostream` library:

```cpp
std::cout << data_here << more_data_to_concat;
```

For example, a `string` and an `int` can be joined together:

```cpp
string name = "Bob";
int age = 22;

std::cout << "Hi " << name << ", you are " << age << " years old correct?" << std::endl;
```

- `std::endl` is for ending a line, it is the same as concatenating the new line character (`\n`).