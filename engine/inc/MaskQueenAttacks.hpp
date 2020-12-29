#ifndef _MASK_QUEEN_ATTACKS_HPP_
#define _MASK_QUEEN_ATTACKS_HPP_

#include "Types.hpp"

#include <unordered_map>

std::unordered_map<const Square, const Bitboard> const MASK_QUEEN_ATTACKS = {
	{ Square::A1, 0x81412111090503feULL },
	{ Square::B1, 0x02824222120a07fdULL },
	{ Square::C1, 0x0404844424150efbULL },
	{ Square::D1, 0x08080888492a1cf7ULL },
	{ Square::E1, 0x10101011925438efULL },
	{ Square::F1, 0x2020212224a870dfULL },
	{ Square::G1, 0x404142444850e0bfULL },
	{ Square::H1, 0x8182848890a0c07fULL },
	{ Square::A2, 0x412111090503fe03ULL },
	{ Square::B2, 0x824222120a07fd07ULL },
	{ Square::C2, 0x04844424150efb0eULL },
	{ Square::D2, 0x080888492a1cf71cULL },
	{ Square::E2, 0x101011925438ef38ULL },
	{ Square::F2, 0x20212224a870df70ULL },
	{ Square::G2, 0x4142444850e0bfe0ULL },
	{ Square::H2, 0x82848890a0c07fc0ULL },
	{ Square::A3, 0x2111090503fe0305ULL },
	{ Square::B3, 0x4222120a07fd070aULL },
	{ Square::C3, 0x844424150efb0e15ULL },
	{ Square::D3, 0x0888492a1cf71c2aULL },
	{ Square::E3, 0x1011925438ef3854ULL },
	{ Square::F3, 0x212224a870df70a8ULL },
	{ Square::G3, 0x42444850e0bfe050ULL },
	{ Square::H3, 0x848890a0c07fc0a0ULL },
	{ Square::A4, 0x11090503fe030509ULL },
	{ Square::B4, 0x22120a07fd070a12ULL },
	{ Square::C4, 0x4424150efb0e1524ULL },
	{ Square::D4, 0x88492a1cf71c2a49ULL },
	{ Square::E4, 0x11925438ef385492ULL },
	{ Square::F4, 0x2224a870df70a824ULL },
	{ Square::G4, 0x444850e0bfe05048ULL },
	{ Square::H4, 0x8890a0c07fc0a090ULL },
	{ Square::A5, 0x090503fe03050911ULL },
	{ Square::B5, 0x120a07fd070a1222ULL },
	{ Square::C5, 0x24150efb0e152444ULL },
	{ Square::D5, 0x492a1cf71c2a4988ULL },
	{ Square::E5, 0x925438ef38549211ULL },
	{ Square::F5, 0x24a870df70a82422ULL },
	{ Square::G5, 0x4850e0bfe0504844ULL },
	{ Square::H5, 0x90a0c07fc0a09088ULL },
	{ Square::A6, 0x0503fe0305091121ULL },
	{ Square::B6, 0x0a07fd070a122242ULL },
	{ Square::C6, 0x150efb0e15244484ULL },
	{ Square::D6, 0x2a1cf71c2a498808ULL },
	{ Square::E6, 0x5438ef3854921110ULL },
	{ Square::F6, 0xa870df70a8242221ULL },
	{ Square::G6, 0x50e0bfe050484442ULL },
	{ Square::H6, 0xa0c07fc0a0908884ULL },
	{ Square::A7, 0x03fe030509112141ULL },
	{ Square::B7, 0x07fd070a12224282ULL },
	{ Square::C7, 0x0efb0e1524448404ULL },
	{ Square::D7, 0x1cf71c2a49880808ULL },
	{ Square::E7, 0x38ef385492111010ULL },
	{ Square::F7, 0x70df70a824222120ULL },
	{ Square::G7, 0xe0bfe05048444241ULL },
	{ Square::H7, 0xc07fc0a090888482ULL },
	{ Square::A8, 0xfe03050911214181ULL },
	{ Square::B8, 0xfd070a1222428202ULL },
	{ Square::C8, 0xfb0e152444840404ULL },
	{ Square::D8, 0xf71c2a4988080808ULL },
	{ Square::E8, 0xef38549211101010ULL },
	{ Square::F8, 0xdf70a82422212020ULL },
	{ Square::G8, 0xbfe0504844424140ULL },
	{ Square::H8, 0x7fc0a09088848281ULL },
};

#endif // _MASK_QUEEN_ATTACKS_HPP_