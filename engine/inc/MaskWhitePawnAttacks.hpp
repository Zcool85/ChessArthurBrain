#ifndef _MASK_WHITE_PAWN_ATTACKS_HPP_
#define _MASK_WHITE_PAWN_ATTACKS_HPP_

#include "Types.hpp"

#include <unordered_map>

std::unordered_map<const Square, const Bitboard> const MASK_WHITE_PAWN_ATTACKS = {
	{ Square::A1, 0x0000000000000200ULL },
	{ Square::B1, 0x0000000000000500ULL },
	{ Square::C1, 0x0000000000000a00ULL },
	{ Square::D1, 0x0000000000001400ULL },
	{ Square::E1, 0x0000000000002800ULL },
	{ Square::F1, 0x0000000000005000ULL },
	{ Square::G1, 0x000000000000a000ULL },
	{ Square::H1, 0x0000000000004000ULL },
	{ Square::A2, 0x0000000000020000ULL },
	{ Square::B2, 0x0000000000050000ULL },
	{ Square::C2, 0x00000000000a0000ULL },
	{ Square::D2, 0x0000000000140000ULL },
	{ Square::E2, 0x0000000000280000ULL },
	{ Square::F2, 0x0000000000500000ULL },
	{ Square::G2, 0x0000000000a00000ULL },
	{ Square::H2, 0x0000000000400000ULL },
	{ Square::A3, 0x0000000002000000ULL },
	{ Square::B3, 0x0000000005000000ULL },
	{ Square::C3, 0x000000000a000000ULL },
	{ Square::D3, 0x0000000014000000ULL },
	{ Square::E3, 0x0000000028000000ULL },
	{ Square::F3, 0x0000000050000000ULL },
	{ Square::G3, 0x00000000a0000000ULL },
	{ Square::H3, 0x0000000040000000ULL },
	{ Square::A4, 0x0000000200000000ULL },
	{ Square::B4, 0x0000000500000000ULL },
	{ Square::C4, 0x0000000a00000000ULL },
	{ Square::D4, 0x0000001400000000ULL },
	{ Square::E4, 0x0000002800000000ULL },
	{ Square::F4, 0x0000005000000000ULL },
	{ Square::G4, 0x000000a000000000ULL },
	{ Square::H4, 0x0000004000000000ULL },
	{ Square::A5, 0x0000020000000000ULL },
	{ Square::B5, 0x0000050000000000ULL },
	{ Square::C5, 0x00000a0000000000ULL },
	{ Square::D5, 0x0000140000000000ULL },
	{ Square::E5, 0x0000280000000000ULL },
	{ Square::F5, 0x0000500000000000ULL },
	{ Square::G5, 0x0000a00000000000ULL },
	{ Square::H5, 0x0000400000000000ULL },
	{ Square::A6, 0x0002000000000000ULL },
	{ Square::B6, 0x0005000000000000ULL },
	{ Square::C6, 0x000a000000000000ULL },
	{ Square::D6, 0x0014000000000000ULL },
	{ Square::E6, 0x0028000000000000ULL },
	{ Square::F6, 0x0050000000000000ULL },
	{ Square::G6, 0x00a0000000000000ULL },
	{ Square::H6, 0x0040000000000000ULL },
	{ Square::A7, 0x0200000000000000ULL },
	{ Square::B7, 0x0500000000000000ULL },
	{ Square::C7, 0x0a00000000000000ULL },
	{ Square::D7, 0x1400000000000000ULL },
	{ Square::E7, 0x2800000000000000ULL },
	{ Square::F7, 0x5000000000000000ULL },
	{ Square::G7, 0xa000000000000000ULL },
	{ Square::H7, 0x4000000000000000ULL },
	{ Square::A8, 0x0000000000000000ULL },
	{ Square::B8, 0x0000000000000000ULL },
	{ Square::C8, 0x0000000000000000ULL },
	{ Square::D8, 0x0000000000000000ULL },
	{ Square::E8, 0x0000000000000000ULL },
	{ Square::F8, 0x0000000000000000ULL },
	{ Square::G8, 0x0000000000000000ULL },
	{ Square::H8, 0x0000000000000000ULL },
};

#endif // _MASK_WHITE_PAWN_ATTACKS_HPP_
