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
