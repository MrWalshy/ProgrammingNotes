Weak pointers work with shared pointers, the main difference is that a weak pointer does not actively have ownership of a resource nor the lifecycle management of the object it points to.

- The weak pointers can view the resource, but not affect its lifespan.
- The lifespan of a resource is managed solely by the shared pointers.
- If all shared pointers to a resource are destroyed, the weak pointer essentially becomes an empty pointer.

Weak pointers are useful for:

- Breaking circular references: When two objects hold a shared pointer to each other, neither can be deallocated (circular dependency). Converting one of the shared pointers to a weak pointer breaks the circular dependency, allowing for deallocation to occur.
- Handling dangling pointers: It's difficult to detect when a raw pointer is dangling, but easy with weak pointers.
- Caching mechanisms: When objects are temporarily stored for quick access, weak pointers can reference the objects without affecting their lifecycle.

## Creating a weak pointer
 Weak pointers are represented by the `std::weak_ptr<T>` type declared in the `<memory>` header, weak pointers are commonly initialised using a shared pointer:

```cpp
auto sharedPtr { std::make_shared<int>(30) };
std::weak_ptr<int> weakPtr { sharedPtr };
```

Type deduction can be used to automatically infer the type of the weak pointer from the shared pointer, so specifying the type isn't necessary:

```cpp
auto sharedPtr { std::make_shared<int>(30) };
std::weak_ptr weakPtr { sharedPtr };
```

## `use_count()` and `expired()`
Similar to other smart pointers, weak pointers can use the `use_count()` member to return the number of pointers sharing ownership of the pointed-to resource. As weak pointers are not classed as an owner of a resource, they do not contribute to this count:

```cpp
auto sharedPtr { std::make_shared<int>(30) };
std::weak_ptr weakPtr { sharedPtr };
std::cout << weakPtr.use_count() << std::endl; // 1
```

If the `use_count()` of a weak pointer is `0`, this indicates the underlying resource has been deallocated; any weak pointers with `0` underlying owners are considered **expired**. The `expired()` member function can be used for checking this, returning `true` if it is expired and `false` otherwise:

```cpp
auto sharedPtr { std::make_shared<int>(30) };
std::weak_ptr weakPtr { sharedPtr };

if (!weakPtr.expired()) std::cout << "Pointer isn't expired" << std::endl;

sharedPtr.reset();

if (weakPtr.expired()) std::cout << "Pointer is expired" << std::endl;
```

## Accessing an object through a weak pointer
Accessing objects through a weak pointer is slightly more complex than other pointer types, this is because the weak pointer could be expired. To use the underlying object, a shared pointer needs to be created from the weak pointer first. This registers an owner and is referred to as **locking** the weak pointer, this offers protections in multi-threaded environments preventing another thread from deallocating an object by preventing the `use_count()` from dropping below `1`.

Create a shared pointer from a weak pointer using the `lock()` member function:

```cpp
auto sharedPtr { std::make_shared<int>(30) };
std::weak_ptr weakPtr { sharedPtr };

// somewhere else in the code
if (std::shared_ptr lockedPtr { weakPtr.lock() })
{
	std::cout << "Value: " << *lockedPtr << std::endl;
}
else
{
	std::cout << "The pointer is expired" << std::endl;
}
```

- C++17 introduced creating variables scoped to an `if` statement within its condition.
- Coercing a shared pointer to a bool allows for checking if a pointer is valid or not, converting to `false` if it isn't and `true` if it is.

The main benefit of using weak pointers is that they can be easily checked to see if they have expired, dangling raw pointers on the other hand are hard to check as they still coerce to `true` in an `if` statement. This is why it is recommended to set raw pointers to `nullptr` instead of leaving them dangling, but this can also cause errors to occur when an object is expecting the pointer to still be valid.