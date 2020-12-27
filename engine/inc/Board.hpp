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

// extern std::unordered_map<Square, Bitboard> const _attacks_rook_mask;        // Computed by X-ray
// extern std::unordered_map<Square, Bitboard> const _attacks_knight_mask;
// extern std::unordered_map<Square, Bitboard> const _attacks_beshop_mask;      // Computed by X-ray
// extern std::unordered_map<Square, Bitboard> const _attacks_queen_mask;       // Computed by X-ray
// extern std::unordered_map<Square, Bitboard> const _attacks_king_mask;
// extern std::unordered_map<Square, Bitboard> const _attacks_white_pawn_mask;
// extern std::unordered_map<Square, Bitboard> const _attacks_black_pawn_mask;

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
        void updateWhiteAllBitdoard() noexcept;
        void updateBlackAllBitdoard() noexcept;
        std::unordered_map<Piece, Bitboard> _pieces_bb;

        friend class BoardHelper;
};

#endif // _BOARD_HPP_
