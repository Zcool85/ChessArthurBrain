#include "Board.hpp"

#include <cstddef>

Board::Board()
    : _dark_squares(0xAA55AA55AA55AA55ULL) {
    for (auto&& bb : _pieces_bb)
        bb.second = 0ULL;
}

void Board::init() {
    for (auto file = FILE_A; file < FILE_NB; file++)
        _pieces_bb[Piece::WhitePawn] |= 1ULL << make_square(file, RANK_2);
    _pieces_bb[Piece::WhiteRook]   |= 1ULL << SQ_A1;
    _pieces_bb[Piece::WhiteKnight] |= 1ULL << SQ_B1;
    _pieces_bb[Piece::WhiteBishop] |= 1ULL << SQ_C1;
    _pieces_bb[Piece::WhiteQueen]  |= 1ULL << SQ_D1;
    _pieces_bb[Piece::WhiteKing]   |= 1ULL << SQ_E1;
    _pieces_bb[Piece::WhiteBishop] |= 1ULL << SQ_F1;
    _pieces_bb[Piece::WhiteKnight] |= 1ULL << SQ_G1;
    _pieces_bb[Piece::WhiteRook]   |= 1ULL << SQ_H1;

    _pieces_bb[Piece::WhiteAll] |= _pieces_bb[Piece::WhitePawn] |
                                   _pieces_bb[Piece::WhiteRook] |
                                   _pieces_bb[Piece::WhiteKnight] |
                                   _pieces_bb[Piece::WhiteBishop] |
                                   _pieces_bb[Piece::WhiteQueen] |
                                   _pieces_bb[Piece::WhiteKing];

    for (auto file = FILE_A; file < FILE_NB; file++)
        _pieces_bb[Piece::BlackPawn] |= 1ULL << make_square(file, RANK_7);
    _pieces_bb[Piece::BlackRook]   |= 1ULL << SQ_A8;
    _pieces_bb[Piece::BlackKnight] |= 1ULL << SQ_B8;
    _pieces_bb[Piece::BlackBishop] |= 1ULL << SQ_C8;
    _pieces_bb[Piece::BlackQueen]  |= 1ULL << SQ_D8;
    _pieces_bb[Piece::BlackKing]   |= 1ULL << SQ_E8;
    _pieces_bb[Piece::BlackBishop] |= 1ULL << SQ_F8;
    _pieces_bb[Piece::BlackKnight] |= 1ULL << SQ_G8;
    _pieces_bb[Piece::BlackRook]   |= 1ULL << SQ_H8;

    _pieces_bb[Piece::BlackAll] |= _pieces_bb[Piece::BlackPawn] |
                                   _pieces_bb[Piece::BlackRook] |
                                   _pieces_bb[Piece::BlackKnight] |
                                   _pieces_bb[Piece::BlackBishop] |
                                   _pieces_bb[Piece::BlackQueen] |
                                   _pieces_bb[Piece::BlackKing];
}


// EOF
