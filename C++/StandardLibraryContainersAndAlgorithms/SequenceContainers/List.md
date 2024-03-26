The list container is a data structure of non-adjacent elements that can be dynamically grown, it is defined in the `<list>` header file.

Each element is known as a node, it has a memory segment and links to its predecessor and successor (linked list).

When a new element is inserted into the list, its predecessor nodes is updated so that its successor link points to the new element. Similarly, the successor nodes is updated so that its predecessor link points to the new element.

Unlike a vector, lists do not provide random access. Elements are accessed by following the chain of elements, starting from the first. The main advantage is that insertion and removal in a linked list is fast at any position, the disadvantage is that getting to the node is slow.

The interface is similar to the vector class, lists don't provide the `operator[]` for element access though.