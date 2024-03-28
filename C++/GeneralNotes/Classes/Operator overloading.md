C++ allows for operators on user-defined types to be overloaded with a different meaning. This is done by preceding the operator (in-place of a name) with the `operator` keyword:

```cpp
class Point
{
	Point operator+(const Point &other)
	{
		Point newPoint;
		newPoint.x = x + other.x;
		newPoint.y = y + other.y;
		return newPoint;
	}

	private:
		int x;
		int y;
};
```

The following operators can be overloaded:

- `+`, `-`, `*`, `/`, `%`, `^`
- `+=`, `-=`, `*=`, `/=`, `%=`, `^=`
- `<`, `>`, `<=`, `>=`, `++`, `--`
- `<<`, `>>`, `==`, `!=`, `&&`, `||`
- `&=`, `|=`, `<<=`, `>>=`, `[]`, `()`
- `,`, `=`, `&`, `|`, `!`, `~`
- `->*`, `->`, `new`, `delete`, `new[]`, `delete[]`

The following cannot be overloaded:

- `::`, `.*`, `.`, `?:`

## Binary operators
Operators expecting two operands are **binary operands**, the overloading methods need to accept a single parameter. When the compiler encounters the call, the operand on the left will have the method called on it while the right operand will be passed as an argument to the method.

Using the `Point` class example, usage could look like:

```cpp
Point first;
Point second;
Point sum = first + second;
// equivalent to
Point sum2 = first.operator+(second);
```

The compiler will automatically rewrite the `first + second` expression to `first.operator+(second)`.

## Unary operators
Operators expecting a single operand are **unary operators**, the overloading methods must not accept any parameters. The compiler will call the method on the variable to which the operator is assigned:

```cpp
class OverloadingNot
{
	public:
		bool condition = false;

		OverloadingNot& operator!()
		{
			condition = !condition;
		}
};

// usage
OverloadingNot obj;
!obj;
```

The `!obj` will be rewritten as `obj.operator!()`.

> Operator overloading is possible in two ways, as a member function or as a non-member function. The two produce the same effect.