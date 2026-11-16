# Snake — C++ / raylib

A small graphical Snake game built with **C++17** and [raylib](https://www.raylib.com/).

## Features
- Grid-based movement
- Keyboard controls (arrow keys or WASD)
- Food, score, and collision detection
- Game-over screen and restart

## Build
Requires a C++17 compiler, CMake 3.16+, Git, and a working CMake toolchain. CMake downloads raylib automatically on the first configure.

```bash
cmake -S . -B build
cmake --build build
```

Run the generated `cpp-snake` executable from the build directory.

## Controls
- Arrow keys or WASD: move
- R: restart after game over
- Escape: quit

## Related projects
- [Tic-Tac-Toe AI](https://github.com/hanisnaff/cpp-tictactoe-ai)
- [Tiny Dungeon](https://github.com/hanisnaff/cpp-dungeon)
- [Portfolio](https://github.com/hanisnaff/hanisnaff)

## License
MIT
