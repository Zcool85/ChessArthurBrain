#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "Types.hpp"

#include <unordered_map>

class BoardHelper;

/*
 * Hold the board representation
 */
class Board {
    public:
        Board();
        void init() noexcept;
        void reset() noexcept;
        // TODO void load(string& fen);
    private:
        void updateWhiteAllBitdoard() noexcept;
        void updateBlackAllBitdoard() noexcept;
        std::unordered_map<Piece, Bitboard> _pieces_bb;
        const Bitboard _dark_squares;
        const Bitboard _queen_side;
        const Bitboard _king_side;
        const Bitboard _center_files;
        const Bitboard _center;
        const Bitboard _flanks;
        // attacks of rook
        // attacks of knight
        // attacks of beshop
        // attacks of queen
        // attacks of king
        // attacks of white pawn
        // attacks of black pawn

        friend class BoardHelper;
};

#endif // _BOARD_HPP_
