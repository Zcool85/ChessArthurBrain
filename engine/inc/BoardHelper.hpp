#ifndef _BOARD_HELPER_HPP_
#define _BOARD_HELPER_HPP_

#include "Board.hpp"

#include <sstream>
using namespace std;

enum ShowSquere {
    LIGHT,
    DARK,
    OFF
};

class BoardHelper {
    public:
        BoardHelper(Board& board);
        void init();
        void reset();
        void print();
        void dump();
        void dump_pretty_print();
        void setOptions(istringstream& is);
    private:
        Board& _board;
        bool _showAscii;
        ShowSquere _showSquare;
        bool _reverse;
};

#endif // _BOARD_HELPER_HPP_
