#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
using namespace std;

void ray_vertical(int const square, bitset<64>& biset) {
    // add 8 for north
    int tmp_square = square;
    while (tmp_square + 8 < 64) {
        tmp_square += 8;
        biset.set(tmp_square);
    }
    // subtract 8 for south
    tmp_square = square;
    while (tmp_square - 8 > -1) {
        tmp_square -= 8;
        biset.set(tmp_square);
    }
}

void ray_horizontal(int const square, bitset<64>& biset) {
    int rank = square / 8;
    int min_file = rank * 8;
    int max_file = min_file + 8;

    // add 1 for east
    int tmp_square = square;
    while (tmp_square + 1 < 64 && (tmp_square + 1) < max_file) {
        tmp_square += 1;
        biset.set(tmp_square);
    }
    // subtract 1 for west
    tmp_square = square;
    while (tmp_square - 1 > -1 && (tmp_square - 1) >= min_file) {
        tmp_square -= 1;
        biset.set(tmp_square);
    }
}

void ray_diag(int const square, bitset<64>& biset) {
    int rank = square / 8;
    int file = square % 8;

    // add 9 for north east
    int tmp_square = square;
    while (tmp_square + 9 < 64 && (tmp_square + 9) % 8 > file && (tmp_square + 9) / 8 > rank) {
        tmp_square += 9;
        biset.set(tmp_square);
    }
    // subtract 9 for south west
    tmp_square = square;
    while (tmp_square - 9 > -1 && (tmp_square - 9) % 8 < file && (tmp_square - 9) / 8 < rank) {
        tmp_square -= 9;
        biset.set(tmp_square);
    }
    // add 7 for north west
    tmp_square = square;
    while (tmp_square + 7 < 64 && (tmp_square + 7) % 8 < file && (tmp_square + 7) / 8 > rank) {
        tmp_square += 7;
        biset.set(tmp_square);
    }
    // subtract 7 for south east
    tmp_square = square;
    while (tmp_square - 7 > -1 && (tmp_square - 7) % 8 > file && (tmp_square - 7) / 8 < rank) {
        tmp_square -= 7;
        biset.set(tmp_square);
    }
}

string make_square(int i) {
    char buff[2];
    buff[0] = 'A' + (i % 8);
    buff[1] = '1' + (i / 8);
    string result;
    result.append(1, buff[0]);
    result.append(1, buff[1]);
    return result;
}

void generate_root_attacks(ostream& stream) {
    // Generate rook attacks masks
    stream << "#ifndef _MASK_ROOK_ATTACKS_HPP_" << endl;
    stream << "#define _MASK_ROOK_ATTACKS_HPP_" << endl;
    stream << "" << endl;
    stream << "#include \"Types.hpp\"" << endl;
    stream << "" << endl;
    stream << "#include <unordered_map>" << endl;
    stream << "" << endl;
    stream << "std::unordered_map<const Square, const Bitboard> const MASK_ROOK_ATTACKS = {" << endl;

    // A1, B1, C1, etc.
    for (size_t i = 0; i < 64; i++)
    {
        bitset<64> biset;
        ray_vertical(i, biset);
        ray_horizontal(i, biset);
        stream << "\t{ Square::" << make_square(i) << ", 0x" << hex << setw(16) << setfill('0') << biset.to_ulong() << "ULL }," << endl;
    }
    
    stream << "};" << endl;
    stream << "" << endl;
    stream << "#endif // _MASK_ROOK_ATTACKS_HPP_" << endl;
}

void generate_beshop_attacks(ostream& stream) {
    // Generate rook attacks masks
    stream << "#ifndef _MASK_BESHOP_ATTACKS_HPP_" << endl;
    stream << "#define _MASK_BESHOP_ATTACKS_HPP_" << endl;
    stream << "" << endl;
    stream << "#include \"Types.hpp\"" << endl;
    stream << "" << endl;
    stream << "#include <unordered_map>" << endl;
    stream << "" << endl;
    stream << "std::unordered_map<const Square, const Bitboard> const MASK_BESHOP_ATTACKS = {" << endl;

    // A1, B1, C1, etc.
    for (size_t i = 0; i < 64; i++)
    {
        bitset<64> biset;
        ray_diag(i, biset);
        stream << "\t{ Square::" << make_square(i) << ", 0x" << hex << setw(16) << setfill('0') << biset.to_ulong() << "ULL }," << endl;
    }
    
    stream << "};" << endl;
    stream << "" << endl;
    stream << "#endif // _MASK_BESHOP_ATTACKS_HPP_" << endl;
}

