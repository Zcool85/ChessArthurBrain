#include "Uci.hpp"
#include "Misc.hpp"

#include <sstream>
#include <iostream>

using namespace std;

#define ENGINE_NAME     "ChessArthurBrain"
#define ENGINE_VERSION  "0.1"
#define ENGINE_AUTHOR   "Zéro Cool"

void Uci::send_engine_name() const {
    stringstream ss;
    ss << "id name " << ENGINE_NAME << " (" << ENGINE_VERSION << ")";
    send_line(ss.str());
}

void Uci::send_engine_author() const {
    stringstream ss;
    ss << "id author " << ENGINE_AUTHOR;
    send_line(ss.str());
}

void Uci::send_engine_options() const {
    // TODO
}

void Uci::handle_command_uci() const {
    send_engine_name();
    send_engine_author();
    send_engine_options();
    send_line("uciok");
}

void Uci::handle_command_isready() const {
    send_line("readyok");
}

void Uci::run() {

    // Commands :
    // ----------
    // uci
    // debug
    // isready
    // setoption name  [value ]
    // register
    // ucinewgame
    // position [fen  | startpos ]  moves  .... 
    // go
    // ponderhit
    // stop
    // quit

    string token, command;
    bool quit = false;

    do {
        if (!getline(cin, command))
            command = "quit";

        istringstream is(command);

        token.clear();
        is >> skipws >> token;

        if (token == "quit") {
            quit = true;
            // Stop "thinking"
            continue;
        }
        if (token == "stop") {
            // Stop "thinking"
            continue;
        }
        if (token == "uci") {
            handle_command_uci();
            continue;
        }

        if (token == "ponderhit") {
            // TODO
            continue;
        }

        if (token == "setoption") {
            // TODO
            continue;
        }

        if (token == "go") {
            // TODO
            continue;
        }

        if (token == "position") {
            // TODO
            continue;
        }

        if (token == "ucinewgame") {
            // TODO
            continue;
        }

        if (token == "isready") {
            handle_command_isready();
            continue;
        }

        stringstream ss;
        ss << "Unknown command: " << command;
        send_line(ss.str());
    } while (!quit);
}