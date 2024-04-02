## Copy semantics
Copying objects is a common theme in programming, how these objects are copied can affect the code in different ways though and potentially lead to errors. In C++, the two common types of copying are *shallow* and *deep* copying.

### Why are copy semantics necessary?
**Shallow copying** is the default behaviour of objects, this leads to only the properties of an object being copied but not the underlying objects they refer to. This might be desired behaviour in the case of a simple class like:

```cpp
struct Vector3
{
	float x;
	float y;
	float z;
}
```

When dealing with pointers as data members though, this can lead to errors. The **double-free error** is the typical cause, this can be explained by:

1. A copy of object `A a`, called `A b`, with a member pointer to an object of type `B` is made. Only the pointer address is copied and not the underlying object that the pointer points-to.
2. Object `a` is destructed, destroying the object in dynamic memory associated with the member pointer. This leaves a dangling pointer on object `b`.
3. The copied object `b` is then destructed, this leads to the **double-free error** when it tries to delete the dangling pointer.

Code that would cause this *double-free* behaviour might look like:

```cpp
struct B {};

class A
{
	B* ptr;

	public:
		A(): ptr(new B{}) {};
		~A() { delete ptr; };
};

int main()
{
	A a;    // a.ptr refers to 00000001
	A b{a}; // b.ptr refers to 00000001 also
}
```

Both objects `a` and `b` will share the same pointer to the same object of type `B`, a shallow copy. When `b` is destructed at the end of the `main()` methods scope, this works fine. When `a` is then destructed, this will potentially then crash the program due to the pointer `ptr` no longer referring to a valid object in memory.

### The rule of three
C++ has a convention called **The Rule of Three** which aims to ensure classes are appropriately designed. The rule states that if **any** of the following are defined in a type, then **all** of them should also be defined in most cases:

- A destructor
- A copy constructor
- A copy assignment operator

### Using shared pointers
Making use of a shared pointer will prevent the crashing issue related to the *double-free error*, but it doesn't solve the problem that only a shallow copy is made. So the shared pointer will still refer to the same object regardless of how many copies are made:

```cpp
struct B {};

class A
{
	std::shared_ptr<B> ptr;

	public:
		A(): ptr(std::make_shared<B>()) {};
};

int main()
{
	A a;    // a.ptr refers to 00000001
	A b{a}; // b.ptr refers to 00000001 also
}
```

### Using unique pointers
A unique pointer will prevent the pointer from being copied when objects are copied

```cpp
struct B {};

class A
{
	std::unique_ptr<B> ptr;

	public:
		A(): ptr(std::make_unique<B>()) {};
};

int main()
{
	A a;
	A b{a};
}
```

This will lead to the compiler throwing a confusing error:

```cpp
'A::A(const A &)': attempting to reference a deleted function
```

This error, caused by the line `A b{a}` attempting to call a constructor of `A(const A &)`, is indicating that a constructor for `A` cannot be found that takes a reference to another object of type `A` as it has been deleted.

As unique pointers cannot be copied, this is why the default copy constructor does not work and is presented as having been *deleted* in the error message. Implementing a custom copy constructor is required to work around this.

## Implementing copy semantics
The implementing of defining how objects should be copied is referred to as **copy semantics**. By default, when constructing an object of type `A` using another object of type `A` like `A b{a}`, this uses the default copy constructor to create a shallow copy.

Implementing a custom copy constructor is simple, it accepts a single parameter as input which holds a `const` reference to an object of the same type:

```cpp
struct B {};

class A
{
	std::unique_ptr<B> ptr;

	public:
		A(): ptr(std::make_unique<B>()) {};
		A(const A& src)
		{
			std::cout << "Object of type A is being copied" << std::endl;
		}
};

int main()
{
	A a;     // ptr: 00000001
	A b{a};  // ptr: 00000000 (not referring to an object)
}
```

- The input `src` is made `const` as we typically don't want to modify the original object.

The current implementation copies the object successfully, but it doesn't initialise a unique pointer to a new object. This is easily remedied by initialising it in the constructor initialiser list:

```cpp
class A
{
	std::unique_ptr<B> ptr;

	public:
		A(): ptr(std::make_unique<B>()) {};
		A(const A& src): ptr(std::make_unique<B>())
		{
			std::cout << "Object of type A is being copied" << std::endl;
		}
};
```

Each copy will now get its own unique object of type `B` in the unique pointer instance it holds as a member.

## Deep copying
The previous implementation does successfully create a copy, but it is not an exact copy including the values of the pointed to object. Consider the following example:

