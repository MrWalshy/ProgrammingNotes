Inheritance allows for one or more classes to have their functionality combined in a hierarchy:

```cpp
class Vehicle
{
	public:
		TankLevel getTankLevel() const;
		void turnOn();
};

class Car : public Vehicle
{
	public:
		bool isTrunkOpen();
};
```

The `Car` class is a derived class which inherits from the base class `Vehicle`, this is indicated by the colon (`:`) after the class name. Multiple inheritance is supported through a comma-delimited list of classes:

```cpp
class C : public A, public B
{
};
```

The classes inherited from can also have the visibility of their inheritance specified, it specifies who can know about the inheritance relationship between the classes.

Inherited methods and fields can be accessed based on specific conditions:

- `public` inheritance: Code external to the class knows that `class B` is derived from `class A`. All public methods of the base class `A` are accessible as public methods of the derived class `B` by code in the program. Protected methods of the base class `A` can be accessed as `protected` by the methods of the derived class `B`.
- `protected` inheritance: All `public` and `protected` members can be accessed as `protected` by the derived class. Only the derived class and classes derived from it know about the inheritance chain; external code sees the classes as unrelated.
- `private` inheritance: All `public` and `protected` methods and fields of the base class accessed by the derived class are `private` to external code.
- Regardless of the inheritance accessibility, all `private` methods and fields of a class can never be accessed outside of that class.

The inheritance access specifier is optional, defaulting to `public` for structs and `private` for classes.

## Construction
With inheritance, the base class becomes embedded in the memory space of the derived class. Due to this, the constructor of the base class needs to be called for proper initialisation.

In the case of a default/no-arg constructor being available in the base class, the compiler will implicitly call it. In the case of the destructor, the compiler will always call the base class destructor after the destructor of the derived class has executed.

If the base class does not have a default constructor, the derived class constructor must explicitly call it in the initialisation list to prevent an error.

```cpp
class A
{
	public:
		A(const std::string& name);
};

class B: public A
{
	public:
		B(int number): A("Name of A"), num(number) {}

	private:
		int num;
};
```

In the case of copy constructors and assignment operators, the generated versions in a base class will be automatically called by the compiler. If writing custom implementations though, they need to be invoked by the user.

As C++ supports multiple inheritance, *ambiguous calls* can happen where the compiler is unsure which method to call in the inheritance hierarchy:

```cpp
struct A
{
	void foo() {}
};

struct B
{
	void foo() {}
};

struct C: A, B
{
	void bar() { foo(); } // ambiguous call
};
```

This can be disambiguated using the scope resolution operator to specify which classes method should be called, `A::foo()` for example.

## Preventing inheritance
The `final` keyword can be used to indicate that a class cannot be inherited from, this will be enforced by the compiler:

```cpp
class Foo: final {}
class Bar: public Foo {} // Error
```

A class can be defined both `final` and inherit from other classes:

```cpp
class Foo {}
class Bar {}
class FooBar final : public Foo, public Bar {}
```

## Invoking a member function from the parent class
Sometimes, you may wish to extend the functionality of a class method. To invoke the method in the parent class, use the class name and the scope resolution operator followed by the method name to invoke:

```cpp
class Foo
{
	public:
		void fooey()
		{
			std::cout << "foo" << std::endl;
		}
};

class FooBar: public Foo
{
	public:
		void fooey()
		{
			Foo::fooey();
			std::cout << "extra foo" << std::endl;
		}
};
```