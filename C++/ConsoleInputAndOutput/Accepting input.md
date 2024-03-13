The `iostream` library provides the standard input function for reading from the console using `std::cin`. The syntax of its usage is:

```cpp
std::cin >> variable;
```

The program will block waiting for the user to input some data, the input value will then be bound to the `variable` specified.

```cpp
string name;
std::cout << "What is your name?" << std::endl;
std::cin >> name;
```