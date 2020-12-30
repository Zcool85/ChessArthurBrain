#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "Types.hpp"

#include <unordered_map>

extern Bitboard const MASK_DARK_SQUARES;
extern Bitboard const MASK_QUEEN_SIDE;
extern Bitboard const MASK_KING_SIDE;
extern Bitboard const MASK_CENTER_FILES;
extern Bitboard const MASK_CENTER;
extern Bitboard const MASK_FLANKS;

extern std::unordered_map<const Square, const Bitboard> const MASK_ROOK_ATTACKS;        // Computed by X-ray
extern std::unordered_map<const Square, const Bitboard> const MASK_KNIGHT_ATTACKS;
extern std::unordered_map<const Square, const Bitboard> const MASK_BESHOP_ATTACKS;      // Computed by X-ray
extern std::unordered_map<const Square, const Bitboard> const MASK_QUEEN_ATTACKS;       // Computed by X-ray
extern std::unordered_map<const Square, const Bitboard> const MASK_KING_ATTACKS;
extern std::unordered_map<const Square, const Bitboard> const MASK_WHITE_PAWN_ATTACKS;
extern std::unordered_map<const Square, const Bitboard> const MASK_BLACK_PAWN_ATTACKS;

class BoardHelper;

/*
 * Hold the board representation
 */
class Board {
    public:
        Board();
        void init() noexcept;
        void reset() noexcept;
        /*
        * Pieces locations
        */
        Bitboard const white_pieces() const noexcept;
        Bitboard const black_pieces() const noexcept;
        Bitboard const empty_squares() const noexcept;
        Bitboard const occupied_squares() const noexcept;
    private:
        void updateWhiteAllBitdoard() noexcept;
        void updateBlackAllBitdoard() noexcept;
        std::unordered_map<Piece, Bitboard> _pieces_bb;

        friend class BoardHelper;
};

#endif // _BOARD_HPP_
