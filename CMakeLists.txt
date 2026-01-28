cmake_minimum_required(VERSION 3.21)
project(chess_monorepo LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libs/chess-core)
add_subdirectory(bindings/wasm)
