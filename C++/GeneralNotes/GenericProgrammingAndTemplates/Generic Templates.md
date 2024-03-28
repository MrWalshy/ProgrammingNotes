A generic template will be agnostic of whether an argument is a value or reference type, this differs from standard templates which are designed with whether a parameter is a value or reference type beforehand.

An example of this is `std::invoke` in C++17, a function accepting a function as the first argument, followed by a list of arguments, and calls the function with the arguments:

```c++
void doAction(int, float, double);
double d = 1.5;
std::invoke(doAction, 1, 1.2f, d);
```

> Leaving for now and come back to, book is a little wishy washy in its explanation. need an additional source