```cpp
struct B 
{
	int value{100};
};

class A
{
	public:
		A(): ptr(std::make_unique<B>()) {};
		
		A(const A& src): ptr(std::make_unique<B>())
		{
			std::cout << "Object of type A is being copied" << std::endl;
		}

		std::unique_ptr<B> ptr;
};

int main()
{
	A a;
	a.ptr->value = 50;
	
	A b{a};

	std::cout << a.ptr->damage << std::endl; // 50
	std::cout << b.ptr->damage << std::endl; // 100
}
```

The copy `b` ends up with a different value from the original, the default value given to the member `int value` of the type `B`. This is because in the `A` classes copy constructor, no arguments are being passed when creating the `B` object; only the `B` classes default constructor is being used.

As the struct `B` does not have any unique pointers, the default copy constructor of that type can be used:

```cpp
class A
{
	public:
		A(): ptr(std::make_unique<B>()) {};
		
		A(const A& src): ptr(std::make_unique<B>(*src.ptr))
		{
			std::cout << "Object of type A is being copied" << std::endl;
		}

		std::unique_ptr<B> ptr;
};
```

Each copy of `A` made will now be a **deep copy**, having the same values as each other. They are different objects though, so can be updated independently without affecting the other.

## Copy assignment operator
C++ classes come with a default implementation of a **copy assignment operator**, this functions like the copy constructor but when using the `=` operator:

```cpp
A a;
B b;
b = a; // copy assignment
```

Like the copy constructor, copy assignment implements shallow copying by default and so errors can ensure. The main difference between the copy constructor and the copy assignment member function is that it commonly returns a reference to itself using the `this` pointer and that the assignments are done within the function body:

```cpp
class A
{
	public:
		A(): ptr(std::make_unique<B>()) {};
		
		A(const A& src): ptr(std::make_unique<B>(*src.ptr))
		{
			std::cout << "Object of type A is being copied" << std::endl;
		}

		A& operator=(const A& src)
		{
			ptr = std::make_unique<B>(*src.ptr);
			return *this;
		}

		std::unique_ptr<B> ptr;
};
```

- It is possible to return by value instead of reference, returning by reference is more efficient though and also allows for chained calls to the copy constructor (`a = b = c`).

### Edge case: Copying an object to itself
There is an unusual usage of the copy operator where an object can be assigned to itself:

```cpp
A a;
a = a;
```

To account for this, an `if` check can be used to compare whether the object to be copied is the same as the one referred to by the `this` pointer:

```cpp
class A
{
	public:
		A(): ptr(std::make_unique<B>()) {};
		
		A(const A& src): ptr(std::make_unique<B>(*src.ptr))
		{
			std::cout << "Object of type A is being copied" << std::endl;
		}

		A& operator=(const A& src)
		{
			if (this != &src)
			{
				ptr = std::make_unique<B>(*src.ptr);
			}
			
			return *this;
		}

		std::unique_ptr<B> ptr;
};
```

## Copy semantics and pass-by-value
When code is used which implicitly creates copies of objects, copy semantics come into play. This typically involves scenarios where objects are passed around by value, like to a function where its parameters are not references or pointers. In such a case, the copy constructor is used to create the object that the function receives.

This can be inefficient when deep copying large data structures, *move semantics* are a feature of C++ that are designed to increase efficiency.

## Copy Elision and Return Value Optimisation
Compilers can reduce the overhead of copying objects by reducing the number of unnecessary copies through a process known as **copy elision**. This increases efficiency by reducing the number of constructor and destructor calls necessary in a program.

Consider the example:

```cpp
struct A
{
	A() = default;
	A(const A& src)
	{
		std::cout << "Copying" << std::endl;
	}
};

A getA()
{
	A a;
	return a;
}

int main()
{
	getA();
	std::cout << "Done" << std::endl;
}
```

In this example, the compiler is able to infer from the `return` statement that the instance of `A` is going to end up in the stack frame of `main()`. Instead of constructing the object in the stack frame of `getA()`, it instead constructs it in the `main()` stack frame. This results in the copy constructor not being invoked, the compiler has **elided** the copy. This is an example of **return value optimisation** (RVO).

Sometimes, RVO cannot be invoked for copying, such a case would happen where the compiler cannot determine which exact object is to be returned at compile time:

```cpp
A getA(bool c)
{
	A a;
	A b;
	return c ? a : b;
}
```

Due to the fact that compilers can implement copy elision, it is best practice not to place side-effects within the constructor as the constructor might not be called in such cases where return value optimisation occurs.