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

class BoardHelper;

/*
 * Hold the board representation
 */
class Board {
    public:
        Board();
        void init() noexcept;
        void reset() noexcept;
    private:
        void updateWhiteAllBitdoard() noexcept;
        void updateBlackAllBitdoard() noexcept;
        std::unordered_map<Piece, Bitboard> _pieces_bb;
        // static std::unordered_map<Square, Bitboard> const _attacks_rook_mask;
        // static std::unordered_map<Square, Bitboard> const _attacks_knight_mask;
        // static std::unordered_map<Square, Bitboard> const _attacks_beshop_mask;
        // static std::unordered_map<Square, Bitboard> const _attacks_queen_mask;
        // static std::unordered_map<Square, Bitboard> const _attacks_king_mask;
        // static std::unordered_map<Square, Bitboard> const _attacks_white_pawn_mask;
        // static std::unordered_map<Square, Bitboard> const _attacks_black_pawn_mask;

        friend class BoardHelper;
};

#endif // _BOARD_HPP_
