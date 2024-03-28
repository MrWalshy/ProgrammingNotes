Manually managing memory is error-prone, due to this C++11 introduced **smart pointers**. They behave like pointers, which are called **raw pointers**, but have additional functionality.

Two commonly used smart pointers from the standard library are `std::unique_ptr` and `std::shared_ptr`. Both are used to free the developer from having to make sure the `delete` function is called appropriately.

> These two smart pointers represent different *ownership models*. The owner of an object is the code that determines the objects lifetime (when its created and destroyed).

Ownership is normally associated with the scope of a function or method, this is how the lifetime of automatic variables is controlled:

```cpp
void foo()
{
	int num;
	doAction(num);
} // num gets destroyed 
```

Alternatively, classes might own objects when declared as value types between the data members of the class. In this case, the lifetime of the object is the same as the class:

```cpp
class A
{
	int num;
};
```

`num` will be constructed when an instance of `A` is constructed and destroyed when the instance of `A` is destroyed.

When objects are managed in dynamic memory, the compiler does not enforce ownership anymore. It is still helpful to apply the ownership concept to dynamic memory though...

A function could be the owner of an object in dynamic memory:

```cpp
void foo()
{
	int* num = new number();
	doAction(num);
	delete num;
}
```

Or a class might own it by storing the pointer in its fields and calling `delete` in the destructor:

```cpp
class A
{
	A(): number(new int(0)) {}
	~A()
	{
		delete number;
	}

	int* number;
};
```

The ownership of dynamic objects can also be passed around.

Smart pointers allow for the ownership of the type of pointer to be specified, making sure it is respected so it doesn't have to be manually tracked. Smart pointers should always be used to represent the ownership of objects, raw pointers should only be used to reference objects.

## A single owner with `std::unique_ptr`
The `unique_ptr` is the default pointer type used, it points to an object with a single owner.

- The uniqueness of ownership is guaranteed.
- The unique pointer cannot be copied, so there can only be one.
- When the unique pointer is destroyed, it also deletes the object it owns.

Considering the example where a `Logger*` is created, it can be updated to return a smart pointer:

```cpp
std::unique_ptr<Logger> createLogger()
{
	if (testsRunning())
	{
		std::unique_ptr<TestLogger> logger = std::make_unique<TestLogger>();
		return logger; // logger is implicitly moved
	}
	else
	{
		std::unique_ptr<ReleaseLogger> logger = std::make_unique<ReleaseLogger>("Release logger");
		return logger; // logger is implicitly moved
	}
}
```

- The `std::make_unique` function is a template function introduced in C++15. It takes the object type, creates it in dynamic memory, passes arguments to the object's constructor, and returns a unique pointer to it.

The ownership of the pointer is passed to the parent scope, it would look something like:

```cpp
std::unique_ptr<Logger> logger = createLogger();
```

There are three important points regarding this:

- There is no longer a `new` expression in the body, it has been replaced with `make_unique`.
- A `unique_ptr` to a derived class is created, but a `unique_ptr` to a base class is returned. This mirrors the ability of raw pointers.
- The `move` operation is used on the `unique_ptr`. The unique pointer cannot be copied, but as it is returned from a function, a value must be used otherwise a reference would become invalid after the function returns. Moving the unique pointer transfers ownership of the object to which it points to the recipient of the value.

Unique pointers can also be used with classes, a benefit being that a destructor does not need to be defined as the `unique_ptr` deletes the object automatically when an instance of the class is destroyed:

```cpp
class A
{
	A(): number(std::make_unique<int>()) {}
	std::unique_ptr<int> number;
};
```

If a pointer to the object needs to be passed, without transferring ownership, the `get()` method can be used.

## Shared ownership using `std::shared_ptr`
A `shared_ptr` is an object that has multiple owners, one of several objects may delete the owned object.

- Can be copied many times.
- The object pointed to will remain alive until the last `shared_ptr` is destroyed.

```cpp
class Node
{
	public:
		void addConnectedNode(std::shared_ptr<Node> node);
		void removeConnectedNode(std::shared_ptr<Node> node);

	private:
		std::vector<std::shared_ptr<Node>> connections;
};
```

Similar to `unique_ptr`, the `std::make_shared` function can be used to create a shared pointer to some specific type.

In some instances, a circular dependency may occur between shared pointers. Such as if a node `A` is connected to node `B` and node `B` is connected to node `A`. As they both refer to each other, they will remain alive. A different kind of pointer exists for handling these situations known as a weak pointer (`std::weak_ptr`).

## Using unique and shared pointers with arrays
Like raw pointers, unique and shared pointers can also be used for arrays where the size is only known at runtime. `unique_ptr` can be used with array types, `shared_ptr` can be starting from C++17:

```cpp
std::unique_ptr<int[]> ints = std::make_unique<int[]>();
std::shared_ptr<float[]> floats = std::make_shared<float[]>();
```