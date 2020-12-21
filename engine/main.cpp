#include "Board.hpp"
#include "DebugEngineCLI.hpp"

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    Board board;
    DebugEngineCLI cli(board);

    cli.main(argc, argv);
}

// EOF