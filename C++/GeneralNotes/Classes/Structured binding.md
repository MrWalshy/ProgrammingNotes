**Structured binding** is a way of extracting values out of simple data types, consider:

```cpp
struct Vector3
{
	float x;
	float y;
	float z;
};
```

Rather than writing multiple statements extracting each value like the following code, they can be extracted all in one statement:

```cpp
Vector3 v { 1.0, 4.0, 3.0 };
float x { v.x };
float y { v.y };
float z { v.z };
```

The syntax for structured binding looks like:

```cpp
auto [varName1, varName2, varNameN]{simpleObject};
auto [varName1, varName2, varNameN](simpleObject);
auto [varName1, varName2, varNameN] = simpleObject;
```

For the vector example, it could look like:

```cpp
Vector3 v { 1.0, 4.0, 3.0 };
auto [x,y,z]{v};
```
 
 The use of `auto` is mandatory, the compiler will determine the appropriate type for each variable. As with uniform initialisation, the variables are mapped by the position within the object and not by name.
