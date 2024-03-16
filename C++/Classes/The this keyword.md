The `this` keyword is used in a `class` context, it is a pointer whose value is the address of the object on which the member function is called. It can be used inside any non-static member function of a class.

```cpp
class Car
{
	std::string colour;

	void setColourToRed()
	{
		this->colour = "Red";
	}

	void setColourToBlue()
	{
		this->colour = "Blue";
	}
};
```

> The syntax `pointer->member` is a convenience provided to access the member of a `struct`/`class` pointed to by `pointer`. It is equivalent to dereferencing a pointer and using dot notation like so: `(*pointer).member`.

If a function parameter has the same name as a field, it is said to *shadow* the field. To disambiguate between them, make use of `this->shadowedName` and `shadowedName` to refer to the field and parameter respectively.