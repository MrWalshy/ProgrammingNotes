Constructors and destructors are used for the initialisation and teardown of an object, constructors are particularly useful as you can use them to choose the initial values of an object.

In the following example, a `struct` is declared for a rectangle:

```cpp
struct Rectangle 
{
	int height;
	int width;
};
```

If an instance of `Rectangle` was created, its `height` and `width` would be initialised to random values as the properties were never set.

> The C++ rule for the initialisation of basic types is that they get non-specified values. Always initialise them as it cannot be guaranteed that they receive a consistent initial value.

## Constructors

Data members are initialised using a constructor, a special member function with the same name as the class and no return type. It is automatically invoked by the compiler when a new object of the class is created.

Invoking a constructor looks like any other function call, except that you do it when declaring a variable with the parameter list following the variable name:

```cpp
Rectangle rectangle(param1, param2, param3, paramN);
```

A zero argument constructor for the `Rectangle` type might look like:

```cpp
struct Rectangle
{
	int height;
	int width;

	Rectangle()
	{
		height = 0;
		width = 0;
	}
};
```

> If a constructor only initialises data members, opting for the using the initialisation list is recommended.

A constructor can also execute code like a normal function body, this is important for a concept called the *class invariant*. A **class invariant** is a set of properties for a class that should be **true** for any given instance of a class. It is known as **invariant** as the set of properties does not change, they are always true.

> Such class invariant concepts are enforceable through the use of `private` members and `public` methods which interact with the concept represented by the class.

For example, a date `struct` operating by the Gregorian calendar wouldn't make sense if coded as follows:

```cpp
struct Date
{
	int day;
	int month;
	int year;
}
```

This is because you could set the `day`, `month`, or `year` to arbitrary values outside of the acceptable ranges. A class invariant for this would enforce that the month is always between 1 and 12, the day between 1 and 31 (sometimes less depending on the month). Independently of any change the user performs on the `Date` object, the invariant must always hold.

Constructors should ensure the class invariant is abided by/respected, after its execution the invariant must hold true.

> The invariant concept is not specific to C++ and does not have a language feature for it. Because of this, it is best practice to document the expected invariant with the class code so developers can easily check what the expected invariant is and ensure they respect it.

### Constructor overloading

A constructor can be overloaded like a function, allowing for multiple different input parameters.

For example, a `Rectangle` might accept a `Square` shape to create a `Rectangle` object from:

```cpp
class Rectangle
{
	public:
	Rectangle();
	Rectangle(Square square);
};
```

> Constructors with a single non-default parameter are also called a **converting constructor**, one which specifies an implicit conversion from the argument type to the class type.

The conversion would be possible using something like:

```cpp
Square square;
Rectangle rectangle(square);
```

Implicit conversions can also occur when calling functions given the appropriate converting constructor is available:

```cpp
void useRectangle(Rectangle rectangle);

int main()
{
	Square square;
	use_rectangle(square);
}
```

The compiler would call the appropriate conversion constructor on the `Rectangle` type to create the object.

To prevent this implicit conversion behaviour, make use of the `explicit` specifier before the constructors definition:

```cpp
explicit ClassName(type arg) {}
```

### Constructor member initialisation
C++ provides a feature to initialise a fields value using **initialisation lists** instead of a constructor, they allow for calling of the constructors of the data members of a class before its constructor body is executed.

The syntax consists of inserting a colon followed by a comma-separated list of constructor initialisations for the class members before the constructor's body:

```cpp
class Rectangle
{
	public:
	Rectangle(): width(0), height(0) {}
	
	private:
	int width;
	int height;
};
```

The constructor body can be left empty as the fields are initialised prior to its execution anyway:

```cpp
Rectangle rectangle;
std::cout << "Width: " << rectangle.width << std::endl; // Width: 0
std::cout << "Height: " << rectangle.height << std::endl; // Height: 0
```

It is recommended to use initialiser lists to initialise member variables in C++, they are mandatory when a data member is `const`.

The order in which members are constructed is the order in the class rather than the initialise list, due to this it is good practice to write the initialiser list in the same order as the fields of the class.

### Aggregate Classes Initialisation
A class or struct with no user-declared constructors, no private or protected specifiers non-static data members, no base classes, and no virtual functions are considered aggregate.

These types of classes can be initialised using a brace-enclosed comma-separated list of initialiser-clauses even though no constructor is present:

```cpp
struct Rectangle
{
	int width;
	int height;
};

Rectangle rectangle = {5, 10};
std::cout << rectangle.width << "," << rectangle.height << std::endl; // 5,10
```

## Destructors
A **destructor** function is called automatically when an object goes out of scope, it's used to destroy objects of its class type.

A destructor has the same name as the class but is preceded by a tilde (`~`), they do not take any arguments nor return any value:

```cpp
class ClassName
{
	public:
	ClassName() {} // constructor
	~ClassName() {} // destructor
};
```

After executing the destructor body and destroying any automatic objects allocated within the body, the destructor calls the destructors for all direct members of the class. The data members are destroyed in reverse order of their construction.

## Default constructor and destructor
All classes require a constructor and destructor, the compiler automatically creates implicitly defined versions if the programmer does not specify any.