# C++ Ascii Clock

> A small program that I made to display the current time in a HH:MM:SS (24 hour) format.

## Prerequisites to build

> **C++20** or higher, **CMake** v3.20 or higher, and a **compiler**, being either GCC, Clang, or MSVC.

## Building

> Clone the project

SSH: `git clone git@github.com:yuriykotlov/ascii-clock.git`

HTTPS: `git clone https://github.com/yuriykotlov/ascii-clock.git`

> Build the project. Replace 'COMPILER' with clang, gcc, or mscv.

```bash
cd ascii-clock

mkdir build
cd build

cmake ..
cmake --build .
```

If you're on Windows and ``cmake ..`` doesn't work, try ``cmake .. -G "MinGW Makefiles"``


> Run the compiled program

```bash
./build/ascii-clock
```