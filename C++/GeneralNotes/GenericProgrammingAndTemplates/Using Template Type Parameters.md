Type parameters can be used as if they are a *concrete type* in templates, including applying type modifiers.

The following example shows using the `const` modifier and *reference* modifier in a template function which creates a new object from a different instance of an object:

```cpp
template<typename T>
T createFrom(const T& other)
{
	return T(other);
}
```

Using multiple template type arguments is done through a comma-separated type parameter list:

```cpp
template<typename A, typename B>
A transform(const B& b)
{
	return A(b);
}

template<typename A, typename B>
A createFrom()
{
	B factory;
	return factory.getA();
}
```

The template arguments can be used in the function parameters, return types, or even instantiated directly in the body of the function. The order in which template parameters are declared does not modify how and where they can be used.

## Requirements of template parameter types
When writing a template, you often don't want it to accept any type as this could lead to errors where certain fields, methods, or operations are not available.

As of C++17, there is no easy way to specify the requirements of templates in code - good documentation is the best approach here.


