#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "Types.hpp"

#include <string>

class BoardHelper;

/*
 * Hold the board representation
 */
class Board {
    public:
        Board();
        void init();
        //void load(string& fen);
    private:
        void _init_white();
        void _init_black();
        Bitboard _pieces_bb[PIECE_NB];
        Bitboard _dark_squares;
        friend class BoardHelper;
};

#endif // _BOARD_HPP_
