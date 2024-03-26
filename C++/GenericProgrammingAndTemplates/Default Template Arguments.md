Template arguments, for both type and non-type template parameters, can have default arguments like function arguments can. The syntax is similar, using an assignment operator after the identifier:

```cpp
template<typename MyType = int>
void foo();
```

This means the user does not have to specify the parameter when instantiating the template. Any default parameters must come after non-default parameters.

Using default arguments allows for a sensible default option to be provided for a template, while also allowing the user to specify there own:

```cpp
template<typename T>
struct Less
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

template<typename T, typename Comparator = Less<T>>
class SortedArray;
```

The `SortedArray` type example above has a default `Comparator` argument, which can be utilised like so:

```cpp
SortedArray<int> numbers;
SortedArray<int, Greater<int>> numbers2;
```

Prior to C++17, if all type parameters had default arguments, then an empty pair of angle brackets would need to be specified:

```cpp
TemplateType<> identifier;
```

From C++17, this requirement has been removed so that the no angle brackets need to be specified in such a case:

```cpp
TemplateType identifier;
```

