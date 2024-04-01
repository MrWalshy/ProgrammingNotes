The **heap**, also known as *dynamic memory* or *the free store*, is used when you want to manually control the memory allocated and deallocated when using objects. It exists outside of the stack, and so objects declared in the heap are not destroyed when a stack frame is removed.

## Allocating and deleting dynamic memory
To allocate dynamic memory to a variable, the `new` keyword is used to send a request to the operating system for an appropriate amount of memory space for a given type. A pointer to the allocated memory will be returned.

```cpp
int* num { new int { 20 } };
```

The pointer can then be used:

```cpp
std::cout << num << std::endl; // prints the address
std::cout << *num << std::endl; // prints the value
```

To delete the dynamic memory associated with the pointer, the `delete` keyword is called on it. Make sure to not use the pointer afterwards, it references memory no longer allocated in the heap and results in undefined behaviour:

```cpp
delete num;
```

To aid in preventing errors associated with using a dangling pointer, the value `nullptr` can be assigned to it or a new memory address:

```cpp
num = nullptr;
```

## Problems with manual memory management
Some issues can occur as a result of not appropriately managing memory:

- Not calling `delete` on a pointer when there is no need for it is a *memory leak*.
- Calling `delete` on an already deleted resource causes memory corruptions and defects, this is known as the **double-free error**.
- Calling `delete` will cause any components relying on the pointer to stop working correctly.

```cpp
void MyFunction() {
  int* ptr { new int { 42 } };
  AnotherFunction();
  delete ptr;
}
```

This code can result in a memory leak if `AnotherFunction()` throws an exception, this is because the code `delete ptr` is never reached in that case and thus the associated dynamic memory is never freed. **Smart pointers** can help prevent this by applying the concepts of *ownership* to a pointer.