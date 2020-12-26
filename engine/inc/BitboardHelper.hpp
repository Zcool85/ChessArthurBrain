#ifndef _BITBOARD_HELPER_HPP_
#define _BITBOARD_HELPER_HPP_

#include "Types.hpp"

constexpr void setbit(Bitboard& bitboard, const Square& square) noexcept {
    bitboard.set(static_cast<int>(square));
}

constexpr void unsetbit(Bitboard& bitboard, const Square& square) noexcept {
    bitboard.reset(static_cast<int>(square));
}

constexpr bool isset(const Bitboard& bitboard, const Square& square) noexcept {
    return bitboard.test(static_cast<int>(square));
}

constexpr Square make_square(const File& file, const Rank& rank) noexcept {
    return Square((static_cast<int>(rank) << 3) + static_cast<int>(file));
}

#endif // _BITBOARD_HELPER_HPP_