A `function` **declaration** tells the compiler the name, parameters, and return type of a function. Once the function is declared, it can be used in the rest of the program.

- The name of the function and its list of parameters are known as the **signature** of the function.

The **definition** of a function specifies what operations a function performs.

## Declaring a function

A function declarations syntax is as follows:

```cpp
return_type function_name(parameter_list);
```

If a function returns nothing, the return type can be specified as `void`. If a function expects no parameters, the parameter list can be left empty:

```cpp
void doNothing();
```

To invoke a function, write the name of the function followed by a pair of parenthesis containing any arguments if required:

```cpp
doNothing();
```

It is not enough to simply declare a function though, it must be provided with a definition. For example, the following program would compile but the linking process would fail due to a lack of definition:

```cpp
void doNothing();

int main()
{
	doNothing();
	
	return EXIT_SUCCESS;
}
```

## Defining a function

To define a function, the same information as in the declaration must be specified alongside a function body. The body of a function delimits a new scope composed of a sequence of statements within curly braces:

```cpp
return_type function_name(parameter_list)
{
	statement1;
	statement2;
	statementN;
}
```

A function can be declared in one place and defined elsewhere or declared and defined at the same time.

When a function is executed, the flow of control is passed to the function. Once it finishes executing, the control flow is passed back to its caller.

The **One Definition Rule (ODR)** specifies that multiple declarations of the same function may exist but only one definition can exist. The solution to the issue where the same function may have several definitions in different files is to:

1. Ensure all definitions are identical.
2. Or place the declaration in a **header** file and the definition in an **implementation** file.

A header file can be included in many different implementation (source) files, the code in these files can call the function. Implementation files are compiled only once, so it can be guaranteed that the definition is seen only once by the compiler. The linker then puts all of the outputs of the compiler together, finds a functions definition, and produces a valid executable.