#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include <bitset>
#include <cstdint>
#include <array>

typedef std::bitset<64> Bitboard;

enum class Piece {
    WhiteAll, BlackAll,
    WhitePawn, WhiteKnight, WhiteBishop, WhiteRook, WhiteQueen, WhiteKing,
    BlackPawn, BlackKnight, BlackBishop, BlackRook, BlackQueen, BlackKing,
};

const std::array<Piece, 14> AllPieces = {
    Piece::WhiteAll, Piece::BlackAll,
    Piece::WhitePawn, Piece::WhiteKnight, Piece::WhiteBishop, Piece::WhiteRook, Piece::WhiteQueen, Piece::WhiteKing,
    Piece::BlackPawn, Piece::BlackKnight, Piece::BlackBishop, Piece::BlackRook, Piece::BlackQueen, Piece::BlackKing,
};

enum class Square : int {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
};

const std::array<Square, 64> AllSquares = {
    Square::A1, Square::B1, Square::C1, Square::D1, Square::E1, Square::F1, Square::G1, Square::H1,
    Square::A2, Square::B2, Square::C2, Square::D2, Square::E2, Square::F2, Square::G2, Square::H2,
    Square::A3, Square::B3, Square::C3, Square::D3, Square::E3, Square::F3, Square::G3, Square::H3,
    Square::A4, Square::B4, Square::C4, Square::D4, Square::E4, Square::F4, Square::G4, Square::H4,
    Square::A5, Square::B5, Square::C5, Square::D5, Square::E5, Square::F5, Square::G5, Square::H5,
    Square::A6, Square::B6, Square::C6, Square::D6, Square::E6, Square::F6, Square::G6, Square::H6,
    Square::A7, Square::B7, Square::C7, Square::D7, Square::E7, Square::F7, Square::G7, Square::H7,
    Square::A8, Square::B8, Square::C8, Square::D8, Square::E8, Square::F8, Square::G8, Square::H8,
};

enum class File {
    A, B, C, D, E, F, G, H,
};

const std::array<File, 8> AllFiles = {
    File::A, File::B, File::C, File::D, File::E, File::F, File::G, File::H,
};

enum class Rank : int {
    _1, _2, _3, _4, _5, _6, _7, _8
};

const std::array<Rank, 8> AllRanks = {
    Rank::_1, Rank::_2, Rank::_3, Rank::_4, Rank::_5, Rank::_6, Rank::_7, Rank::_8,
};

#endif // _TYPES_HPP_
