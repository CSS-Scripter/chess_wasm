add_executable(chess_backend
  src/main.cpp
  src/server.cpp
  src/game_manager.cpp
)

target_link_libraries(chess_backend
  PRIVATE
    chess_core
)

target_compile_features(chess_backend PRIVATE cxx_std_17)
