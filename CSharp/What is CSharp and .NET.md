C# and .NET are a programming language and platform developed by Microsoft in 2002. The .NET platform allows for various programming languages to run on it, including C#, F#, and VB.NET; the languages can even interact with each other.

- Microsoft launched .NET Core in 2016, which allowed .NET languages to interoperate with each other and introduced cross platform development for iOS, Linux, MacOS, and Windows
- The .NET 5 release removed the "Core" part of the name
- C#10 and .NET 6 released on November 8, 2021. C#10 only runs on .NET 6 and above

The .NET platform provides multiple useful development frameworks:

- ADO.NET and Entity Framework (EF) Core for database access
- Windows Presentation Foundation (WPF) for user interfaces
- RESTful services and web apps with ASP.NET Core

## The building blocks of .NET
The .NET platform is made up of various components, including the .NET runtime, Common Type System (CTS), Common Language System (CLS), etc...

- .NET is essentially a runtime environment with large base class library for developers to build upon. The runtime layer contains minimal implementations for each platform (Windows, iOS, Linux) and architectures (x86, x64, ARM) alongside the base types for .NET.
- The Common Type System (CTS) spec describes all possible data types and programming constructs supported by the runtime, specifies how they can interact with each other, and how they are represented in the .NET metadata format.
- Not every .NET language supports all features defined in the CTS.
- The Common Language Specification (CLS) defines a subset of common types and constructs available in all .NET programming languages.

### Base Class Libraries
.NET provides a set of base class libraries (BCLs) available to all .NET programming languages.

### .NET Standard
The BCLs available in the .NET framework exceed those in .NET. To handle the issues when using .NET framework code with .NET code, the .NET standard was introduced. A specification defining the availability of .NET APIs and BCLs that must be available in each implementation:

- Defines a uniform set of BCL APIs all .NET implementations implement.
- Enables devs to produce portable libraries usable across .NET implementations.
- Reduces or eliminates conditional compilation of shared source due to .NET APIs.

### Managed vs Unmanaged code
C# programs can only be hosted using the .NET runtime, they cannot be natively compiled. This is known as *managed code*, the binary unit containing the managed code is called an *assembly*.
