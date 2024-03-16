- Type names use PascalCase: `MyClass`
- Functions and variables use camelCase: `myMethod`
- Constants are all upper case: `const double PI = 3.14;`

C++ Standard Library uses these guidelines:
- Macro names use SCREAMING_SNAKE_CASE: `INT_MAX`
- Template parameter names use camel case
- All other names use snake case: `unordered_map`

In classes, it is common for the data members (fields) and parameters of a function to use snake case. Typically, a `m_` prefix to indicate a member is used on the field names and a `t_` prefix on parameters to indicate *the*:

```cpp
class SomeClass
{
	int m_data;

	void foo(int t_data);
}
```

Alternatively, snake case can be used depending on the conventions followed.