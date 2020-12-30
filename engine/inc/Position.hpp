#ifndef _POSITION_HPP_
#define _POSITION_HPP_

#include "Types.hpp"
#include "Board.hpp"

/*
 * Hold the states of the current position
 */
class  Position {
    public:
        // /*
        //  * Bitboard possibles moves
        //  */
        // Bitboard const white_moves() const noexcept;
        // Bitboard const white_rook_moves() const noexcept;
        // Bitboard const white_knight_moves() const noexcept;
        // Bitboard const white_beshop_moves() const noexcept;
        // Bitboard const white_queen_moves() const noexcept;
        // Bitboard const white_king_moves() const noexcept;
        // Bitboard const white_pawn_moves() const noexcept;
        // Bitboard const black_moves() const noexcept;
        // Bitboard const black_rook_moves() const noexcept;
        // Bitboard const black_knight_moves() const noexcept;
        // Bitboard const black_beshop_moves() const noexcept;
        // Bitboard const black_queen_moves() const noexcept;
        // Bitboard const black_king_moves() const noexcept;
        // Bitboard const black_pawn_moves() const noexcept;
        // /*
        //  * Bitboard attacks
        //  */
        // Bitboard const white_rook_attacks(Square& const from_square) const noexcept;
        // Bitboard const white_knight_attacks(Square& const from_square) const noexcept;
        // Bitboard const white_beshop_attacks(Square& const from_square) const noexcept;
        // Bitboard const white_queen_attacks(Square& const from_square) const noexcept;
        // Bitboard const white_king_attacks(Square& const from_square) const noexcept;
        // Bitboard const white_pawn_attacks(Square& const from_square, Square& const en_passant_square) const noexcept;
        // Bitboard const black_rook_attacks(Square& const from_square) const noexcept;
        // Bitboard const black_knight_attacks(Square& const from_square) const noexcept;
        // Bitboard const black_beshop_attacks(Square& const from_square) const noexcept;
        // Bitboard const black_queen_attacks(Square& const from_square) const noexcept;
        // Bitboard const black_king_attacks(Square& const from_square) const noexcept;
        // Bitboard const black_pawn_attacks(Square& const from_square, Square& const en_passant_square) const noexcept;
    private:
        __unused Board _board;
        // Color _color_to_move;
        // ?? _castle_rights;
        __unused Square _en_passant_target;
        __unused int _halfmove_clock;
        __unused int _halfmove;
        __unused bool king_in_check;
};

#endif // _POSITION_HPP_
