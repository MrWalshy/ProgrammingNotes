It is common or code which interacts with templates to define some public aliases to types. A typical example would be the `value_type type alias` for containers which specifies the type contained in the container:

```cpp
template<typename T>
class MyArray
{
	public:
		using value_type = T;
};
```

The reason for this is that the type of the template parameter for the generic array might need to be known.

If accepting a specific type, this problem does not arise:

```cpp
void createOneAndAppend(std::vector<int>& container)
{
	int newElement{}; // it is known that the vector contains int
	container.push_back(newElement);
}
```

When the type isn't known though, in a template, the `type alias` can be declared inside the container to specify which kind of values it contains and instance a new value:

```cpp
template<typename Container>
void createOneAndAppend(Container& container)
{
	Container::value_type newElement;
	container.push_back(newElement);
}
```

This wouldn't compile though as `value_type` is a **dependent type**, a type derived from one of the template parameters. When the compiler compiles the code, it notices that the `value_type` identifier is accessed in the `Container` class.

This could be a static field or a `type alias`, the compiler will not when it parses the template as it does not know what the `Container` type will be and whether it has a type alias or a static variable. It assumes a static value is being accessed. In this case, the syntax is not valid as `new_element{}` is still had after access to the field.

To solve this, the compiler can be told that we are accessing a type in the class by prepending `typename` to the type being accessed:

```cpp
template<typename Container>
void createOneAndAppend(Container& container)
{
	typename Container::value_type newElement{};
	container.push_back(newElement);
}
```