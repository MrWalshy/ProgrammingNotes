The `const` keyword can be used to inform the compiler that a variable cannot have its value modified once initialised:

```cpp
const type variable_name = value;
```

> An object whose state cannot change is known as being **immutable**, this characteristic is generally known as **immutability**.

As an example, the following would be illegal:

```cpp
int main()
{
	const int num = 20;
	num = 10; // Error: Cannot change the value of num
}
```

An object can be considered immutable if its state doesn't change once the object is created, a class can be considered immutable if its instances are immutable.

## Compile-time constants

C++ has the `constexpr` keyword for use when it is necessary for the compiler to evaluate a constant at compile time, every variable declared as `constexpr` is implicitly `const`.

## Constant pointers and references

Pointers and references can also be declared as `const`.

### References

```cpp
const type var_name;
const type &reference_name = variable_name;
```

A reference to an object with the `const` qualifier is known as a **const reference**. This prevents a reference from being used to change the object of the variable they refer to.

A const reference can be bound to a non-const type, this is typically done to express that the object being referenced is to be treated as if it's immutable:

```cpp
type var_name;
const type &reference_name = var_name;
```

The opposite of this is not allowed, `const` objects can only be referred to by `const` references.

### Pointers

A pointer can also point to a `const` object:

```cpp
const type *pointer_name = &variable_name;
```

An example of this might look like:

```cpp
int main()
{
	int v = 10; // 10
	const int *const_v_pointer = &v; // Mem location of v
}
```

- `const` object addresses can only be stored in a pointer to `const`
- A pointer to `const` can point to a non-`const` object. Like in the case of a reference to `const`, there is not guarantee that the object itself will not change; it is just indicated that the pointer cannot be used to modify the object.

As a pointer, unlike a reference, is also an object, a `const` pointer can be created. It is not like a const reference as that is just a short version of *reference to const*. A **const pointer** is a pointer that is itself constant, it may be a `const` or non-`const` object pointed to but the address pointed to by the pointer cannot be changed once it is initialised:

```cpp
type *const pointer_name = &variable_name;
```

- This can be read as: `pointer_name` is a `const` pointer to an object of type `type`.

In code, a const pointer would look like:

```cpp
int main()
{
	int v = 10;
	int *const v_const_pointer = &v;
}
```

A *pointer to const* and a *const pointer* are independent features, but can be expressed in the same statement to indicate that both the pointer object and the pointer are `const`:

```cpp
const type *const pointer_name = &variable_name;
```

