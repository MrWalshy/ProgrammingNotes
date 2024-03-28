**Source files** contain the implementation code, they typically have the extension of `.cpp` but other common extensions exist such as `.cc`, `.ccx`, or `.c++`.

**Header files** contain code used to describe available functionalities, the functionalities can be referenced and used by executable source code in the source files. The most common file extensions for header files are `.hpp`, `.hxx`, and `.h`.

## How executables are created from header and source files

The compiler first preprocesses the directives, directives are generally placed at the top of a file and are preceded by a `#` sign. It is preprocessed before the actual compilation of the program code and will have its content replaced with that of the header file indicated by the directive - the `iostream` header describes standard functionality for reading and writing from streams for example.

- Header files may also contain directives to other headers, creating a chain of expansions during preprocessing.

Next, the compiler processes the source files and produces an object file containing the machine code relative to the source file. The compiler then links all the object files into a single executable program.

As header files may include other headers, this can lead to multiple duplicate includes. Transitive include files may also occur, this is when a header file includes another file which is not directly referenced by your source code in an `#include` directive.

C++ has a protective mechanism to employ against duplicate includes known as **include guards**, this is a specific pattern which instructs a preprocessor to ignore the content of the header if it has already been included:

```cpp
#ifndef <name>
#define <name>
// header includes here
#endif
```

This code checks for a preprocessor variable with a given name, if it does not exist then the directives below but before `#endif` will be evaluated. If the variable does exist, the directives will be skipped until the `#endif`. The `#define` directive is used to define the preprocessor variable.

## Defining a starting point

All programs require an entrypoint, in C++ this is through a unique function called `main` and will be the first thing to be executed. The function will be called by the operating system, so it requires a return value to indicate the status; this is referred to as the **exit status code**.

## Compiling a source file into an object file

Compiling an object file into a source file is quite simple:

| MSVC                     | GCC                               |
| ------------------------ | --------------------------------- |
| `cl /EHsc /s myfile.cpp` | `g++ -c -o myfile.obj myfile.cpp` |


It is common to include headers when compiling, the headers defined in the C++ standard can be included without performing any action. For user-defined headers, the compiler needs to be told where to look up the header files:

- **MSVC**: Pass the parameter as the `/I path` flag where `path` is the path to the directory to look in for the header.
- **GCC**: Pass the `-I path` flag where `path` is the directory to look in for the header.

For example, if `myfile.cpp` includes a header from the `include` directory, the file could be compiled to an object file like so:

| MSVC                                | GCC                                          |
| ----------------------------------- | -------------------------------------------- |
| `cl /EHsc /s /I include myfile.cpp` | `g++ -c -I include -o myfile.obj myfile.cpp` |

Several files can be compiled in their respective object files and then linked together to create the final application.

## Linking object files

To link together two object files called `main.obj` and `mylib.obj` into an executable, the following commands can be run:

| MSVC                                    | GCC                              |
| --------------------------------------- | -------------------------------- |
| `link main.obj mylib.obj /out:main.exe` | `g++ main.obj mylib.obj -o main` |

For convenience, MSVC and GCC offer a way to compile several files into an executable without the need to manually create an object file for each file and then link the files together. Although, when using this method any user-defined headers still need to be included using the `/I` or `-I` flags.

For example, to compile `main.cpp` and `mylib.cpp` together which both use some headers from the `include` folder, the commands would look like:

| MSVC                                                  | GCC                                         |
| ----------------------------------------------------- | ------------------------------------------- |
| `cl /EHsc /I include main.cpp mylib.cpp /Fe:main.exe` | `g++ -I include main.cpp mylib.cpp -o main` |
