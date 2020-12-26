#include "Board.hpp"
#include "BitboardHelper.hpp"

#include <cstddef>

Board::Board()
    : _dark_squares(0xAA55AA55AA55AA55ULL),
      _queen_side  (0x0F0F0F0F0F0F0F0FULL),
      _king_side   (0xF0F0F0F0F0F0F0F0ULL),
      _center_files(0x3C3C3C3C3C3C3C3CULL),
      _center      (0x0000001818000000ULL),
      _flanks      (0x8181818181818181ULL) {
    // First add bitboards
    for (const auto& piece : AllPieces)
        _pieces_bb[piece].reset();

    reset();
}

void Board::reset() noexcept {
    for (auto&& bb : _pieces_bb)
        bb.second.reset();
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
        setbit(_pieces_bb[Piece::WhitePawn], make_square(file, Rank::_2));
    setbit(_pieces_bb[Piece::WhiteRook],   Square::A1);
    setbit(_pieces_bb[Piece::WhiteKnight], Square::B1);
    setbit(_pieces_bb[Piece::WhiteBishop], Square::C1);
    setbit(_pieces_bb[Piece::WhiteQueen],  Square::D1);
    setbit(_pieces_bb[Piece::WhiteKing],   Square::E1);
    setbit(_pieces_bb[Piece::WhiteBishop], Square::F1);
    setbit(_pieces_bb[Piece::WhiteKnight], Square::G1);
    setbit(_pieces_bb[Piece::WhiteRook],   Square::H1);

    updateWhiteAllBitdoard();

    for (const auto& file : AllFiles)
        setbit(_pieces_bb[Piece::BlackPawn], make_square(file, Rank::_7));
    setbit(_pieces_bb[Piece::BlackRook],   Square::A8);
    setbit(_pieces_bb[Piece::BlackKnight], Square::B8);
    setbit(_pieces_bb[Piece::BlackBishop], Square::C8);
    setbit(_pieces_bb[Piece::BlackQueen],  Square::D8);
    setbit(_pieces_bb[Piece::BlackKing],   Square::E8);
    setbit(_pieces_bb[Piece::BlackBishop], Square::F8);
    setbit(_pieces_bb[Piece::BlackKnight], Square::G8);
    setbit(_pieces_bb[Piece::BlackRook],   Square::H8);

    updateBlackAllBitdoard();
}

// EOF
