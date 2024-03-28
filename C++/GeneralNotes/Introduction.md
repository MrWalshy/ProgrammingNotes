Notes here are currently based on C++ Fundamentals Packt book, any near verbatim notes I need to reword for better understanding.
## Installing a C++ Compiler on Windows
Two main choices exist, the MSVC toolset or the MinGW toolset. MinGW will be explained here, it provides up to date native builds of GCC and other useful C++ libraries.

1. Install MinGW-w64 via MSYS2
2. Install the MinGW-w64 toolset using the MSYS2 terminal: `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain`
3. Accept the default number of packages and enter `Y` when prompted to install
4. Add the MinGW-w64 `bin` folder to the Windows `PATH` variable. Path to add is typically: `C:\msys64\ucrt64\bin`

Once the install process is complete, open a new terminal and check that GCC, g++, and GDB are correctly installed:

```sh
gcc --version
g++ --version
gdb --version
```

Building and running a program in VS Code is simple, ensure the C++ plugins are installed to make development easier. To build and run, select the Play icon at the top right of a source file. The first launch will prompt for a compiler, select the G++ Build and Debug option. This will then build the program into an exe file and run the built executable, displaying its output in the terminal.