The syntax for a class template is equivalent to that for functions:

```cpp
template<typename T>
class MyArray
{
	
};
```

Like a function, instantiating a class template uses angle brackets containing a list of types:

```cpp
MyArray<int> array;
```

Like a function template, the class template code is generated when the template is instantiated and the same restrictions apply; the template definition must be available to the compiler and some of the error checking is executed when the template is instantiated.

When defining a constructor function for a template class, the type parameter is not specified as the name of the class will implicitly refer to the specific template instance being created:

```cpp
template<typename T>
class MyArray
{
	MyArray() {} // legal

	MyArray<T>() {} // illegal
};
```

Template classes can make use of the type parameters when declaring and defining fields and methods:

```cpp
template<typename T>
class MyArray
{
	T[] internal_array;

	void pushBack(const T& element);
};
```

Classes can also have templated methods, these are similar to template functions but they have access to the classes instance data:

```cpp
template<typename T>
class MyArray
{
	template<typename Comparator>
	void sort(const Comparator& element);
}
```

The syntax for calling such a method would look like:

```cpp
MyArray<int> array;
MyComparator comparator;
array.sort<MyComparator>(comparator);
```

In this situation, the compiler can sometimes deduce the parameters type where the user does not have to specify it.

If a method is only declared in the class, the user can later implement it by specifying the template types of both the class and the method:

```cpp
template<typename T> // template of the class
template<typename Comparator> // template of the method
MyArray<T>::sort(const Comparator& element)
{
	// implementation
}
```

The type names do not need to match, but it is good practice to do so.

Similar to methods, template overloaded operators can be created in a class. These are identical to writing operator overloads for regular classes, the only difference is that the template declaration must precede the overload declaration like for method templates.

## How static methods and fields interact with a class template
When a template class declares a static member, the members is only shared with instantiations of the template with the same template parameters:

```cpp
template<typename T>
class MyArray
{
	const static int elementSize = sizeof(T);
};

MyArray<int> intArray1;
MyArray<int> intArray2;
MyArray<std::string> stringArray;
```

`intArray1` and `intArray2` will share the same static variable, `elementSize`, as they are both of the same type (`MyArray<int>`). The `stringArray` instance will refer to a different value of `elementSize` as it is a different class (`MyArray<std::string>)`, meaning it doesn't share the static field with the `MyArray<int>` instance even though they are generated from the same class template.