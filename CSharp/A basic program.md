C#9 introduced top-level statements, which allows programs to be created without an explicit main method:

```c#
int x = 10 * 10;
System.Console.WriteLine(x);
```

Each C# statement is terminated by a semicolon. In the above example, `System` is a namespace, `Console` is a class, and `WriteLine` is a method on the class for printing to a console.

Many common types reside in the `System` namespace, the `System.Text` namespace has types for handling text and `System.IO` for input/output for example.

Manually qualifying the `Console` class with the `System` namespace can add clutter, so the `using` directive allows importing a namespace:

```c#
using System;

int x = 10 * 10;
Console.WriteLine(x);
```

## Compilation
The C# compiler compiles source code (`.cs` files) into an **assembly**, an assembly being the unit of packaging and deployment in .NET. An assembly is either an *application* or a *library*.

When creating a program, its entry point is indicated by the presence of top-level statements or a main method.

The `dotnet` tool (`dotnet.exe` on Windows) can be used to manage .NET source code and binaries from the command line, it can both build and run a program as an alternative to an IDE like Visual Studio. Downloading the .NET SDK will install the `dotnet` tool to `%ProgramFiles%\dotnet` on Windows and `/usr/bin/dotnet` on Ubuntu.

Compiling requires a *project file* and one or more C# files. To scaffold a new console project, use the command:

```sh
dotnet new Console -n MyFirstProgram
```

