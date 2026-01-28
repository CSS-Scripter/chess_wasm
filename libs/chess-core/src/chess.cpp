#include "chess.h"

#include <string>
#include <vector>
#include <sstream>

std::string rook_moves(const std::string& square) {
    char file = square[0];
    char rank = square[1];

    std::vector<std::string> moves;

    for (char f = 'a'; f <= 'h'; f++) {
        if (f != file) {
            moves.push_back(std::string() + f + rank);
        }
    }

    for (char r = '1'; r <= '8'; r++) {
        if (r != rank) {
            moves.push_back(std::string() + file + r);
        }
    }

    std::ostringstream out;
    for (size_t i = 0; i < moves.size(); i++) {
        out << moves[i];
        if (i + 1 < moves.size()) out << ",";
    }

    return out.str();
}

