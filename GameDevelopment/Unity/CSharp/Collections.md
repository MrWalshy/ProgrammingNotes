## Arrays
The most basic collection type:

- Can store any type of value, all elements need to be of the same type
- Length is static
- Each element is initialised to a default value if none is assigned. Number types default to zero, other types get set to `null` or nothing

```c#
ElementType[] name;
name = new ElementType[length];
```

Example:

```c#
int[] TopScores = new int[3];
```

Direct initialisation:

```c#
// longhand
int[] TopScores = new int[] { 10, 12, 8 };

// shorthand
int[] TopScores = { 10, 12, 8 };
```

Values can be accessed and assigned to by their index:

```c#
TopScores[0] = 30;
int topScore = TopScores[0];
```

### Multidimensional arrays
Arrays can have dimensions, multiple rows and columns essentially. A comma is used in the type declaration for each dimension:

```c#
int[,] Coordinates = new int[3,2]
{
	{ 10, 4 },
	{ 13, 2 },
	{ 5, 2 }
};
```

The subscript to access is the row, followed by a comma, and then the column to access:

```c#
int[] coordinate = Coordinates[0]; // 10,4
int coordinateX = Coordinates[0][0]; // 10
```

C# arrays can have up to 32 dimensions.

The length of an array can be checked with the `Length` property:

```c#
int length = Coordinates.Length;
```

## Lists
A **List** is like an array, but it is mutable and can have a length which changes at runtime as needed:

```c#
List<ElementType> name = new List<ElementType>();
```

Lists can be directly initialised like an array:

```c#
List<ElementType> name = new List<ElementType>()
{
	value1, value2
};
```

The size of an array can be retrieved using the `Count` property:

```c#
Debug.Log(name.Count);
```

### Accessing and modifying a list
The `Add(value)` method appends a new item to a list:

```c#
List<string> PartyMembers = new List<string>();
PartyMembers.Add("Bob"); // { Bob }
PartyMembers.Add("Fred"); // { Bob, Fred }
```

The `Insert(index, value)` method can be used to insert an element into a specific spot:

```c#
PartyMembers.Insert(0, "Charlie"); // { Charlie, Bob, Fred }
```

The `RemoveAt(index)` method is used to remove a specific value at an index, the `Remove(value)` method removes the first matching object:

```c#
PartyMembers.Remove(0); // { Bob, Fred }
PartyMembers.Remove("Fred"); // { Bob }
```

## Dictionaries
The `Dictionary` type stores values as key:value pairs. The key is a index/lookup value for a corresponding value. Unlike arrays and lists, dictionaries are unordered:

```c#
Dictionary<KeyType, ValueType> name;
name = new Dictionary<KeyType, ValueType>();
```

Dictionaries can be directly initialised as well:

```c#
Dictionary<KeyType, ValueType> name = new Dictionary<KeyType, ValueType>()
{
	{ Key1, Value1 },
	{ Key2, Value2 }
};
```

Each key must be unique. The `Count` property can be used to count the number of key-value pairs in the dictionary:

```c#
Debug.Log(name.Count);
```

### Accessing and modifying dictionaries
Both class methods and subscript notation can be used with dictionaries:

```c#
Dictionary<string, int> Inventory = new Dictionary<string, int>() 
{
	{ "Health Potion", 3 },
	{ "Gold", 328 }
};
int amountOfGold = Inventory["Gold"]; // 328
Inventory["Gold"] = 453; // "Gold" = 453
```

The `Add(key, value)` method can be used to insert a new key-value pair into the dictionary:

```c#
Inventory.Add("Silver", 400);
```

If the item already exists, it will be updated instead. The subscript version can also be used to create a new key-value pair.

It is good practice to use the `ContainsKey(key)` method to check if the key exists before to avoid accidentally adding a new pair:

```c#
if (Inventory.ContainsKey("Silver"))
{
	Inventory["Silver"] = 453;
}
```

A key-value pair can be removed with the `Remove(key)` method:

```c#
Inventory.Remove("Silver");
```

