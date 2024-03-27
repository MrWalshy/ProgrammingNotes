Combines numeric elements using a linear operation.

- `accumulate`: Takes the beginning of a range, end of a range, an initial value, and optionally a binary predicate. Combines all elements in the range with the initial value using the binary predicate. If no binary predicate is provided, `operator+` is used.

```cpp
#include <vector>
#include <algorithm>

// main()
std::vector<int> costs = {1,2,3};

int budget = 10;
auto subtract = [](int a, int b) { return a - b; };
int margin = std::accumulate(costs.begin(), costs.end(), budget, subtract); // 4
```

