## For statements
The `for` statement allows for code to be executed a specific number of times:

```c#
for (initialiser; condition; iterator) {}
```

Example:

```c#
for (int i = 0; i < 10; i++) {}
```

## foreach loops
The `foreach` loop iterates over a collection type, storing each element in a temporary local variable:

```c#
foreach (ElementType name in collectionVariable) {}
```

Example:

```c#
List<string> PartyMembers = new List<string> { "Fred", "Bob" };

foreach (string partyMember in PartyMembers)
{
	Debug.Log(partyMember);
}
```

### Looping through key-value pairs
When looping through a dictionary, the `KeyValuePair<Key, Value>` type is used:

```c#
Dictionary<string, int> Inventory = new Dictionary<string, int>()
{
	{ "Potion", 10 },
	{ "Gold", 328 }
};

foreach (KeyValuePair<string, int> kvp in Inventory)
{
	Debug.Log($"Item: {kvp.Key}, {kvp.Value}");
}
```

The `Key` and `Value` properties are used to access the key and value properties respectively.

## While loops
Loops while some condition is true:

```c#
while (condition) {}
```

