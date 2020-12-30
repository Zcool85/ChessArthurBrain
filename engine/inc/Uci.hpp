#ifndef _UCI_HPP_
#define _UCI_HPP_

#include "Game.hpp"

class Uci {
    public:
        void run();
    private:
        Game _current_game;
        void send_engine_name() const;
        void send_engine_author() const;
        void send_engine_options() const;
        // Others send possibilities :
        // ---------------------------
        // bestmove  [ ponder  ]
        // copyprotection
        // registration
        // info
        // option
        void handle_command_uci() const;
        void handle_command_isready() const;
};

#endif // _UCI_HPP_
