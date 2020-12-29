#ifndef _MASK_KNIGHT_ATTACKS_HPP_
#define _MASK_KNIGHT_ATTACKS_HPP_

#include "Types.hpp"

#include <unordered_map>

std::unordered_map<const Square, const Bitboard> const MASK_KNIGHT_ATTACKS = {
	{ Square::A1, 0x0000000000020400ULL },
	{ Square::B1, 0x0000000000050800ULL },
	{ Square::C1, 0x00000000000a1100ULL },
	{ Square::D1, 0x0000000000142200ULL },
	{ Square::E1, 0x0000000000284400ULL },
	{ Square::F1, 0x0000000000508800ULL },
	{ Square::G1, 0x0000000000a01000ULL },
	{ Square::H1, 0x0000000000402000ULL },
	{ Square::A2, 0x0000000002040004ULL },
	{ Square::B2, 0x0000000005080008ULL },
	{ Square::C2, 0x000000000a110011ULL },
	{ Square::D2, 0x0000000014220022ULL },
	{ Square::E2, 0x0000000028440044ULL },
	{ Square::F2, 0x0000000050880088ULL },
	{ Square::G2, 0x00000000a0100010ULL },
	{ Square::H2, 0x0000000040200020ULL },
	{ Square::A3, 0x0000000204000402ULL },
	{ Square::B3, 0x0000000508000805ULL },
	{ Square::C3, 0x0000000a1100110aULL },
	{ Square::D3, 0x0000001422002214ULL },
	{ Square::E3, 0x0000002844004428ULL },
	{ Square::F3, 0x0000005088008850ULL },
	{ Square::G3, 0x000000a0100010a0ULL },
	{ Square::H3, 0x0000004020002040ULL },
	{ Square::A4, 0x0000020400040200ULL },
	{ Square::B4, 0x0000050800080500ULL },
	{ Square::C4, 0x00000a1100110a00ULL },
	{ Square::D4, 0x0000142200221400ULL },
	{ Square::E4, 0x0000284400442800ULL },
	{ Square::F4, 0x0000508800885000ULL },
	{ Square::G4, 0x0000a0100010a000ULL },
	{ Square::H4, 0x0000402000204000ULL },
	{ Square::A5, 0x0002040004020000ULL },
	{ Square::B5, 0x0005080008050000ULL },
	{ Square::C5, 0x000a1100110a0000ULL },
	{ Square::D5, 0x0014220022140000ULL },
	{ Square::E5, 0x0028440044280000ULL },
	{ Square::F5, 0x0050880088500000ULL },
	{ Square::G5, 0x00a0100010a00000ULL },
	{ Square::H5, 0x0040200020400000ULL },
	{ Square::A6, 0x0204000402000000ULL },
	{ Square::B6, 0x0508000805000000ULL },
	{ Square::C6, 0x0a1100110a000000ULL },
	{ Square::D6, 0x1422002214000000ULL },
	{ Square::E6, 0x2844004428000000ULL },
	{ Square::F6, 0x5088008850000000ULL },
	{ Square::G6, 0xa0100010a0000000ULL },
	{ Square::H6, 0x4020002040000000ULL },
	{ Square::A7, 0x0400040200000000ULL },
	{ Square::B7, 0x0800080500000000ULL },
	{ Square::C7, 0x1100110a00000000ULL },
	{ Square::D7, 0x2200221400000000ULL },
	{ Square::E7, 0x4400442800000000ULL },
	{ Square::F7, 0x8800885000000000ULL },
	{ Square::G7, 0x100010a000000000ULL },
	{ Square::H7, 0x2000204000000000ULL },
	{ Square::A8, 0x0004020000000000ULL },
	{ Square::B8, 0x0008050000000000ULL },
	{ Square::C8, 0x00110a0000000000ULL },
	{ Square::D8, 0x0022140000000000ULL },
	{ Square::E8, 0x0044280000000000ULL },
	{ Square::F8, 0x0088500000000000ULL },
	{ Square::G8, 0x0010a00000000000ULL },
	{ Square::H8, 0x0020400000000000ULL },
};

#endif // _MASK_KNIGHT_ATTACKS_HPP_