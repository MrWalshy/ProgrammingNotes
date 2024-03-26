An **associative container** allows for the fast lookup of elements while always keeping them in a sorted order. The order is determined by the elements value and a comparison function called a *comparator*. By default, the comparator is `operator<`. The user can supply a **Functor** (function object) parameter to specify how the elements should be sorted if wanted; the `<functional>` header file contains many functors that can be used to sort associative containers, like `std::less` and or `std::greater`.

Typically, associative containers are implemented as variations of binary trees, providing fast element lookup by exploiting the logarithmic complexity of the underlying structure.

Associative containers include:

- **Set**: Elements are all distinct/unique, sorted according to their values.
- **Multiset**: Same as a set, duplicates are allowed though.
- **Map**: Container in which elements are mapped as key-value pairs, sorted by key values; each key is distinct.
- **Multimap**: Same as a map, keys can be duplicated though.