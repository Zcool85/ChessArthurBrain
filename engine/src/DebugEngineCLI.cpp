#include "DebugEngineCLI.hpp"
#include "Unused.hpp"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const string CMD_QUIT = "quit";
const string CMD_INIT = "init";
const string CMD_RESET = "reset";
const string CMD_SHOW = "show";
const string CMD_DUMP = "dump";
const string CMD_DUMP_PRETTY_PRINT = "dumppp";
const string CMD_SET  = "set";
const string CMD_HELP = "help";

void showHelp() {
    cerr << "quit" << endl;
    cerr << "init" << endl;
    cerr << "reset" << endl;
    cerr << "show" << endl;
    cerr << "dump" << endl;
    cerr << "dumppp" << endl;
    cerr << "set ascii on/off" << endl;
    cerr << "set square light/dark/off" << endl;
    cerr << "set reverse true/false" << endl;
    cerr << "" << endl;
}

DebugEngineCLI::DebugEngineCLI(Board& board)
    : _boardHelper(board) { }

void DebugEngineCLI::main(int argc, char* argv[]) {
    unused(argc);
    unused(argv);

    string token, command;

    do {
        cout << "> ";
        cout.flush();

        if (!getline(cin, command))
            command = CMD_QUIT;

        istringstream is(command);

        token.clear();
        is >> skipws >> token;
        
        if (token.empty()) continue;

        if (token == CMD_QUIT) continue;

        if (token == CMD_HELP) { showHelp(); continue; }

        if (token == CMD_INIT) { _boardHelper.init(); continue; }

        if (token == CMD_RESET) { _boardHelper.reset(); continue; }

        if (token == CMD_SHOW) { _boardHelper.print(); continue; }

        if (token == CMD_DUMP) { _boardHelper.dump(); continue; }

        if (token == CMD_DUMP_PRETTY_PRINT) { _boardHelper.dump_pretty_print(); continue; }

        if (token == CMD_SET) { _boardHelper.setOptions(is); continue; }
        
        cerr << "Unknow command \"" << token << "\"" << endl;
        cerr << "Type \"" << CMD_HELP << "\" for command list" << endl;
    } while (token != CMD_QUIT);
}

// EOF
