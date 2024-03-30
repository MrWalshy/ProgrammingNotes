The insertion operator, `<<`, used with `std::cout` can be overloaded to support custom types as arguments. This is done by overloading the operator using a free function.

Consider the following type:

```cpp
struct Vector3
{
	float x;
	float z;
	float y;
};
```

It is possible to overload the insertion operator to support this. Overloading the `<<` operator will require two parameters, the first of which is `std::ostream` to represent the *output stream* and the second will be a `const` reference to the type to be used:

```cpp
void operator<<(std::ostream& stream, const Vector3& vector)
{
	stream << "x: " << vector.x << ", y: " << vector.y << ", z: " << vector.z;
}
```

## Chaining `<<`
Chaining calls to `<<` makes the overload more useful, allowing for you to continue inserting new values into the output stream. To enable this behaviour, change the return type to `std::ostream&` and return the relevant argument:

```cpp
std::ostream& operator<<(std::ostream& stream, const Vector3& vector)
{
	stream << "x: " << vector.x << ", y: " << vector.y << ", z: " << vector.z;
	return stream;
}
```

## Serialising the object
The required output can be written directly inside the overload, alternatively a `serialize` method could be used for this purpose:

```cpp
struct Vector3
{
	float x;
	float z;
	float y;

	std::string serialize() const
	{
		return std::format("x: {}, y: {}, z: {}", x, y, z);
	}
};
```

This can then be invoked inside the overload of the insertion operator:

```cpp
std::ostream& operator<<(std::ostream& stream, const Vector3& vector)
{
	stream << vector.serialize();
	return stream;
}
```
