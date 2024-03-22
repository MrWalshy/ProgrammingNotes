A special type of constructor is the **copy constructor**, this initialises the data members of an object from those of another object.

> The passed object is typically of *type reference* to the class itself and possibly `const` qualified.

Syntax looks like:

```cpp
class ClassName
{
	public:
	ClassName(const ClassName& other) : member(other.member) {}

	private:
	type member;
}
```

If a copy constructor is not explicitly declared and all the data members have a copy constructor, the compiler will implicitly declare a copy constructor which copies all of the class members in the same order of initialisation.

An example of this:

```cpp
struct A
{
	A() {}
	A(const A& a)
	{
		std::cout << "Copy construct A" << std::endl;
	}
}

struct B
{
	B() {}
	B(const B& b)
	{
		std::cout << "Copy construct B" << std::endl;
	}
}

class C
{
	A a;
	B b;
	// implicit copy constructor generated as A and B have copy constructors
}

int main()
{
	C first;
	C second(first);
	// Prints: "Copy construct A", "Copy construct B"
}
```

> If a pointer is copied, the object pointed to is not copied. Instead, the address at which the object is located is copied.

## The copy assignment operator
An alternative way of copying an object is through the **copy assignment operator**. Unlike the copy construct operator, this is called when the object has already been initialised.

The assignment operator signature and implementation looks similar to the copy constructor, the only difference being that the assignment operator is an overload of the `=` operator and generally returns a reference to `*this` (not required to though):

```cpp
class ClassName
{
	public:
		ClassName& operator=(const ClassName& other)
		{
			member = other.member;
		}

	private:
		type member;
}
```

For the copy assignment operator, the compiler also generates one implicitly if one is not explicitly declared. The members are copied in order of initialisation.

Both a copy constructor and and copy assignment operator can be used in the same class:

```cpp
class ClassName
{
	public:
		ClassName& operator=(const ClassName& other)
		{
			member = other.member;
			std::cout << "Copy assignment operator called" << std::endl;
		}

		ClassName(const ClassName& other) : member(other.member)
		{
			std::cout << "Copy constructor called" << std::endl;
		}

	private:
		type member;
}
```

Usage would look like:

```cpp
ClassName obj;

ClassName objCopy1(obj);
ClassName objCopy2 = obj;
```

## The move-constructor and move-assignment operator
Moving allows for the data members of an object to be set equal to those of another data member. The difference between this and copying is that the content is transferred from one object to another, removing it from the source.

> Involves the concepts of **rvalue** and **lvalue**. An **lvalue** is an expression, with an address accessible by the program, whose evaluation determines the identity of an object, bit-field, or function (variable names, array elements, function call retuning an **lvalue reference**, bit-fields, unions, class members). An **rvalue** is an expression whose evaluation initialises an object or computes the value of an operand for an operator, it does not have an accessible address (literals, function calls returning a non-reference type, temporary objects created during expression evaluation).

The move-constructor and move-assignment are members taking a parameter of type `rvalue` reference to the class itself:

```cpp
ClassName(ClassName && other); // move constructor
ClassName& operator=(ClassName && other); // move-assignment
```

> The `rvalue` reference is indicated by placing an `&&` operator after the type of the function argument.

This allows for resources owned by an `rvalue` object to be moved into an `lvalue` without copying. The source object that the data members are moved from needs to remain valid though, it is fundamental to reset the data members of the source object to a valid value to prevent the destructor from freeing the resources (like memory) of the class multiple times.

```cpp
class MoveExample
{
	public:
		MoveExample(MoveExample&& other)
		{
			_resource = other._resource;
			other._resource = resetResource;
		}

		~MoveExample()
		{
			if (not is_reset_resource(_resource)) release_resource(_resource);
		}

		private:
			Resource _resource;
}

// Usage
MoveExample obj1;
{
	// call move constructor
	MoveExample obj2(std::move(obj1));
}
// obj2 is destroyed, _resource is released
// first is destroyed, duplicate _resource release does not occur
```

The move constructor and move assignment operator will be implicitly generated if:
- No user-defined ones are provided
- No user-declared destructors, copy constructors, or copy or move assignment operators.

```cpp
struct MovableClass
{
	MovableClass(MovableClass&& other)
	{
		std::cout << "Move construct" << std::endl
	}

	MovableClass& operator=(MovableCLass&& other)
	{
		std::cout << "Move assign" << std::endl;
	}
};

// usage
MovableClass first;
MovableClass second = std::move(first); // move construct
// or MovableClass second(std::move(first));
MovableClass third;
second = std::move(third); // move assignment
```

## Preventing implicit constructors and assignment operators
To prevent implicit generation, write the declaration of the constructor or operator and add `= delete;` at the end of the declaration:

```cpp
class Rectangle
{
	int length;
	int width;

	Rectangle(Rectangle&& other) = delete;
	Rectangle& operator=(Rectangle&& other) = delete;
}
```

