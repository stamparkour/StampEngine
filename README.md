# Stamp Engine

Toolset of several libraries that, when combined be used as a complete game engine, and can be used individually.

# Build Test App

Make sure you have
- Cmake

run 
``` sh
cmake -B build -DSTAMP_BUILD_APP=YES 
cmake --build build
```

# Build Documentation

Make sure you have
- CMake
- [doxygen](https://www.doxygen.nl/manual/install.html)
- Graphviz (optional)

run 
``` sh
cmake -B build -DSTAMP_BUILD_DOXYGEN=YES 
cmake --build build
```