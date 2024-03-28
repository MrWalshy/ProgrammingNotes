Rearranges the order of elements within a container.

- `sort`: Takes the beginning of a range, the end of the range, and optionally a binary predicate. Changes the order of the range to keep the elements in sorted, ascending order. When a binary predicate is supplied, the elements are compared using it; the first argument is moved before the second if the predicate returns `true`. If no predicate is supplied, `operator<` is used.

```cpp
#include <vector>
#include <algorithm>

// main()
std::vector<int> vector = {5,2,4,3,8,1};

std::sort(vector.begin(), vector.end()); // 1 2 3 4 5 8
```