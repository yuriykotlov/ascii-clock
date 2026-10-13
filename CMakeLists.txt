cmake_minimum_required(VERSION 3.30)
project(AsciiClock VERSION 1.0 LANGUAGES CXX)

# Enforce C++20 across all platforms and compilers
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Look for all your .cpp source files
file(GLOB SOURCES "src/*.cpp")

# 2. Tell CMake to build your executable
add_executable(ascii-clock ${SOURCES})

# 3. Tell CMake where your header files are (the 'incl' folder)
# 'PUBLIC' ensures the compiler adds this to the include paths list
target_include_directories(ascii-clock PUBLIC incl)

# 4. Hide temporary build objects (Keeps the root clean)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)