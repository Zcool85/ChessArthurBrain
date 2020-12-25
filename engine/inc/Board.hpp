#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "Types.hpp"

#include <string>
#include <unordered_map>

class BoardHelper;

/*
 * Hold the board representation
 */
class Board {
    public:
        Board();
        void init() noexcept;
        // TODO void load(string& fen);
    private:
        void updateWhiteAllBitdoard() noexcept;
        void updateBlackAllBitdoard() noexcept;
        std::unordered_map<Piece, Bitboard> _pieces_bb;
        Bitboard _dark_squares;
        friend class BoardHelper;
};

#endif // _BOARD_HPP_
