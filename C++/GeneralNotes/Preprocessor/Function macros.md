Macros can accept arguments to use within their replacement text, similar to the parameters used in a function but without a specified type:

```cpp
#define DEFINE_BINARY_OPERATION(Name, Type, Operator) \
Type Name(Type a, Type b){ \
    return a Operator b; \
} \

DEFINE_BINARY_OPERATION("sum", int, +)

int main()
{
	sum(10, 20);
}
```