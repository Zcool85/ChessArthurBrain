#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include <cstdint>

typedef uint64_t Bitboard;

enum Color : int {
    WHITE, BLACK,
    COLOR_NB = 2
};

enum PieceType : int {
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
    PIECE_TYPE_NB = 6
};

enum Piece : int {
    W_PAWN = PAWN,                 W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
    B_PAWN = PAWN + PIECE_TYPE_NB, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING,
    PIECE_NB = 12
};

inline Piece& operator++(Piece& piece, int) {
	piece = static_cast<Piece>(static_cast<int>(piece) + 1);
	return piece;
}

enum Square : uint64_t {
    SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1,
    SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2,
    SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3,
    SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4,
    SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5,
    SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6,
    SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7,
    SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8,
    SQUARE_NB   = 64
};

inline Square& operator++(Square& square, int) {
	square = static_cast<Square>(static_cast<int>(square) + 1);
	return square;
}

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

enum File : int {
    FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NB
};

inline File& operator++(File& file, int) {
	file = static_cast<File>(static_cast<int>(file) + 1);
	return file;
}

enum Rank : int {
    RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NB
};

inline Rank& operator++(Rank& rank, int) {
	rank = static_cast<Rank>(static_cast<int>(rank) + 1);
	return rank;
}

constexpr Square make_square(File file, Rank rank) {
    return Square((rank << 3) + file);
}

#endif // _TYPES_HPP_
