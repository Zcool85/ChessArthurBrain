#ifndef _DEBUG_ENGINE_CLI_HPP_
#define _DEBUG_ENGINE_CLI_HPP_

#include "Board.hpp"
#include "BoardHelper.hpp"

class DebugEngineCLI {
    public:
        DebugEngineCLI(Board& board);
        void main(int argc, char* argv[]);
    private:
        BoardHelper _boardHelper;
};

#endif // _DEBUG_ENGINE_HPP_
