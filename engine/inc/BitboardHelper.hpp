#ifndef _BITBOARD_HELPER_HPP_
#define _BITBOARD_HELPER_HPP_

#include "Types.hpp"

constexpr void setbit(Bitboard& bitboard, const Square& square) noexcept {
    bitboard |= 1ULL << static_cast<int>(square);
}

constexpr void unsetbit(Bitboard& bitboard, const Square& square) noexcept {
    bitboard &= ~(1ULL << static_cast<int>(square));
}

constexpr bool isset(const Bitboard& bitboard, const Square& square) noexcept {
    return bitboard[static_cast<int>(square)];
}

#endif // _BITBOARD_HELPER_HPP_