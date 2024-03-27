Mutating algorithms change the order of elements:

- `reverse`: Takes the beginning and end of a range, reverses the order of the elements in the two ranges.
- `reverse_copy`: Like `reverse` but also takes an output iterator, outputs the reversed range without modifying the source range.
- `shuffle`: Takes the beginning of a range, end of a range, and a random number generator. Reorders the elements in the range in a random order.

```cpp
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

// main()
std::vector<int> vector = {1,2,3,4,5,6};

std::random_device randomDevice;
std::mt19937 randomNumberGenerator(randomDevice());
std::shuffle(vector.begin(), vector.end(), randomNumberGenerator);
```