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

enum class Square : int {
    SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1,
    SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2,
    SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3,
    SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4,
    SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5,
    SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6,
    SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7,
    SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8,
};

const std::array<Square,64> AllSquares = {
    Square::SQ_A1, Square::SQ_B1, Square::SQ_C1, Square::SQ_D1, Square::SQ_E1, Square::SQ_F1, Square::SQ_G1, Square::SQ_H1,
    Square::SQ_A2, Square::SQ_B2, Square::SQ_C2, Square::SQ_D2, Square::SQ_E2, Square::SQ_F2, Square::SQ_G2, Square::SQ_H2,
    Square::SQ_A3, Square::SQ_B3, Square::SQ_C3, Square::SQ_D3, Square::SQ_E3, Square::SQ_F3, Square::SQ_G3, Square::SQ_H3,
    Square::SQ_A4, Square::SQ_B4, Square::SQ_C4, Square::SQ_D4, Square::SQ_E4, Square::SQ_F4, Square::SQ_G4, Square::SQ_H4,
    Square::SQ_A5, Square::SQ_B5, Square::SQ_C5, Square::SQ_D5, Square::SQ_E5, Square::SQ_F5, Square::SQ_G5, Square::SQ_H5,
    Square::SQ_A6, Square::SQ_B6, Square::SQ_C6, Square::SQ_D6, Square::SQ_E6, Square::SQ_F6, Square::SQ_G6, Square::SQ_H6,
    Square::SQ_A7, Square::SQ_B7, Square::SQ_C7, Square::SQ_D7, Square::SQ_E7, Square::SQ_F7, Square::SQ_G7, Square::SQ_H7,
    Square::SQ_A8, Square::SQ_B8, Square::SQ_C8, Square::SQ_D8, Square::SQ_E8, Square::SQ_F8, Square::SQ_G8, Square::SQ_H8,
};

enum class File {
    FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H,
};

const std::array<File, 8> AllFiles = {
    File::FILE_A, File::FILE_B, File::FILE_C, File::FILE_D, File::FILE_E, File::FILE_F, File::FILE_G, File::FILE_H,
};

enum class Rank : int {
    RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8
};

const std::array<Rank, 8> AllRanks = {
    Rank::RANK_1, Rank::RANK_2, Rank::RANK_3, Rank::RANK_4, Rank::RANK_5, Rank::RANK_6, Rank::RANK_7, Rank::RANK_8,
};

enum Direction : int {
    NORTH =  8,
    EAST  =  1,
    SOUTH = -NORTH,
    WEST  = -EAST,

    NORTH_EAST = NORTH + EAST,
    SOUTH_EAST = SOUTH + EAST,
    SOUTH_WEST = SOUTH + WEST,
    NORTH_WEST = NORTH + WEST
};

#endif // _TYPES_HPP_
