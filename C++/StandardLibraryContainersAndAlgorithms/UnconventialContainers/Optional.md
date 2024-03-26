The `std::optional<T>` type is a container used to contain a value that may or may not be present, the type parameter `T` is the type of value that the `optional` might contain. Value type means that the instance of the class contains the value, copying `optional` will create a new copy of the contained data.

- Defined in the `<optional>` header

Optionals are a good alternative to exceptions where an exception doesn't make sense, such as when it is expected that a certain value might not exist when searching for one:

```cpp
std::optional<User> tryGetUserByEmail(Email email);
```

Two easy methods to use are provided by the `optional` template:

- `has_value()`: Returns `true` if a value is currently held, `false` if it is empty.
- `value()`: Returns the value currently held by the optional, or throws an exception if empty.

In addition, `optional` can be used as a condition in an `if` statement: evaluates to `true` if it contains a value and `false` otherwise.

```cpp
#include <iostream>
#include <optional>

int main()
{
	std::optional<int> currentHour;

	if (not currentHour.has_value()) std::cout << "Time unknown." << std::endl;

	currentHour = 18;
	if (currentHour) std::cout << "Current hour: " << currentHour.value() << std::endl;
}
```

Some convenience features are also provided:

- `std::nullopt` value can be assigned to make it explicit when it was wanted to be empty
- `std::make_optional<T>(T value)` can be used to make an optional from a value
- Can use the dereference operator (`*`) to access the value of `optional` without throwing an exception if the value is not present
- `value_or(defaultValue)` is a method which returns the value contained by an optional or the specified `defaultValue` if it is empty

```cpp
std::optional<std::string> maybeUser = std::nullopt;
std::string name = maybeUser.value_or("Unknown");

maybeUser = std::make_optional<std::string>("email@example.com");
if (maybeUser) std::cout << "User: " << *maybeUser << std::endl;
```

