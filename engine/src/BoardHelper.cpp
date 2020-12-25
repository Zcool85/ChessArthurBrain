#include "BoardHelper.hpp"

#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <unordered_map>
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
    unordered_map<Piece, string> const display = _showAscii ? glyph_ascii_pieces : glyph_unicode_pieces;
    string pieces[SQUARE_NB];
    
    // Set pieces position for each square
    for (auto square = SQ_A1; square < SQUARE_NB; square++)
        for (const auto& bb : _board._pieces_bb)
            if (display.contains(bb.first) && bb.second[square]) pieces[square] = display.at(bb.first);

    // Set empty squares
    for (auto square = SQ_A1; square < SQUARE_NB; square++) {
        if (pieces[square].empty()) {
            if (_showSquare == ShowSquere::DARK) {
                if (_board._dark_squares[square])
                    pieces[square] = "▓";
                else
                    pieces[square] = "░";
            }
            if (_showSquare == ShowSquere::LIGHT) {
                if (_board._dark_squares[square])
                    pieces[square] = "░";
                else
                    pieces[square] = " ";
            }
            if (_showSquare == ShowSquere::OFF) pieces[square] = " ";
        }
    }

    // Display board
    if (_reverse) {
        cout << "╔═════════════════╗╮" << endl;

        for (auto rank = 0; rank < 8; rank++)
        {
            cout << "║ ";
            for (auto file = FILE_NB - 1; file >= FILE_A; file--)
                cout << pieces[make_square(static_cast<File>(file), static_cast<Rank>(rank))] << " ";
            cout << "║" << rank + 1 << endl;
        }
        
        cout << "╚═════════════════╝┊" << endl;
        cout << "╰┈h┈g┈f┈e┈d┈c┈b┈a┈┈╯" << endl;
    }
    else {
        cout << "╔═════════════════╗╮" << endl;

        for (auto rank = 7; rank >= 0; rank--)
        {
            cout << "║ ";
            for (auto file = FILE_A; file < FILE_NB; file++)
                cout << pieces[make_square(file, static_cast<Rank>(rank))] << " ";
            cout << "║" << rank + 1 << endl;
        }
        
        cout << "╚═════════════════╝┊" << endl;
        cout << "╰┈a┈b┈c┈d┈e┈f┈g┈h┈┈╯" << endl;
    }
}

// EOF
