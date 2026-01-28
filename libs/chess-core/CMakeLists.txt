add_library(chess_core
    src/chess.cpp
)

target_include_directories(chess_core
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(chess_core PUBLIC cxx_std_17)
