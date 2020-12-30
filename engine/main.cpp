#include "Board.hpp"
#include "Uci.hpp"
#include "DebugEngineCLI.hpp"

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    if (argc == 2) {
        // cli mode
        Board board;
        DebugEngineCLI cli(board);
        cli.main(argc, argv);
    } else {
        // uci mode
        Uci uci;
        uci.run();
    }

    return EXIT_SUCCESS;
}

// EOF