The array container is a fixed-size data structure of contiguous elements, the size needs to be specified at compile time and cannot be changed once defined.

When the array is created, the size of its elements are used to initialise the blocks of data next to each other in memory. Elements cannot be added or removed, but the values can be modified.

To access array elements, the access operator `[]` or the `at()` member function can be used. The access operator does not perform any range checks, the `at()` function does and throws an exception if the index is out of range. The first and last elements can also be accessed using the `front()` and `back()` member operations.

To obtain the size of the array, use the `size()` member function. To check if a container is empty, the `empty()` function can be used; this returns `true` if `size()` is zero.

To include the array class, include the `<array>` header file.