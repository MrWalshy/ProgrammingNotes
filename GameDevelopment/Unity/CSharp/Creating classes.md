A class is declared using the `class` keyword:

```c#
public class Character {}
```

An access modifier can also be specified. A new instance can be created from the class:

```c#
var char1 = new Character();
var char2 = new Character();
```

## Fields
A field is a variable on the class, it belongs to each instance created from it:

```c#
public class Character
{
    public string name;
    public int exp = 0;
}
```

## Constructors
A constructor can be used to initialise the values of an instance.

- Default constructor is generated if one is not specified. Any fields are set to their default values - numbers as `0`, booleans as `false`, reference types as `null`
- Custom constructors can have parameters like methods
- Classes can have multiple constructors

```c#
public class Character
{
    public string name;
    public int exp = 0;

	public Character()
	{
	    name = "Unknown";
	}
	
	public Character(string name)
	{
	    this.name = name;
	}
}
```

These constructors are invoked based on the parameters passed:

```c#
var char1 = new Character(); // name = "Unknown"
var char2 = new Character("Fred"); // name = "Fred"
```

