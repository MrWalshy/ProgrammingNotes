A **member function** is used to manipulate the data members of a class, they are simply a function declared within the body of a class:

```cpp
class Car
{
	public:
	void turnOn() {}
};
```

The dot operator can be used to access the member function from outside the class scope:

```cpp
Car car;
car.turnOn();
```

## Declaring a member function
The member function must be declared inside the class, its implementation can placed either inside or outside the class though.

To implement a member functions definition outside of the class scope, use the scope resolution operator (`::`) to declare that the referred to function is a member of the class:

```cpp
class Car
{
	public:
	void turnOn();
};

void Car::turnOn() {}
```

## Using `const` member functions

Member functions can be given the `const` qualifier, this limits a functions access to being read-only.

> A member function which accesses a `const` data member must itself be declared as `const`, `const` member functions are not allowed to modify an objects state or call another function that does so.

A `const` member function is declared by placing the `const` keyword after the function name but before its body:

```cpp
class Car
{
	std::string& getColour() {}
	const std::string& getColour() const {}
}

Car car;
car.getColour(); // calls std::string& getColour()

const Car constCar;
constCar.getColour(); // calls const std::string& getColour() const
```

Overloading allows for two functions to match in name and parameter but differ by the `const` value. The `const` variant will only be invoked when it is called on a `const` object.

