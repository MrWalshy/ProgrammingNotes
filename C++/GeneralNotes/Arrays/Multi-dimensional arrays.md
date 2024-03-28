A multi-dimensional array is an array of arrays, it is where an array's elements are also arrays themselves:

```cpp
type name[dimension_of_array][dimension_of_elements];
```

In a bi-dimensional array like the example above, the first dimension is typically referred to as the number of rows and the second dimension as the number of columns in each row.

There can be more than two dimensions to an array, but the amount of memory required increases exponentially per dimension.

```cpp
int[2][5] = {
	{ 1, 2, 3, 4, 5 },
	{ 6, 7, 8, 9, 10 }
};
```

As in the case of single-dimension arrays, the number of dimensions can be omitted from the declaration when initialised during declaration.

The nested braces can be omitted when the dimensions are specified as the compiler can infer the length of the internal arrays from the definition:

```cpp
int[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
```