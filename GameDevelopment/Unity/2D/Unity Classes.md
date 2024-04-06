Unity uses C# as its development language for scripts, these scripts can be attached to objects to provide functionality.

## The `MonoBehaviour` and `ScriptableObject` classes
The `MonoBehaviour` class is what all game object classes inherit from, it provides the basic structure for a class and is attached to the game object; this class is used to implement the logic of a game. The `ScriptableObject` class is used as an object that contains data, it cannot be directly attached to an object. When creating game objects, it is usually appropriate to create a common base class with the statistics and basic behaviours that all entities in the game will have. The 

First, create a new class within the `Scripts` folder by right-clicking inside it and then selecting `Create > C# Script`. Once done, a base classes code might look like:

```c#
public class Entity : ScriptableObject
{
    public string Name;
    public string Occupation;
    public string Weapon;

    public Vector2 Position;

    public int Age;
    public int Level = 1;
    public int Health = 2;
    public int Strength = 1;
    public int Magic = 0;
    public int Defense = 0;
    public int Speed = 1;
    public int Damage = 1;
    public int Armour = 0;
    public int NumberOfAttacks = 1;

    string Faction;
}
```

Making the fields `private` and adding the `[SerializeField]` attribute will make this safer.
## The `Player` object
Basing the `Player` class on the base `Entity` class makes defining the players behaviours simpler:

```cpp
public class Player : Entity
{
    [SerializeField]
    string[] inventory;

    [SerializeField]
    string[] skills;

    [SerializeField]
    int money;
}
```

## Adding common behaviours
Any behaviours common to all game objects should be placed in the `Entity` base class:

```c#
public class Entity : ScriptableObject
{
    // attributes

    public void TakeDamage(int amount)
    {
        Health -= Mathf.Clamp(amount - Armour, 0, int.MaxValue);
    }

    public void Attack(Entity entity)
    {
        entity.TakeDamage(Strength);
    }
}
```

All entities are able to attack and receive damage, this is just a simple implementation and does not mirror how you might actually approach it.

## Accessing the components of a game object
To access the components of a game object, the `GetComponent<T>()` function needs to be used:

```c#
var renderer = this.GetComponent<Renderer>();
var collider = renderer.GetComponent<Collider>();
RigidBody rigidBody = collider.GetComponent<RigidBody>();
```

If anything needs to be used in other methods, an `Awake()` method can be placed on the object that is called when the script *awakes* to initialise fields to hold the object reference.

An alternative way of retrieving a component is to directly specify the type and cast it on the spot:

```c#
rigidBody = (RigidBody2D)GetComponent(typeof(RigidBody2D));
```