void generate_queen_attacks(ostream& stream) {
    // Generate rook attacks masks
    stream << "#ifndef _MASK_QUEEN_ATTACKS_HPP_" << endl;
    stream << "#define _MASK_QUEEN_ATTACKS_HPP_" << endl;
    stream << "" << endl;
    stream << "#include \"Types.hpp\"" << endl;
    stream << "" << endl;
    stream << "#include <unordered_map>" << endl;
    stream << "" << endl;
    stream << "std::unordered_map<const Square, const Bitboard> const MASK_QUEEN_ATTACKS = {" << endl;

    // A1, B1, C1, etc.
    for (size_t i = 0; i < 64; i++)
    {
        bitset<64> biset;
        ray_vertical(i, biset);
        ray_horizontal(i, biset);
        ray_diag(i, biset);
        stream << "\t{ Square::" << make_square(i) << ", 0x" << hex << setw(16) << setfill('0') << biset.to_ulong() << "ULL }," << endl;
    }
    
    stream << "};" << endl;
    stream << "" << endl;
    stream << "#endif // _MASK_QUEEN_ATTACKS_HPP_" << endl;
}

void generate_knight_attacks(ostream& stream) {
    // Generate rook attacks masks
    stream << "#ifndef _MASK_KNIGHT_ATTACKS_HPP_" << endl;
    stream << "#define _MASK_KNIGHT_ATTACKS_HPP_" << endl;
    stream << "" << endl;
    stream << "#include \"Types.hpp\"" << endl;
    stream << "" << endl;
    stream << "#include <unordered_map>" << endl;
    stream << "" << endl;
    stream << "std::unordered_map<const Square, const Bitboard> const MASK_KNIGHT_ATTACKS = {" << endl;

    // A1, B1, C1, etc.
    for (int i = 0; i < 64; i++)
    {
        int rank = i / 8;
        int file = i % 8;

        bitset<64> biset;

        if (rank < 6 && file < 7 && i + 17 < 64) biset.set(i + 17);
        if (rank < 7 && file < 6 && i + 10 < 64) biset.set(i + 10);
        if (rank < 7 && file > 1 && i + 6  < 64) biset.set(i + 6);
        if (rank < 6 && file > 0 && i + 15 < 64) biset.set(i + 15);
        if (rank > 0 && file < 6 && i - 6  > -1) biset.set(i - 6);
        if (rank > 1 && file < 7 && i - 15 > -1) biset.set(i - 15);
        if (rank > 1 && file > 0 && i - 17 > -1) biset.set(i - 17);
        if (rank > 0 && file > 1 && i - 10 > -1) biset.set(i - 10);
        stream << "\t{ Square::" << make_square(i) << ", 0x" << hex << setw(16) << setfill('0') << biset.to_ulong() << "ULL }," << endl;
    }
    
    stream << "};" << endl;
    stream << "" << endl;
    stream << "#endif // _MASK_KNIGHT_ATTACKS_HPP_" << endl;
}

void generate_king_attacks(ostream& stream) {
    // Generate rook attacks masks
    stream << "#ifndef _MASK_KING_ATTACKS_HPP_" << endl;
    stream << "#define _MASK_KING_ATTACKS_HPP_" << endl;
    stream << "" << endl;
    stream << "#include \"Types.hpp\"" << endl;
    stream << "" << endl;
    stream << "#include <unordered_map>" << endl;
    stream << "" << endl;
    stream << "std::unordered_map<const Square, const Bitboard> const MASK_KING_ATTACKS = {" << endl;

    // A1, B1, C1, etc.
    for (int i = 0; i < 64; i++)
    {
        int rank = i / 8;
        int file = i % 8;

        bitset<64> biset;

        if (rank < 7 && file < 7 && i + 9 < 64) biset.set(i + 9);
        if (rank < 7             && i + 8 < 64) biset.set(i + 8);
        if (rank < 7 && file > 0 && i + 7 < 64) biset.set(i + 7);
        if (            file < 7 && i + 1 < 64) biset.set(i + 1);
        if (            file > 0 && i - 1 > -1) biset.set(i - 1);
        if (rank > 0 && file < 7 && i - 7 > -1) biset.set(i - 7);
        if (rank > 0             && i - 8 > -1) biset.set(i - 8);
        if (rank > 0 && file > 0 && i - 9 > -1) biset.set(i - 9);
        stream << "\t{ Square::" << make_square(i) << ", 0x" << hex << setw(16) << setfill('0') << biset.to_ulong() << "ULL }," << endl;
    }
    
    stream << "};" << endl;
    stream << "" << endl;
    stream << "#endif // _MASK_KING_ATTACKS_HPP_" << endl;
}

