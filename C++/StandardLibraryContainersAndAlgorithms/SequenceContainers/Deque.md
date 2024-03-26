The deque container is short for *double-ended queue*. Like vectors, they allow for the fast, direct access of elements and fast insertion and deletion of elements at the back. Unlike vectors, fast insertion and deletion at the front is also possible.

The `Deque` class is defined in the `<deque>` header file.

A deque generally requires more memory than a vector, vectors are more performant for element access and `push_back` so unless front insertions are required, vectors are usually preferred.