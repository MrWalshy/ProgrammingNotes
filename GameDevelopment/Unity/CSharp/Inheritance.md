Classes can inherit from other classes, only a single class though. This is done by specifying the class to inherit from after a colon:

```c#
public class Character {}
public class Troll: Character {}
```

Any class members denoted as `public`, `protected`, or `internal` will be automatically inherited, constructors will not be inherited.

## Base constructors
The `base()` keyword can be used with a constructor to call the constructor of a parent class:

```c#
public class Child: Parent
{
	public Child(): base()
	{}
}
```

If there is a parameter in the parent class constructor, that can also be used:

```c#
public class Child: Parent
{
	public Child(string foo): base(foo)
	{}
}
```