void generate_white_pawn_attacks(ostream& stream) {
    // Generate rook attacks masks
    stream << "#ifndef _MASK_WHITE_PAWN_ATTACKS_HPP_" << endl;
    stream << "#define _MASK_WHITE_PAWN_ATTACKS_HPP_" << endl;
    stream << "" << endl;
    stream << "#include \"Types.hpp\"" << endl;
    stream << "" << endl;
    stream << "#include <unordered_map>" << endl;
    stream << "" << endl;
    stream << "std::unordered_map<const Square, const Bitboard> const MASK_WHITE_PAWN_ATTACKS = {" << endl;

    // A1, B1, C1, etc.
    for (int i = 0; i < 64; i++)
    {
        int rank = i / 8;
        int file = i % 8;

        bitset<64> biset;

        if (rank < 7 && file > 0 && i + 7 < 64) biset.set(i + 7);
        if (rank < 7 && file < 7 && i + 9 < 64) biset.set(i + 9);
        stream << "\t{ Square::" << make_square(i) << ", 0x" << hex << setw(16) << setfill('0') << biset.to_ulong() << "ULL }," << endl;
    }
    
    stream << "};" << endl;
    stream << "" << endl;
    stream << "#endif // _MASK_WHITE_PAWN_ATTACKS_HPP_" << endl;
}

void generate_black_pawn_attacks(ostream& stream) {
    // Generate rook attacks masks
    stream << "#ifndef _MASK_BLACK_PAWN_ATTACKS_HPP_" << endl;
    stream << "#define _MASK_BLACK_PAWN_ATTACKS_HPP_" << endl;
    stream << "" << endl;
    stream << "#include \"Types.hpp\"" << endl;
    stream << "" << endl;
    stream << "#include <unordered_map>" << endl;
    stream << "" << endl;
    stream << "std::unordered_map<const Square, const Bitboard> const MASK_BLACK_PAWN_ATTACKS = {" << endl;

    // A1, B1, C1, etc.
    for (int i = 0; i < 64; i++)
    {
        int rank = i / 8;
        int file = i % 8;

        bitset<64> biset;

        if (rank > 0 && file < 7 && i - 7 > -1) biset.set(i - 7);
        if (rank > 0 && file > 0 && i - 9 > -1) biset.set(i - 9);
        stream << "\t{ Square::" << make_square(i) << ", 0x" << hex << setw(16) << setfill('0') << biset.to_ulong() << "ULL }," << endl;
    }
    
    stream << "};" << endl;
    stream << "" << endl;
    stream << "#endif // _MASK_BLACK_PAWN_ATTACKS_HPP_" << endl;
}

int main(int argc, char* argv[]) {
    
    if (argc != 2) return 1;

    if (strcmp(argv[1], "rook") == 0)
        generate_root_attacks(cout);

    if (strcmp(argv[1], "knight") == 0)
        generate_knight_attacks(cout);

    if (strcmp(argv[1], "beshop") == 0)
        generate_beshop_attacks(cout);

    if (strcmp(argv[1], "queen") == 0)
        generate_queen_attacks(cout);

    if (strcmp(argv[1], "king") == 0)
        generate_king_attacks(cout);

    if (strcmp(argv[1], "white_pawn") == 0)
        generate_white_pawn_attacks(cout);

    if (strcmp(argv[1], "black_pawn") == 0)
        generate_black_pawn_attacks(cout);
}
