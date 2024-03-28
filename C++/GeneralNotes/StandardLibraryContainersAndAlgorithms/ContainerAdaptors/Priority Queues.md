A queue where elements are accessed according to their priority, in descending order (highest priority first). Also defined in the `<queue>` header file.

Interface is similar to the `queue` class with `push()`, `top()` and `pop()`. The next element is determined as the element with the highest priority rather than the first inserted though.

- Default comparator is the `operator<`.