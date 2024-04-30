A struct is similar to a class, the main difference is that they represent a value type. This means they are passed by value instead of reference like a class is.

When a struct is assigned or passed to another variable, a new copy of the struct is created and the original is not referenced.

```c#
AccessModifier struct Name
{
	// fields
	// constructors
	// methods
}
```

Some limitations:

- Variables cannot be initialised with values inside the `struct` declaration unless they are marked with the `static` or `const` modifiers
- Constructors without parameters are illegal.
- Structs come with a default constructor that automatically sets all variables to their default values.

```c#
public struct Weapon
{
    public string name;
    public int damage;

    public Weapon(string name, int damage)
    {
        this.name = name;
        this.damage = damage;
    }

    public void PrintWeaponStats()
    {
        Debug.Log($"Weapon: {name} - {damage} dmg");
    }
}
```

They are instantiated just like a class instance:

```c#
Weapon bow = new Weapon("Basic Bow", 10);
bow.PrintWeaponStats();
```

