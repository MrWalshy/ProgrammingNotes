Smart pointers are used with the concept of *ownership*, objects owning other objects. This allows for pointers to be automatically cleaned up when the object owning it is deleted.

## What is a unique pointer?
A unique pointer, implemented as `std::unique_ptr`, points to an object in memory; it is *unique* because it should be the only pointer pointing to that object. This means that the function or object owning the unique pointer has exclusive ownership of the object pointed to.

## Creating unique pointers
The `<memory>` header allows usage of the `std::make_unique` function, the preferred way of creating unique pointers:

```cpp
std::make_unique<T>(args);
```

- The type `T` is the type of the pointer
- The `args` are the arguments that would be passed to the constructor of the specified type

The function returns a `std::unique_ptr<T>` object, which will be stored as a local variable usually. When the local variable is automatically destructed, the pointer to the object is also cleaned up (deleted) by having its destructor invoked:

```cpp
void foo()
{
	auto ptr = std::make_unique<int>(50);
	std::cout << ptr << std::endl;
} // ptr is automatically cleaned up

int main()
{
	foo();
}
```

## Dereferencing a unique pointer
A unique pointer, like a *raw pointer*, can be dereferenced to access the object itself and its members using the `*` or `->` operators:

```cpp
#include <memory>
#include <string>
#include <iostream>

struct SomeType
{
	int a;
	float b;
	std::string c;

	SomeType(int a, float b, std::string c): a{a}, b{b}, c{c} 
	{
		std::cout << "Creating SomeType instance" << std::endl;
	}

	~SomeType()
	{
		std::cout << "Destroying SomeType instance" << std::endl;
	}
};

int main()
{
	auto somePtr = std::make_unique<SomeType>(10, 5.f, "Hello");
	std::cout << "somePtr.a: " << (*somePtr).a << std::endl;
	std::cout << "somePtr.b: " << somePtr->b << std::endl;
}
```

## Requesting access to the underlying raw pointer
The design intent of a unique pointer makes it so that copying does not make sense, the `unique_ptr` class deletes the copy constructor to compensate for this:

```cpp
auto ptr1 { std::make_unique<int>(10) };
auto ptr2 { ptr1 }; // compilation error
```

This also applies when passing an argument by value to a function, as it is a form of copy assignment it will result in a compile error. To access the underlying raw pointer, the `get()` member function can be used on a smart pointer to get it.

- This should be seen as requesting access and not ownership, the code requesting access should take care not to *delete* the raw pointer used by the smart pointer.

```cpp
void foo(int* num) {}

int main()
{
	auto ptr { std::make_unique<int>(10) };
	foo(ptr.get()); // access the raw pointer
}
```

## Transferring ownership
Sometimes, ownership of a smart pointer wants to be transferred to a different function or object rather than just accessed. The `std::move` function from the `<utility>` header is used for this purpose. It is important to remember that the original smart pointer variable no longer owns the pointer and cannot be used for that object when it has been moved without causing *undefined behaviour*:

```cpp
#include <memory>
#include <utility>
#include <iostream>

void foo(std::unique_ptr<int> num)
{
	std::cout << "foo() now owns unique pointer to " << *num << std::endl;
	std::cout << "foo() finishing, unique pointer about to be destroyed." << std::endl;
}

int main()
{
	auto ptr = make_unique<int>(10);
	std::cout << "main() currently owns unique pointer to " << *num << std::endl;
	foo(std::move(ptr));
}
```

The process of transferring ownership follows 3 general steps:

1. The lvalue reference to the `unique_ptr` is cast to an rvalue reference, so `ptr` in this example is cast to an rvalue reference when `foo(std::move(ptr))` is called.
2. The resulting rvalue reference from calling `std::move(ptr)`, passed as an argument to `foo`, is then assigned to the parameter `std::unique_ptr<int> num` using either the move constructor or move assignment operator:
	- If the pointed-to object has a move constructor, that is invoked.
	- If the pointer-to object has a move assignment operator instead, that will be invoked.
3. The transfer of ownership is then completed.

## Releasing unique pointers
Unique pointers can release their ownership of an object using the `release()` member function, this returns the raw pointer to the underlying resource rather than delete it so it can be manually managed. Any calls to the member `get()` on the original smart pointer will then return `nullptr`.

## Updating smart pointers with `reset()`
The `reset()` member function will release ownership of an underlying resource, but unlike `release()` it will also delete it. This member optionally accepts a new pointer to an object in dynamic memory to manage instead:

```cpp
#include <memory>
#include <iostream>

int main()
{
	auto ptr { std::make_unique<int>(30) };
	std::cout "ptr currently has address " << ptr.get() << " and value " << *ptr << std::endl;

	ptr.reset(new int {60});
	std::cout "ptr now has address " << ptr.get() << " and value " << *ptr << std::endl;
}
```

## Swapping smart pointers with `swap()`
The `swap()` member function allows for two unique pointers to swap the raw pointer that they have ownership over:

```cpp
#include <memory>
#include <iostream>

int main()
{
	auto ptr1 { std::make_unique<int>(10) };
	auto ptr2 { std::make_unique<int>(20) };

	std::cout << "ptr1 owns value: " << *ptr1 << std::endl; // 10
	std::cout << "ptr2 owns value: " << *ptr2 << std::endl; // 20

	std::cout << "Swapping ownership of ptr1 and ptr2" << std::endl;
	ptr1.swap(ptr2);

	std::cout << "ptr1 owns value: " << *ptr1 << std::endl; // 20
	std::cout << "ptr2 owns value: " << *ptr2 << std::endl; // 10
}
```

## `const` unique pointers
There are four possible combinations when using `const` with unique pointers, these affect whether the pointer, underlying value or both are modifiable or not.

### Non-const pointer to no-const
When `const` is not used for both the pointer and the object it refers to, both are modifiable:

```cpp
auto ptr { std::make_unique<int>(10) };
*ptr = 50; // modify owned object
ptr.reset(); // modify pointer
```

### Const pointer to non-const
A `const` pointer referring to a non-`const` object allows the object to be modified but not the pointer:

```cpp
const auto ptr { std::make_unique<int>(10) };
*ptr = 50; // modify owned object
ptr.reset(); // error
```

### Non-const pointer to const
A non-`const` pointer to a `const` object allows the pointer to be modified but not the underlying object:

```cpp
auto ptr { std::make_unique<const int>(10) };
*ptr = 50; // error
ptr.reset(); // modify pointer
```

### Const pointer to const object
A `const` pointer to a `const` object means neither the pointer nor object pointed-to can be modified:

```cpp
const auto ptr { std::make_unique<const int>(10) };
*ptr = 50; // error
ptr.reset(); // error
```

