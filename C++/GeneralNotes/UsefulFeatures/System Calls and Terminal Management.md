## System calls
The `std::system()` function accepts a string that is sent to the operating systems command processor. This can be used to clear the terminal screen in Windows:

```cpp
system("cls);
```

## Terminal Management

### Clearing the console
When working with the terminal, different commands exist for Windows and Unix based systems. To account for this, the compiler will define a `_WIN32` preprocessor directive when building for Windows, Checking for this with conditional directives can be used to include a specific command:

```cpp
#if defined _WIN32
system("cls");
#else
system("clear");
#endif
```

### User input
To get input from the terminal, the `std::cin` input stream and the `std::getline()` function can be used:

- `std::cin`: Used with the extraction operator (`>>`) to read from the standard input stream until whitespace or the end of file is reached. Line-buffering is used by default, so it waits for the user to press the Enter key before reading the input. It can be used to read data of a variety of types, including integers, floating-points, characters, strings, etc...
- `std::getline(istream& is, string& op, char delim)`: Takes two arguments, the first being the input stream and the second being a reference to a string to be populated with the user input. A third optional argument for a delimiter to read to is also allowed. This reads input until the end of the line, end of file, or the specified delimiter. Line buffering is enabled by default. The header `<string>` is needed to use this function.

```cpp
std::string userInput;

std::cout << "> ";
std::getline(std::cin, userInput);

std::cout << "> ";
std::cin >> userinput;
```