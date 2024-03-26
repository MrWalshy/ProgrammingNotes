Most algorithms accept a unary or binary predicate, a **Functor** which accepts either one or two parameters. The predicates allow the user to control some of the actions that an algorithm carries out.

As functors can be verbose to write, a class with an overload of `operator()`, C++ allows for lambda expressions to be written. These create a special function object with a type known only by the compiler, they behave like a function but can access the variables in the scope in which it is created.

The syntax is similar to functions:

```cpp
[capture variables] (arguments) { body }
```

Lambdas are simple to create, for example one follows which takes two integers and returns their sum:

```cpp
auto sumNumbers = [] (int a, int b) { return a + b; };
std::cout << sumNumbers(10, 20) << std::endl;
```

By default, the lambda body can only reference variables defined in the argument list and inside the body. Additionally, they can **capture** a variable in the local scope and use it in their body. *Capture variables* entail a list of variables names that can be referenced in the body, captured variables are stored inside the created function object; they are *captured by value* by default and thus copied:

```cpp
int addend = 1;
auto sumNumbers = [addend] (int b) { return addend + b; };
addend = 2;
std::cout << sumNumbers(3) << std::endl; // 4
```

Some situations might require modifying the value of a variable in the scope the lambda was created in, or its current value accessed. Capture by reference with the `&` operator prepended to the variable name. It is important to ensure that the referenced variable is still valid when the lambda is invoked though, otherwise the body accesses an invalid object and results in bugs (prefer capture by value).

```cpp
int multiplier = 1;
auto multiplyNumbers = [&multiplier](int b) { return multiplier * b; };
multiplier = 2;
std::cout << multiplyNumbers(3) << std::endl; // 6
```

