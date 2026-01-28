// bindings/wasm/bindings.cpp
#include <emscripten/bind.h>
#include "chess.h"

EMSCRIPTEN_BINDINGS(chess) {
    emscripten::function("rook_moves", &rook_moves);
}
