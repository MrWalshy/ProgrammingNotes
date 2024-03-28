A *read-only algorithm* inspects elements stored inside a container but does not modify the order of the elements. Some of the most common are:

- `all_of`, `any_of`, `none_of`: These functions all accept three arguments: the start of a range, the end of a range, and a unary predicate. They return `true` if the predicate returns true for all, at least one, or no element in the sequence respectively.
- `for_each`: Takes the beginning of a range, the end of a range, and a unary predicate. This calls the unary predicate with each element in the sequence, in order of iteration.
- `count`, `count_if`: Takes the beginning of a range, end of a range, and a value or a unary predicate. Returns the number of elements equal to the value, or for which the predicate holds `true`.
- `find`, `find_if`, `find_if_not`: Takes the beginning of a range, end of a range, and a value or unary predicate. Returns the iterator pointing at the position of the first element equal to the value, or the end of the range if the element is not found. In the variant with the predicate, it returns the first element for which the predicate is `true` or the end of the range otherwise.

These algorithms require including the `<algorithm>` header file.

```cpp
std::vector<int> vector = { 1,2,3,4,5 };

auto isLessThan10 = [](int value) { return value < 10; };
bool allLessThen10 = std::all_of(vector.begin(), vector.end(), isLessThan10);

auto isEven = [](int value) { return value % 2 == 0; };
bool atLeastOneIsEven = std::any_of(vector.begin(), vector.end(), isEven);

auto isNegative = [](int value) { return value < 0; };
bool nonIsNegative = std::none_of(vector.begin(), vector.end(), isNegative);

auto isOdd = [](int value) { return value % 2 == 1; };
int numOfOddNums = std::count_if(vector.begin(), vector.end(), isOdd);

auto position = std::find(vector.begin(), vector.end(), 6);
std::cout << (position != vector.end()) << std::endl; // 0/false
```