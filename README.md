# C++ Ascii Clock

> A small program that I made to display the current time in a HH:MM:SS (24 hour) format.

## Prerequisites to build

> **C++20** or higher, **CMake** v3.30 or higher, and a **compiler**, being either GCC, Clang, or MSVC.

## Building

> Clone the project

SSH: `git clone git@github.com:yuriykotlov/ascii-clock.git`

HTTPS: `git clone https://github.com/yuriykotlov/ascii-clock.git`

> Build the project. Replace 'COMPILER' with clang, gcc, gcc-linux, or mscv.

```
cd ascii-clock

cmake --preset COMPILER
cmake --build build
```

> Run the compiled program

#### Windows
```
start ./build/ascii-clock
```

#### Linux or MacOS
```
./build/ascii-clock
```