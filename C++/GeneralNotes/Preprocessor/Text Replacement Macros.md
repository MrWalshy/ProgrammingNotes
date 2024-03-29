Macros created with the `#define` directive can be used to substitute blocks of code into the project at a desired location:

```cpp
#define PI float pi{3.14f}

int main()
{
	PI
	std::cout << "pi: " << pi << std::endl;
}
```

Preprocessor definitions can also span multiple lines by using the `\` character as a line break:

```cpp
#define DEFINE_SUM_INTS \
int sum(int a, int b){ \
    return a + b; \
} \

DEFINE_SUM_INTS

int main()
{
	std::cout << sum(10, 20) << std::endl;
}
```

