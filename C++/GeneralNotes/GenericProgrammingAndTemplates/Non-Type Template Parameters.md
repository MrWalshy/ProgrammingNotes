A **non-type template parameter** is a template parameter that is not a type, it is a value instead. 

An example of this is when an `std::array` is declared, its type and capacity is specified within the angle brackets (`std::array<int, 10>`). The second parameter is a non-type template parameter.

To declare a non-type template parameter in the parameter list of a template, specify the *data type* followed by an *identifier*:

```cpp
template<typename T, unsigned int size>
class Array
{
	// implementation
}
```

> Non-type template parameters must be of integral type, regular type parameters do not have this restriction.