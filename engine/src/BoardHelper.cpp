#include "BoardHelper.hpp"
#include "BitboardHelper.hpp"

#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <iterator>
#include <boost/range/adaptor/reversed.hpp>
using namespace std;

ostream& operator<<(ostream &o, Piece piece) {
    switch(piece) {
        case Piece::WhiteAll:    return o << "AW";
        case Piece::WhitePawn:   return o << "P";
        case Piece::WhiteKnight: return o << "N";
        case Piece::WhiteBishop: return o << "B";
        case Piece::WhiteRook:   return o << "R";
        case Piece::WhiteQueen:  return o << "Q";
        case Piece::WhiteKing:   return o << "K";
        case Piece::BlackAll:    return o << "AB";
        case Piece::BlackPawn:   return o << "p";
        case Piece::BlackKnight: return o << "n";
        case Piece::BlackBishop: return o << "b";
        case Piece::BlackRook:   return o << "r";
        case Piece::BlackQueen:  return o << "q";
        case Piece::BlackKing:   return o << "k";
        default: return o << "(invalid value)";
    }
}

ostream& operator<<(ostream &o, Rank rank) {
    return o << static_cast<int>(rank) + 1;
}

static unordered_map<Piece, string> const glyph_ascii_pieces = {
    {Piece::WhitePawn,   "P"},
    {Piece::WhiteKnight, "N"},
    {Piece::WhiteBishop, "B"},
    {Piece::WhiteRook,   "R"},
    {Piece::WhiteQueen,  "Q"},
    {Piece::WhiteKing,   "K"},
    {Piece::BlackPawn,   "p"},
    {Piece::BlackKnight, "n"},
    {Piece::BlackBishop, "b"},
    {Piece::BlackRook,   "r"},
    {Piece::BlackQueen,  "q"},
    {Piece::BlackKing,   "k"},
};

static unordered_map<Piece, string> const glyph_unicode_pieces = {
    {Piece::WhitePawn,   "♟"},
    {Piece::WhiteKnight, "♞"},
    {Piece::WhiteBishop, "♝"},
    {Piece::WhiteRook,   "♜"},
    {Piece::WhiteQueen,  "♛"},
    {Piece::WhiteKing,   "♚"},
    {Piece::BlackPawn,   "♙"},
    {Piece::BlackKnight, "♘"},
    {Piece::BlackBishop, "♗"},
    {Piece::BlackRook,   "♖"},
    {Piece::BlackQueen,  "♕"},
    {Piece::BlackKing,   "♔"},
};

BoardHelper::BoardHelper(Board& board)
    : _board(board),
      _showAscii(false),
      _showSquare(ShowSquere::DARK),
      _reverse(false) { }

void BoardHelper::init() {
    _board.init();
}

void BoardHelper::setOptions(istringstream& is) {
    // set ascii on/off
    // set square light/dark/off
    // set reverse true/false
    string option_name, value;

    is >> option_name;
    is >> value;

    if (option_name == "ascii") {
        if (value == "on") { _showAscii = true; return; }
        if (value == "off") { _showAscii = false; return; }

        cerr << "No ascii option \"" << value << "\"" << endl;
    }

    if (option_name == "square") {
        if (value == "light") { _showSquare = ShowSquere::LIGHT; return; }
        if (value == "dark") { _showSquare = ShowSquere::DARK; return; }
        if (value == "off") { _showSquare = ShowSquere::OFF; return; }

        cerr << "No square option \"" << value << "\"" << endl;
    }

    if (option_name == "reverse") {
        if (value == "true") { _reverse = true; return; }
        if (value == "false") { _reverse = false; return; }

        cerr << "No reverse option \"" << value << "\"" << endl;
    }

    cerr << "No option \"" << option_name << "\"" << endl;
}

void BoardHelper::dump() {
    for (const auto& bb : _board._pieces_bb)
        cout << "Piece " << setw(2) << bb.first << ": 0b" << bb.second << endl;
}

void BoardHelper::print() {
    auto const display = _showAscii ? glyph_ascii_pieces : glyph_unicode_pieces;
    unordered_map<Square, string> pieces;
    
    // Set pieces positions for each square
    for (const auto& square : AllSquares)
        for (const auto& [piece, bitboard] : _board._pieces_bb)
            if (display.contains(piece) && isset(bitboard, square))
                pieces[square] = display.at(piece);

    // Set empty squares
    for (const auto& square : AllSquares) {
        if (pieces[square].empty()) {
            if (_showSquare == ShowSquere::DARK) {
                if (isset(_board._dark_squares, square))
                    pieces[square] = "▓";
                else
                    pieces[square] = "░";
            }
            if (_showSquare == ShowSquere::LIGHT) {
                if (isset(_board._dark_squares, square))
                    pieces[square] = "░";
                else
                    pieces[square] = " ";
            }
            if (_showSquare == ShowSquere::OFF)
                pieces[square] = " ";
        }
    }

    // Display board
    if (_reverse) {
        cout << "╔═════════════════╗╮" << endl;

        for (const auto& rank : AllRanks)
        {
            cout << "║ ";
            for (const auto& file : boost::adaptors::reverse(AllFiles)) {
                cout << pieces[make_square(file, rank)] << " ";
            }
            cout << "║" << rank << endl;
        }
        
        cout << "╚═════════════════╝┊" << endl;
        cout << "╰┈h┈g┈f┈e┈d┈c┈b┈a┈┈╯" << endl;
    }
    else {
        cout << "╔═════════════════╗╮" << endl;

        for (const auto& rank : boost::adaptors::reverse(AllRanks)) {
            cout << "║ ";
            for (const auto& file : AllFiles)
                cout << pieces[make_square(file, rank)] << " ";
            cout << "║" << rank << endl;
        }
        
        cout << "╚═════════════════╝┊" << endl;
        cout << "╰┈a┈b┈c┈d┈e┈f┈g┈h┈┈╯" << endl;
    }
}

// EOF
