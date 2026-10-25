# Stamp Engine

## Goal

Toolset of several libraries that, when combined be used as a complete game engine, and can be used individually.

## At Present

Implemented:
- reflection library
- task library

# Build Test App

Make sure you have installed:
- Cmake >3.24

run 
``` sh
cmake -B build -DSTAMP_BUILD_APP=YES 
cmake --build build <name>
```

where `<name>` is:
- `my_app` - app for debugging code
- `task_benchmark` - benchmarks for task library
- `stamp_test` - unit tests



# Build Documentation

Make sure you have installed:
- CMake >3.24
- [doxygen](https://www.doxygen.nl/manual/install.html)
- Graphviz (optional)

run 
``` sh
cmake -B build -DSTAMP_BUILD_DOXYGEN=YES 
cmake --build build stamp_docs
```