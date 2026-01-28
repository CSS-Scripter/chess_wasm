# Chess WASM

A "simple" chess website to try out compiling C++ into WebAssembly, and running it from a frontend framework (Vue). Later on I will add a backend to add another layer to the C++ codebase: exporting to a library file, which will be used by the backend to validate and execute moves.

Initial Setup

```
C++ Chess Codebase
|
| - [ EmScripten ] -> .wasm file -> Vue Frontend
| 
- - [ CMake ] -> .so/.dll/.dylib -> ??? Backend
```
