#include "Board.hpp"

#include <cstddef>

Board::Board()
    : _dark_squares(0xAA55AA55AA55AA55ULL) {
    for (auto piece = W_PAWN; piece < PIECE_NB; piece++)
        _pieces_bb[piece] = 0ULL;
}

void Board::_init_white() {
    for (auto file = FILE_A; file < FILE_NB; file++)
        _pieces_bb[W_PAWN] |= 1ULL << make_square(file, RANK_2);
    _pieces_bb[W_ROOK]   |= 1ULL << SQ_A1;
    _pieces_bb[W_KNIGHT] |= 1ULL << SQ_B1;
    _pieces_bb[W_BISHOP] |= 1ULL << SQ_C1;
    _pieces_bb[W_QUEEN]  |= 1ULL << SQ_D1;
    _pieces_bb[W_KING]   |= 1ULL << SQ_E1;
    _pieces_bb[W_BISHOP] |= 1ULL << SQ_F1;
    _pieces_bb[W_KNIGHT] |= 1ULL << SQ_G1;
    _pieces_bb[W_ROOK]   |= 1ULL << SQ_H1;
}

void Board::_init_black() {
    for (auto file = FILE_A; file < FILE_NB; file++)
        _pieces_bb[B_PAWN] |= 1ULL << make_square(file, RANK_7);
    _pieces_bb[B_ROOK]   |= 1ULL << SQ_A8;
    _pieces_bb[B_KNIGHT] |= 1ULL << SQ_B8;
    _pieces_bb[B_BISHOP] |= 1ULL << SQ_C8;
    _pieces_bb[B_QUEEN]  |= 1ULL << SQ_D8;
    _pieces_bb[B_KING]   |= 1ULL << SQ_E8;
    _pieces_bb[B_BISHOP] |= 1ULL << SQ_F8;
    _pieces_bb[B_KNIGHT] |= 1ULL << SQ_G8;
    _pieces_bb[B_ROOK]   |= 1ULL << SQ_H8;
}

void Board::init() {
    _init_white();
    _init_black();
}


// EOF
