**Container adaptors** are additional STL library container classes with constrained access policies on top of the containers already specified. They have a template parameter that a user can provide to specify the type of container to wrap:

- **Stack**: LIFO access policy, wraps a deque by default.
- **Queue**: FIFO access policy, wraps a deque by default.
- **Priority Queue**: Contained elements have an associated priority, container is accessed as a queue where the next element is the highest in priority. Wraps a vector by default.