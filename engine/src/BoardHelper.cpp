#include "BoardHelper.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

const vector<string> glyph_ascii_pieces = {
    // Same index as enum Piece
    "P", "N", "B", "R", "Q", "K",   // white
    "p", "n", "b", "r", "q", "k"    // black
};

const vector<string> glyph_unicode_pieces = {
    // Same index as enum Piece
    "♟", "♞", "♝", "♜", "♛", "♚", // white
    "♙", "♘", "♗", "♖", "♕", "♔"  // black
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
    for (auto piece = W_PAWN; piece < PIECE_NB; piece++) {
        cout << "Piece " << piece << ": 0b" << bitset<64>(_board._pieces_bb[piece]) << endl;
    }
}

void BoardHelper::print() {
    vector<string> display;
    string pieces[SQUARE_NB];

    if (_showAscii)
        copy(glyph_ascii_pieces.begin(), glyph_ascii_pieces.end(), back_inserter(display));
    else
        copy(glyph_unicode_pieces.begin(), glyph_unicode_pieces.end(), back_inserter(display));
    
    // Set pieces position for each square
    for (auto square = SQ_A1; square < SQUARE_NB; square++)
        for (auto piece = W_PAWN; piece < PIECE_NB; piece++)
            if (_board._pieces_bb[piece][square]) pieces[square] = display[piece];

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
