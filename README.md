# Snake (C++ / raylib)

A compact graphical Snake starter built with C++17 and raylib.

## Requirements
- C++17 compiler
- CMake 3.16+
- raylib installed and discoverable by CMake

## Build

```bash
cmake -S . -B build
cmake --build build
```

Run the generated `cpp-snake` executable from the build directory.

## Controls
- Arrow keys or WASD: move
- R: restart after game over
- Escape: quit

## Concepts
Game loop, delta time, grid movement, input, collision detection, and basic state management.
