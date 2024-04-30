An array represents a fixed number of variables called *elements*, it stores them of a particular type in a contiguous block of memory for efficient access.

Arrays are denoted using square brackets:

```c#
string[] names = new string[3]; // array of 3 characters
```

An index is used to access an array element by its position:

```c#
names[0] = "Bob";
names[1] = "Fred";
names[2] = "Alice";

Console.WriteLine(names[0]); // Bob
```

## Iterating through an array
The length of an array can be acquired using the `Length` property, this can be used in a `for` loop to iterate through it:

```c#
for (int i = 0; i < names.length; i++) 
{
	Console.WriteLine(names[i]);
}
```

## Array initialisation expressions
Array initialisation expressions allow declaring and populating an array in a single step:

```c#
string[] names = new string[] { "Bob", "Fred", "Alice" };
string[] names = { "Bob", "Fred", "Alice" };
```

All arrays inherit from the `System.Array` class.

## Default element initialisation
Array elements are always initialised upon instantiation with default values.

### Value type vs reference types
Value and reference type arrays have performance implications. When the element type is a value type, each element is allocated as part of the array:

```c#
int[] i = new int[3]; // [0,0,0]
```

For a reference type, it would allocate `null` values by default:

```c#
string[] names = new string[]; // [null,null,null]
```

## Indices and ranges
Introduced in C#8, these simplify working with an arrays elements.

### Indices
Indices allow referring to an element relative to the end of an array using the `^` operate, `^1` refers to the last element and `^2` to the second to last element. C# indices are implemented using the `Index` type:

```c#
int[] nums = { 1, 2, 3 };
int lastNum = nums[^1]; // 3

Index secondToLast = ^2;
int secondToLastNum = nums[secondToLast]; // 2
```

### Ranges
A range allows for a *slice* of an array to be selected using the `..` operator:

```c#
int[] nums = { 1, 2, 3, 4, 5 };
int[] firstTwo = nums[..2];
int[] lastThree = nums[2..];
int[] middle = nums[2..3];
```

The second number is *exclusive*, the element at that index is not included.

The caret can also be used to indicate a start or end position relative to the end of the array:

```c#
int lastTwo = nums[^2..];
```

These ranges are implemented using the `Range` type in C#.

## Multidimensional arrays
Multidimensional arrays have two varieties, *rectangular* and *jagged*.

- A rectangular array represents an *n*-dimensional block of memory
- A jagged array is an array of arrays

### Rectangular arrays
A rectangular array uses commas for each new dimension, the following would be a two-dimensional array:

```c#
int[,] matrix = new int[3,3];
```

This would have three rows and three columns in each row. The `GetLength` method of the array type returns the length for a given dimension:

```c#
for (int i = 0; i < matrix.GetLength(0); i++)
{
	for (int j = 0; j < matrix.GetLength(1); j++)
	{
		matrix[i,j] = i;
		Console.Write(matrix[i,j] + " ");
	}
	Console.WriteLine();
}
```

Rectangular arrays can also be initialised with explicit values:

```c#
int[,] matrix = new int[,]
{
	{ 0, 0, 0 },
	{ 1, 1, 1 },
	{ 2, 2, 2 }
};
```

### Jagged arrays
A jagged array is declared using pairs of square brackets to represent each dimension. Declaring a jagged array where the outermost array has a length of 3 looks like:

```c#
int[][] matrix = new int[3][];
```

The inner dimensions are omitted as each inner array can be arbitrary in length. Each inner array is initialised to `null` rather than an empty array, so they must be manually initialised:

```c#
int [][] jagged = new int[3][];

for (int i = 0; i < jagged.Length; i++)
{
	jagged[i] = new int[3];
	for (int j = 0; j < jagged[i].Length; j++)
	{
		jagged[i][j] = i + j + 1;
	}
}
```

They can also be explicitly initialised:

```c#
int[][] jagged = new int[][]
{
	new int[] { 1, 2, 3 },
	new int[] { 4, 5, 6},
	new int[] { 7, 8, 9 }
};
```

