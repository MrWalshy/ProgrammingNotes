A **class** combines data and operations together to create new data types for representing complex concepts.

Advantages of classes include:
- **Abstraction**: Allows for the representation of a high-level concept in a simpler way.
- **Information hiding**: The processing of hiding implementation detail from the user of a class while exposing a public interface for them to interact with.
- **Encapsulation**: The principle of grouping the data and the operations performed on it together. The data in a class is typically hidden from the user, with the class providing functionality instead for interacting with that data.

The basic structure of a class looks as follows:

```cpp
class ClassName
{
	// class body
};
```

> The semi-colon after the class body is necessary.

## Data Members and Access Specifiers
Inside a class body, there are two main types of class members that can be defined:

- **Data members**: Variables declared inside the class, known as **fields**.
- **Member functions**: Functions declared inside a class body that can access the fields, known as **methods**.

Classes make use of **access specifiers** to hide information and functionality from the user of a class, declaring its access:

- **Private**: `private` members can only be accessed by functions inside the class.
- **Protected**: `protected` members can only be accessed by functions inside the class and its derived/inherited classes.
- **Public**: `public` members can be accessed from anywhere.

By default, class members have the `private` access modifier if one is not specified. To specify the access, write the specifier followed by a colon to delimit an area in which any following members have that access specifier:

```cpp
class ClassName
{
	private:
		int privateDataMember;
		int privateMemberFunction();

	protected:
		float protectedData;
		float protectedFunction();

	public:
		double publicData;
		double publicFunction();
}
```

## Structs

In C++, an alternative class format exists where the only difference is that class members are `public` by default. Structs are declared using the `struct` keyword instead of the `class` keyword, the following struct and class are equivalent:

```cpp
struct Name
{
	int publicData;
}

class Name
{
	public:
		int publicData;
}
```

A struct is normally used when a collection of data members are required that should be accessible anywhere in the program code, classes are used for modelling more complex concepts.

## Using a class

A class is a blueprint/design of an object, multiple objects can be created from a class in a process known as **instantiation**. Each instantiated object is known as an **instance** of the class.

Consider the following class:

```cpp
class Coordinates
{
	public:
		float latitude;
		float longitude;
		
		float distance(const Coordinates& other_coordinate);
}
```

If a class has a default constructor (none present or one with zero parameters), instances can be created by simply specifying the data type and variable name in a variable declaration:

```cpp
Coordinates londonPosition;
Coordinates manchesterPosition;
```

These are two different instances of the `Coordinates` class.

## Brace initialisation

The fields of a `struct` or `class` can be initialised using brace initialisation in certain circumstances.

Structs:
- When initialising an object of a `struct` type, brace initialisation can be used to directly initialise its members.
- If there is no constructor, provide the elements in the order that the members are declared in the struct.

```cpp
struct ExampleStruct
{
	int x;
	int y;
}

// Usage
ExampleStruct es{10, 20}; // x = 10, y = 20
```

Classes:
- If the class has no constructor, provide the elements in order of declaration.
- If the class has non-default constructors, the order in which parameters appear in the brace initialiser is the order of constructor parameters.

```cpp
class ExampleClass
{
	public:
		ExampleClass() : x(0), y(0) {}
		ExampleClass(int x) : x(x), y(0) {}
		ExampleClass(int x, int y) : x(x), y(y) {}

	private:
		int x;
		int y;
}

// usage
ExampleClass ec1; // x = 0, y = 0
ExampleClass ec2{10}; // x = 10, y = 0
ExampleClass ec3{10, 20}; // x = 10, y = 20
```
### Class scope

When declaring a class, a new scope called the **class scope** is created. Names defined inside the class scope can only be accessed within the same class scope. To access members of a `class` or `struct` from a scope outside the class, use the dot (`.`) operator. Using the `Coordinates` example, the latitude and longitude could be accessed like so:

```cpp
float manchesterLatitude = manchesterPosition.latitude;
float londonLongitude = londonPosition.longitude;
```

Invoking a member function follows the same process:

```cpp
float distance = manchesterPosition.distance(londonPosition);
```

When inside the class scope, the other members of the class can be accessed directly without dot notation:

```cpp
float Coordinates::distance(const Coordinates& other)
{
	return pythagorean_distance(latitude, longitude, other.latitude, other.longitude);
}
```

