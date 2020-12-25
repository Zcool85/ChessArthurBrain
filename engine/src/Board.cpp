#include "Board.hpp"
#include "BitboardHelper.hpp"

#include <cstddef>

Board::Board()
    : _dark_squares(0xAA55AA55AA55AA55ULL) {
    for (auto&& bb : _pieces_bb)
        bb.second = 0ULL;
}

void Board::updateWhiteAllBitdoard() noexcept {
    _pieces_bb[Piece::WhiteAll] |= _pieces_bb[Piece::WhitePawn]   |
                                   _pieces_bb[Piece::WhiteRook]   |
                                   _pieces_bb[Piece::WhiteKnight] |
                                   _pieces_bb[Piece::WhiteBishop] |
                                   _pieces_bb[Piece::WhiteQueen]  |
                                   _pieces_bb[Piece::WhiteKing]   ;
}

void Board::updateBlackAllBitdoard() noexcept {
    _pieces_bb[Piece::BlackAll] |= _pieces_bb[Piece::BlackPawn]   |
                                   _pieces_bb[Piece::BlackRook]   |
                                   _pieces_bb[Piece::BlackKnight] |
                                   _pieces_bb[Piece::BlackBishop] |
                                   _pieces_bb[Piece::BlackQueen]  |
                                   _pieces_bb[Piece::BlackKing]   ;
}

void Board::init() noexcept {
    for (const auto& file : AllFiles)
        setbit(_pieces_bb[Piece::WhitePawn], make_square(file, Rank::RANK_2));
    setbit(_pieces_bb[Piece::WhiteRook],   Square::SQ_A1);
    setbit(_pieces_bb[Piece::WhiteKnight], Square::SQ_B1);
    setbit(_pieces_bb[Piece::WhiteBishop], Square::SQ_C1);
    setbit(_pieces_bb[Piece::WhiteQueen],  Square::SQ_D1);
    setbit(_pieces_bb[Piece::WhiteKing],   Square::SQ_E1);
    setbit(_pieces_bb[Piece::WhiteBishop], Square::SQ_F1);
    setbit(_pieces_bb[Piece::WhiteKnight], Square::SQ_G1);
    setbit(_pieces_bb[Piece::WhiteRook],   Square::SQ_H1);

    updateWhiteAllBitdoard();

    for (const auto& file : AllFiles)
        setbit(_pieces_bb[Piece::BlackPawn], make_square(file, Rank::RANK_7));
    setbit(_pieces_bb[Piece::BlackRook],   Square::SQ_A8);
    setbit(_pieces_bb[Piece::BlackKnight], Square::SQ_B8);
    setbit(_pieces_bb[Piece::BlackBishop], Square::SQ_C8);
    setbit(_pieces_bb[Piece::BlackQueen],  Square::SQ_D8);
    setbit(_pieces_bb[Piece::BlackKing],   Square::SQ_E8);
    setbit(_pieces_bb[Piece::BlackBishop], Square::SQ_F8);
    setbit(_pieces_bb[Piece::BlackKnight], Square::SQ_G8);
    setbit(_pieces_bb[Piece::BlackRook],   Square::SQ_H8);

    updateBlackAllBitdoard();
}

// EOF
