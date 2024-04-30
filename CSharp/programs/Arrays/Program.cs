using System;

int[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int lastNum = numbers[^1];
Console.WriteLine($"numbers[^1]: {lastNum}");

int[] lastThree = numbers[^3..];
Console.WriteLine("numbers[^3..]:");
for (int i = 0; i < lastThree.Length; i++) {
    Console.WriteLine(lastThree[i]);
}

// rectangular array
Console.WriteLine("Rectangular array");
int[,] matrix = new int[3,3];

for (int i = 0; i < matrix.GetLength(0); i++)
{
	for (int j = 0; j < matrix.GetLength(1); j++)
	{
		matrix[i,j] = i;
		Console.Write(matrix[i,j] + " ");
	}
	Console.WriteLine();
}

// jagged array
Console.WriteLine("Jagged array");
int [][] jagged = new int[3][];

for (int i = 0; i < jagged.Length; i++)
{
	jagged[i] = new int[3];
	for (int j = 0; j < jagged[i].Length; j++)
	{
		jagged[i][j] = i + j + 1;
        Console.Write(jagged[i][j] + " ");
	}
    Console.WriteLine();
}
