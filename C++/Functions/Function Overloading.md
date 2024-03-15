C++ allows for functions with the same name but different parameter types, the function signature is what differs. When a function is invoked, the compiler looks in something called the **overload set** which contains all the functions with that name; the compiler picks function that best matches the arguments provided.

```cpp
void foo(int i);
void foo(float f);

// call int overload
foo(30);
// cal float overload
foo(1.5f);
```