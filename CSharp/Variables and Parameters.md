A variable represents a storage location with a modifiable value, it can be a *local variable*, *parameter* (*value*, *ref*, *out*, or *in*), *field* (*instance* or *static*), or *array element*.

## The stack and the heap
Variables are stored in the stack or the heap, each has different lifetime semantics.

### Stack
The stack is a block of memory in which local variables and parameters are stored, it grows and shrinks as method or function calls are entered or exited.

Consider the following method:

```c#
static int Factorial(int x)
{
	if (x == 0) return 1;
	return x * Factorial(x - 1);
}
```

The invocation of `Factorial(3)` would create a stack like the following:

```c#
Factorial(x = 1)
Factorial(x = 2)
Factorial(x = 3)
```

Each method invocation gets its own stack frame, which stores the local variables and parameters. When the method ends, it is popped off the stack. So after the `Factorial(x = 1)` invocation has ended, the stack would look like:

```c#
Factorial(x = 2)
Factorial(x = 3)
```

### Heap
The heap is where objects (reference types) are stored. When a new object is created, it is stored on the heap and a reference to it is returned.

During execution, a garbage collector belonging to the runtime periodically deallocates objects from the heap to prevent the program from running out of memory. An object is eligible for deallocation as soon as it is no longer referenced anywhere in the program by something that is alive.

Value-type instances and object references live wherever the variable was declared. If it is as a field within a class type or an array element, it lives on the heap.

Static fields are also stored on the heap, these are not garbage collected until the process (program) ends.

## Default values
