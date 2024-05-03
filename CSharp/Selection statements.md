There are three main control flow mechanism within C#:

- Selection statements (`if`, `switch`)
- Conditional/ternary operator (`?:`)
- Loop statements (`while`, `do-while`, `for`, `foreach`)

## The `if` statement
The `if` statement executes a statement, or block, if a `bool` expression is `true`:

```c#
if (5 > 0) Console.WriteLine("true");

if (5 > 0)
{
	Console.WriteLine("true");
	Console.WriteLine("5 is greater than 0");
}
```

### The `else` and `else if` clauses
The `else` clause can be used for when an `if` statements condition is not `true`:

```c#
if (0 > 5) Console.WriteLine("true");
else Console.WriteLine("false");
```

The `else if` clause can be repeated multiple times to allow multiple conditions to be specified:

```c#
int age = 30;

if (age >= 65) doFoo();
else if (age >= 18) doBar();
else if (age >= 10) dooFooey();
else doFoobar();
```

## The `switch` statement
`switch` statements are used to branch execution based on a selection of possible values:

```c#
int dayOfWeek = 3;

switch (dayOfWeek)
{
	case 1:
		foo();
		break;
	case 2:
		bar();
		break;
	...
	default:
		Console.WriteLine("Not a day of week");
		break;
}
```

The most common scenario is switching on a constant, which must be a built-in integral type including `bool`, `char`, `enum` types, alongside the `string` type.

At the end of each `case` clause, you should use a jump statement to control where execution goes next:

- `break`: Jump to end of switch statement
- `goto case x`: Jumps to another case clause
- `goto default`: Jumps to default case clause
- Any other jump statement: `return`, `throw`, `continue`, `goto label`

Like in other languages, cases fall through and can be chained:

```c#
int num = 0;

switch (num)
{
	case 0:
	case 1:
	case 2:
		foo();
		break;
	case 3:
	case 4:
		bar();
		break;
}
```

### Switching on types
Recent versions of C# introduced the ability to switch based on a *pattern*, one such way is switching on a type from C#7:

```c#
PrintTheType(10);
PrintTheType("Hi");

void PrintTheType(object x)
{
	switch (x)
	{
		case int i:
			Console.WriteLine("int");
			Console.WriteLine(i * i);
			break;
		case string s:
			Console.WriteLine("it's a string");
			Console.WriteLine($"Length: {s.Length}");
			break;
	}
}
```

Each case clause specifies a type to try match, alongside a variable to assign the typed value on a successful match. Unlike constant based matching, this works with any type.

A predicate can be added to the `case` with the `when` keyword:

```c#
switch (x)
{
	case bool b when b == true:
		break;
	case bool b:
		break;
}
```

If switching on a type is desired, but the value is of no interest, the *discard* can be used (an underscore) in place of the pattern variable name:

```c#
case string _:
	break;
```

Cases can fall through as well, but the pattern variables cannot be used:

```c#
switch (x)
{
	case float f:
	case double d:
		Console.WriteLine("Can only use x here");
		break;
}
```

The `null` value can also be switched on:

```c#
case null:
	break;
```

### Switch expressions
C#8 introduced using `switch` as an expression, returning some value based on a match:

```c#
int dayNumber = 1;
string dayString = dayNumber switch
{
	1 => "Monday",
	2 => "Tuesday",
	...
	_ => "Unknown"
};
```

The `switch` keyword comes after the input, with the case clauses being comma-separated expressions. They can also be used in LINQ queries.

- The `_` represents the default expression. If a switch expression fails to match and does not have a default expression, an exception is thrown.

A *tuple pattern* can also be used to switch on multiple values:

```c#
int dayNumber = 1;
int monthNumber = 2;

string dateString = (dayNumber, monthNumber) switch
{
	(1, 1) => "Monday, January";
	(1, 2) => "Monday, February";
	...
};
```

## Iteration statements
Iteration statements are used to execute a sequence of statements multiple times.

### `while` and `do-while`
These loop statements iterate while some `bool` expression is `true`:

```c#
int i = 0;

while (i < 10)
{
	Console.WriteLine(i);
	i++;
}
```

The `do-while` always executes at least once, unlike a `while` which might never execute:

```c#
int i = 0;

do
{
	Console.WriteLine(i);
	i++;
} while (i < 10);
```

### `for`
The `for` statement is syntactic sugar over a `while` loop, it has special clauses for the initialisation and iteration variables and expressions:

```c#
for (init-clause; condition-clause; iteration-clause)
	statement-or-block
```

A `for` statement might never execute depending on the condition:

```c#
for (int i = 0; i < 10; i++)
{
	Console.WriteLine(i);
}
```

The three clauses can be omitted as desired, an infinite loop would look like:

```c#
for (;;)
	Console.WriteLine("Infinite");
```

### `foreach`
The `foreach` statement is used to iterate over the elements of an enumerable object, most .NET types representing a set or list of elements are enumerable (strings and arrays both are for example):

```c#
foreach (char c in "food")
	Console.WriteLine(c);
```

### Jump statements
- `break`: Ends the execution of a loop or `switch` statement
- `continue`: Goes to the next iteration of a loop
- `goto statement-label`: Goes to the label within a statement block
- `return`: Exits a method and returns a value of the methods return type when not void returning
- `throw`: Throws an exception to indicate an error


