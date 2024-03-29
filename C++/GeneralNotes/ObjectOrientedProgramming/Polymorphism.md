Inheritance enables polymorphism, a way of changing the behaviour of code at runtime.

**Static polymorphism** is that of the template system, where templates can be written that work with many different types at compilation time. **Dynamic polymorphism** allows for the behaviour of methods to change while a program is running, this is possible due to **dynamic binding** and **dynamic dispatch**.

## Dynamic binding
> The ability for a reference or a pointer of a base type to point to an object of a derived type at runtime.

```cpp
struct A {};
struct B: A {};
struct C: B {};

B b;
C c;

A& ref1 = b; // b stored as a reference in a variable of type A
A& ref2 = c;

// storing a pointer to a derived type in a base type
A* ptr = nullprt;
if (runtime_condition()) ptr = &b;
else ptr = &c;
```

For dynamic binding to work, the code must know that the derived class derives from the base class.

- If the inheritance visibility is `private`, only code inside the derived class will be able to bind the object to a *pointer* or *reference* of the base class.
- If the inheritance visibility is `protected`, then the derived class and every class deriving from it will be able to perform dynamic binding.
- `public` inheritance visibility will always allow dynamic binding.

Dynamic binding creates a distinction between the `static` type and the `dynamic` (runtime) type, the static type is the type seen in the source code (`ref1` has a static type of a reference to the `A` struct).

The dynamic type is the real type of an object, the type constructed in the objects memory location at runtime. `ref1` has a dynamic type of `B` as it refers to the memory location in which an object of `B` was created, `ref2` has a dynamic type of `C` for the same reason.

The dynamic type can be adjusted at runtime, take the case of `ptr` with the static type of a pointer to `A`, its dynamic type can be altered at runtime as needed:

```cpp
A* ptr = &b;
ptr = &c;
```

Only references and pointers can be assigned values from a derived class safely, assigning an object to a value type would result in the object being *sliced*:

```cpp
B b;
A a = b;
```

This would compile, but only the part of `A` embedded inside of `B` would be copied. This is because when `A` was declared, the compiler dedicated an area of memory big enough only to contain an object of type `A`; this means there isn't enough space for an object of type `B` and the rest of the data gets sliced.

This behaviours occurs due to C++ using *static dispatch* by default for function and method calls; when the compiler sees a method call, it checks the static type of the variable on which the method is called, and it will execute the respective implementation.

C++ supports dynamic dispatch though, this is done by marking a method with the `virtual` keyword. If a method is marked with the `virtual` keyword, when the method is called on a reference or pointer, the compiler will execute the implementation of the dynamic type instead of the static type. This allows for functions to be written with a reference to a base class, and then call methods using the basic class that invoke derived classes methods (polymorphism):

```cpp
void safeTurnOn(Vehicle& vehicle)
{
	if (vehicle.getFuelInTank() > 0.1 && vehicle.batteryHasEnergy())
	{
		vehicle.turnOn();
	}
}

// usage
Car myCar;
Truck truck;
safeTurnOn(myCar); // calls Car specific methods
safeTurnOn(truck); // calls Truck specific methods
```

## Virtual methods
To tell the compiler that dynamic dispatch is wanted, the `virtual` keyword needs to be used:

```cpp
class Vehicle
{
	public:
		virtual void turnOn();
};
```

This will indicate that the matching method in a derived class is a candidate for dynamic dispatch. It is important that the methods have the same signature though otherwise it will just be an overload:

```cpp
struct Base
{
	virtual void foo(int) = 0;
};

struct Derived: Base
{
	void foo(int) override {} // valid override that redefines the virtual method

	void foo(float) {} // overload, signature differs
};

// usage
Derived d;
Base* b = &d;
b->foo(10); // calls the override
```

The `override` keyword was introduced in C++11, it is recommended to use this as the compiler will give an error message of the signature of the override doesn't match the base types virtual method.

- The `virtual` keyword can be used on every override, regardless of depth in the hierarchy chain. It isn't required though as declaring a `virtual` method on the base class results in any override also being `virtual`.
- Dynamic dispatch is disabled inside constructors and destructors.
- Constructors cannot be marked `virtual`, destructors can be though and should if a `virtual` method is defined. This is especially important when classes are created on dynamic memory or the heap.

## Slicing
When working with polymorphic objects, a behaviour called slicing can occur where details of the subclass are lost when it is stored in a superclass variable:

```cpp
class Character {};
class Warrior: public Character
{
	public:
		int defence {20};
};

void Attack(Character e) {}

// main()
Warrior w;
Attack(w); // defence member sliced and no longer exists
```

To prevent this, store the subclass object in a pointer or reference variable to prevent the slicing behaviour from occurring:

```cpp
class Character {};
class Warrior: public Character
{
	public:
		int defence {20};
};

void Attack(Character* e) {}

// main()
Warrior w;
Attack(&w);
```

## Dynamic downcasting
It is possible to downcast using `static_case<T>(T t)`, but this is unsafe. The alternative `dynamic_cast<T>(T)` is safer as it checks whether the object pointed to is actually of the specified type `T`, returning a `nullptr` if it is not:

```cpp
class Character {};
class Warrior: public Character
{
	public:
		int defence {20};
};

void doSomething(Character* e) 
{
	Warrior* warriorPtr = dynamic_cast<Warrior*>(e);

	if (warriorPtr)
	{
		// its a warrior
	}
	else
	{
		// its not a warrior
	}
}

// main()
Warrior w;
Attack(&w);
```