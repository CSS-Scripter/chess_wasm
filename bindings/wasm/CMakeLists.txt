if (NOT EMSCRIPTEN)
  return()
endif()

add_executable(chess_wasm
  bindings.cpp
)

target_link_libraries(chess_wasm
  PRIVATE
    chess_core
)

set_target_properties(chess_wasm PROPERTIES
  OUTPUT_NAME "libchess"
)

target_link_options(chess_wasm PRIVATE
  "-sWASM=1"
  "-sMODULARIZE=1"
  "-sEXPORT_NAME=createChessModule"
  "-sENVIRONMENT=web"
  "--bind"
  "-sEXPORT_ES6=1"
)
