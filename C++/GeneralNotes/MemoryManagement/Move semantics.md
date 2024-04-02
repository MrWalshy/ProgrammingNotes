## Resources and subresources
The following types are used for the examples:

```cpp
struct Subresource
{
	Subresource()
	{
		std::cout << "Creating subresource" << std::endl;
	}

	Subresource(const Subresource& src)
	{
		std::cout << "Copying subresource (expensive)" << std::endl;
	}
};

struct Resource
{
	Resource(): sub(std::make_unique<Subresource>())
	{
		std::cout << "Creating resource" << std::endl;
	}

	Resource(const Resource& src): sub(std::make_unique<Subresource>(*src.sub))
	{
		std::cout << "Copying resource" << std::endl;
	}

	std::unique_ptr<Subresource> sub;
};
```

The examples assume that the `Subresource` holds lots of data and is expensive to copy due to being a *deep copy*.
## Why are move semantics needed?
Move semantics increase the efficiency of a program, it is useful for complex objects which have sub-objects that may also contain there own objects, potentially numbering thousands of sub-objects. Avoiding unnecessary copies is a natural result of this when programming.

Consider the following code, which shows how such expensive copies can easily occur:

```cpp
int main()
{
	std::vector<Resource> resources;
	Resource a;
	resources.push_back(a);
}
```

Passing the resource by value to the `push_back()` method results in a copy of the object `a` being made, this could result in performance costs for complex objects.

## The move constructor
The basic idea is that instead of copying all of the subresources to a new resource object, the new object just takes control of the existing subresources. Essentially, instead of deep copying the object, a shallow copy is made followed by the transfer of ownership of the subresources to the new object. To support such **moving**, the type in question needs to implement **move semantics**.

```cpp
struct Resource
{
	// default and copy constructor omitted

	// move constructor
	Resource(Resource&& src)
	{
		std::cout << "Moving resource" << std::endl;
	}
};
```

There are two main differences to the copy constructors:

- The `&&` on the parameter type denotes an *rvalue reference*, a reference which can only bind to temporary objects. Copy constructors instead use an lvalue reference with a single `&`.
- The move constructor will modify the `src` object, by taking its resource, so the parameter is not marked as `const`.

To use move semantics instead of copy semantics, the `std::move()` function from the `<utility>` header, like used with unique pointers, is used to signal to the compiler that it is safe to use the types move semantics:

```cpp
Resource original; // Creating resource
Resource a{original}; // Copying resource
Resource b{std::move(original)}; // Moving resource
```

## Implementing move semantics
Move semantics can be seen as an alternate way of creating copies of an object:

- Copy constructors are used when the original object still needs to be used, the copy constructor doesn't modify the original.
- Move constructors are used when the original object is no longer needed, the subresources of it will be moved to the new object. This is faster than copying them.

How exactly move semantics should be implemented depends on the resources and subresources nature.

```cpp
struct Resource
{
	Resource(): sub(std::make_unique<Subresource>())
	{
		std::cout << "Creating resource" << std::endl;
	}

	Resource(const Resource& src): sub(std::make_unique<Subresource>(*src.sub))
	{
		std::cout << "Copying resource" << std::endl;
	}

	Resource(Resource&& src): sub(std::move(src.sub))
	{
		std::cout << "Moving resource" << std::endl;
	}

	std::unique_ptr<Subresource> sub;
};
```

This allows for using copy or move semantics as needed now:

```cpp
Resource original; // Creating resource
Resource a{original}; // Copying resource

if (original.sub.get()) std::cout << "original still has subresource" << std::endl;

Resource b{std::move(original)}; // Moving resource

if (!original.sub.get()) std::cout << "original doesn't have subresource" << std::endl;
```

## The moved-from state
After the move semantics are used, it leaves the original object in a potentially unusable state known as the *moved from* state. We tell the compiler that this is ok by using the `std::move()` function. In most compilers, any further use of the original object left in the moved from state will cause it to issue a warning about using a moved from object.

It should be kept in-mind that the moved-from object still exists until it is freed from memory, meaning it could still have a user-defined destructor called at some point in the future. If dealing with raw pointers, this could potentially lead to the *double-free* error. To diffuse the error in that case, the raw pointer can be set to `nullptr`; calling `delete` on a `nullptr` is valid and has no effect.

## The move assignment operator
When implementing the move constructor, as with the copy constructor, it is advisable to also implement the associated assignment operator to allow movement to be used in a variety of ways (`b = std::move(a)`).

```cpp
struct Resource
{
	Resource(): sub(std::make_unique<Subresource>())
	{
		std::cout << "Creating resource" << std::endl;
	}

	Resource(const Resource& src): sub(std::make_unique<Subresource>(*src.sub))
	{
		std::cout << "Copying resource" << std::endl;
	}

	Resource(Resource&& src): sub(std::move(src.sub))
	{
		std::cout << "Moving resource" << std::endl;
	}

	Resource& operator=(Resource&& src)
	{
		std::cout << "Moving by assignment" << std::endl;
		sub = std::move(src.sub);
		return *this;
	}

	std::unique_ptr<Subresource> sub;
};
```

Interestingly, if a move constructor is not available then `std::move()` will invoke a copy constructor if available.
### Moving an object to itself
Like with copying, it is also valid to move an object to itself using `a = std::move(a)`. The same conditional `if` check can be used for such a scenario:

```cpp
Resource& operator=(Resource&& src)
{
	if (&src != this)
	{
		std::cout << "Moving by assignment" << std::endl;
		sub = std::move(src.sub);
	}
	
	return *this;
}
```