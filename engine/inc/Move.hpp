#ifndef _MOVE_HPP_
#define _MOVE_HPP_

#include "Types.hpp"

class Move {
    private:
        Piece _piece;
        Square _from;
        Square _to;
        bool _is_capture;
        bool _is_en_passant;
        bool _is_castling;
        bool _is_promotion;
        Piece _promote_to;
};

#endif // _MOVE_HPP_
