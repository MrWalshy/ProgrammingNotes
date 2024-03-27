These modify the collections they iterate over.

- `copy`: Takes the beginning of a range, end of a range, and an output iterator. Copies the elements in the range into the output iterator.
- `copy_if`: Like `copy` but also takes an unary predicate and only copies the elements which hold true against the predicate.
- `transform`: Two commonly used overloads.
	- One takes the beginning of a range, end of a range, an output iterator, and a unary predicate. The unary predicate is applied to each element in the range and outputs it into the output iterator.
	- The second takes the beginning of a range, end of a range, the beginning of a second range (needs to at least be as long as the first range), an output iterator, and a binary predicate. The binary predicate is applied, passing the elements at the same position in the two ranges, and outputs the returned value into the output iterator.
- `remove`, `remove_if`: Takes the beginning of a range, end of a range, and a value or unary predicate. The elements are not actually removed from the container, elements equal to the value or which the predicate is true are moved to the end of the container. An iterator after the last element that should not be removed is returned.

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

// main()
std::vector<std::string> vector = {"Hello", "World", "C++", "Learning"};
std::vector<std::string> longWords;
// copy words longer than 3 letters into longWords
auto lengthG3 = [](const std::string& s) { return s.length() > 3; };
std::copy_if(vector.begin(), vector.end(), std::back_inserter(longWords), lengthG3);

// transforming (this seems like a map operation)
std::vector<int> lengths;
auto stringLength = [](const std::string& s) { return s.length(); };
std::transform(longWords.begin(), longWords.end(), std::back_inserter(lengths), stringLength);

// removing elements
auto isLessThan7 = [](int length) { return length < 7; };
auto newLast = std::remove_if(lengths.begin(), lengths.end(), isLessThan7);
lengths.erase(newLast, lengths.end()); // erase the elements between two iterators
```
