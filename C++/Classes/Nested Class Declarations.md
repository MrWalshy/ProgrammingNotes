In a class scope, classes can also be declared inside a class. These are called **nested classes**. A nested class has access to the declared names of its outer class, even `private` declarations.

To access a nested class, the scope resolution operator (`::`) is used like when accessing the static members of the outer class:

```cpp
class Coordinate
{
	struct CoordinateDistance
	{
		float x = 0;
		float y = 0;
		static float walkingDistance(CoordinateDistance distance);
	}
};

// Create instance of nested class
Coordinate::CoordinateDistance distance;

// invoking static method inside nested class
Coordinate::CoordinateDistance::walkingDistance(distance);
```

Nested classes are useful for two main reasons:

- When implementing a class, an object is needed for managing some of the class logic. The nested class is usually `private` and not exposed through the public interface in these cases.
- When a different class that is closely related to the outer class is needed to provide some part of the available functionality. These classes are usually publically accessible.

