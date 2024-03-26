The `forward_list` container is similar to the list container, the difference is that it only has forward (successor) links on each node. This means that reverse iteration is not possible. This type is defined in the `<forward_list>` header file.

- Does not provide the `push_back()` or `size()` members
- Insertion is done using `insert_after()`, the new element is inserted after the provided position
- Removal is done through `erase_after()`, which removes the element after the provided position