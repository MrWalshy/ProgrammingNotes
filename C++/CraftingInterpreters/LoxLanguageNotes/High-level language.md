Lox is a high-level language, it abstracts things the user does not need to know about.

## Dynamic typing
Lox is dynamically typed, variables can store values of any type, and a single variable can store values of different types at different times. Type errors are detected at runtime due to this.

## Automatic memory management
High-level languages often manage memory automatically to prevent a common class of errors and reduce the load on the programmer - they don't have to remember to free memory.

Two main techniques exist for managing memory:
- **Reference counting**: Simpler to implement, but has limitations.
- **Tracing garbage collection**: Harder to implement due to working with raw memory.