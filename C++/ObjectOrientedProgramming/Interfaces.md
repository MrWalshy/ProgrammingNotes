An interface is a way of specifying a contract in which the caller needs to provide to call some functionality. To specify an interface, an **Abstract Base Class** (ABC) is required; *abstract* meaning it cannot be instantiated and *base* meaning it is designed to be inherited from.

Any class defining a pure virtual method is `abstract`, a pure virtual method is a virtual method ending with `= 0`:

```cpp
class Vehicle
{
	public:
		virtual void turnOn() = 0;
};
```

A pure virtual method does not have to be defined, this results in the class not being instantiable as there is no code to call for its pure virtual methods. The class is instead derived from and its pure virtual methods are overridden, a class deriving from an ABC is one of the following:

- Another abstract base class if it declares an additional pure virtual method, or if it does not override all the pure virtual methods of the base class.
- A regular concrete class if it overrides all the pure virtual methods of the base class.

```cpp
// Abstract Base Class
class GasolineVehicle: public Vehicle
{
	public:
		virtual void fillTank() = 0;
};

// Concrete class
class Car: Public GasolineVehicle
{
	virtual void turnOn() override {}
	virtual void fillTank() override {}
};
```

Although abstract base classes cannot be instantiated, variables with references or pointers to them can be defined:

```cpp
Car c;
GasolineVehicle* gv = &c;
```

Some best practices when designing an interface in C++ include:

- An abstract base class should not have any data members or fields.
- An abstract base class should always define a virtual destructor (`virtual ~Interface() = default`).
- All the methods of an abstract base class should be pure virtual, implementations should be separate from the interface.
- All of the methods of an abstract base class should be `public`.
- All the methods of an abstract base class should be regarding a single functionality.
- Consider disabling copy and move constructors and assignment operators on the interface (`Interface(const Interface&) = delete;` and similar) or making them `protected` to stop slicing occurring when copying objects between reference or pointer variables of the base type.