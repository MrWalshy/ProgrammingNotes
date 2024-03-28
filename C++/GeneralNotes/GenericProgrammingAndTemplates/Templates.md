A **template** is a way to define functions or classes that can work across many different types, this is done through special parameters known as **type parameters**. 

The type parameter is used in-place of a real type such as `int` or `string` when writing the template code. When a templated function is invoked or template class instantiated, the type parameter is *substituted* with a real type used by the calling code.

Templates are denoted by the `template` keyword followed by a list of template parameters enclosed in angle brackets. The template parameter list is comma-separated:

```cpp
template<typename T>
T max(T a, T b)
{
	if (a > b) return a;
	else return b;
}
```

- The `typename` keyword indicates that the template is for a templated function using a generic type, named `T` in this case.
- The `class` keyword can be used in place of `typename`, there is no difference between them.

The templated function can then be invoked by specifying the function name, followed by the type parameters in angle brackets, and then the regular parameter list for the function following:

```cpp
max<int>(10, 20);
```

> The type parameters don't always need to be explicitly specified, the compiler can often infer them.

## Compiling template code

Like functions and classes, templates need to be declared before their usage. When compiling, the compiler will parse and perform partial checks on the template definition on its first encounter; this is because the compiler doesn't know what types will be used with a template when it is parsed, this prevents the compiler performing checks involving the parameter types or anything that depends on them. This means some errors will only be given when the template is instantiated.

When a defined template is instantiated in code, the compiler uses the template definition to generate a new instance of the code with the generic types replaced with the types used.

Templates can be forward declared, but the compiler must see the definition. When writing templates that should be accessed by several files, the definition and the declaration of the templates must be in the **header** file to allow other translation units (`.cpp`) to see and use them when included.

> This restriction does not apply if the template is used only in one file.