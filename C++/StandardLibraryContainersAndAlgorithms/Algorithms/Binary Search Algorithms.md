- `binary_search`: Takes the beginning of a range, end of a range, a value, and optionally a binary predicate. Looks for the value in the range and states whether it was found. The provided range must be sorted according to the binary predicate. If no predicate is provided, the range must be sorted according to `operator<`.

```cpp
#include <vector>
#include <algorithm>

// main()
std::vector<int> vector = {1,2,3,4,5,6};

bool found = std::binary_search(vector.begin(), vector.end(), 2);
```