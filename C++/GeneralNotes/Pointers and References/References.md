A **reference** is an alias for an object, it is a way to give another name to an existing variable. References are defined using the following syntax:

```cpp
type variable_name = value;
type &reference_name = variable_name;
```

A program may define multiple references to the same object, but a reference can not be referenced by another reference as it is not an object.
## Example

```cpp
#include <iostream>

int main()
{
    int num = 30;
    int &num_ref = num;
    std::cout << "num: " << num << std::endl;
    std::cout << "num_ref: " << num_ref << std::endl;
    return 0;
}
```

Both `num` and `num_ref` will result in `30` printed to the console as `num_ref` is just an alias for `num`.

## Differences between pointers and references

There are three main differences:

- A reference, once initialised, is bound to a specific object and cannot be reassigned. Operations performed on the reference are operations performed upon the referenced object.
- References must be initialised as they cannot be rebound.
- A reference always has an association with a variable in memory. If the variable is not valid, the reference must not be used.

## References as class members
When a class contains references, the specific members **must** be initialised within the member initialiser list to satisfy the fact that references must be initialised when they are declared (the constructor body is too late for this as the object is already declared with default values):

```cpp
class Foo {};
class Bar
{
	public:
		Bar(Foo& foo): foo(foo) {}

	private:
		Foo& foo;
};
```

If doing this, it needs to be ensured that the lifetime of `Foo` is at least as long as the lifetime of `Bar` wherever it was originally declared and initialised.