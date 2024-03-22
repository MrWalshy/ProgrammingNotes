A **functor** (function object) is similar to a class, a class overloading the `operator()` function is also known as the **function call operator**.

The syntax used to define a functor is:

```cpp
class ClassName
{
	public:
		type operator()(type arg) {}
};
```

The function call operator has a return type and can take any number of arguments of any type. Invoking the call operator is as simple as writing the name of the object followed by parenthesis and passing any arguments:

```cpp
ClassName obj;
type t;
obj(t); // object called as if it was a function
```

> These are useful where a function object can be passed to an algorithmic template accepting an object with `operator()` defined.

A simple example of a **functor** for printing a string before appending a new line:

```cpp
class Logger
{
	public:
		void operator()(const std::string &s)
		{
			std::cout << s << std::endl;
		}
};

// usage
Logger log;
log("Hello world");
log("Something, something, C++");
```

