Just like in C++, conditional logic exists for use in the preprocessor but at a simpler level. It is used for conditionally including certain chunks of code into the translation units sent to the preprocessor.

## ifdef
The `#ifdef` directive will check if a specified **preprocessor definition** exists, including some chunk of code between it and an `#endif` directive if the definition exists:

```cpp
int main()
{
	std::cout << "Regular code" << std::endl;
#ifdef DEV_BUILD
	std::cout << "Developer build active" << std::endl;
#endif
}
```

## ifndef
The `#ifndef` directive represents the opposite of `#ifdef`, it includes some code if the specified definition does not exist. It is commonly used with header guards:

```cpp
#ifndef FILE_H
#define FILE_H
class Foo
{

};
#endif
```

## elif and else
`#elif` and `#else` directives also exist for chaining these conditional checks for a definition:

```cpp
int main()
{
	std::cout << "Regular code" << std::endl;
#ifdef DEV_BUILD
	std::cout << "Developer build active" << std::endl;
#elif DEMO_BUILD
	std::cout << "Demo build active" << std::endl;
#else
	std::cout << "Public build active" << std::endl;
#endif
}
```
