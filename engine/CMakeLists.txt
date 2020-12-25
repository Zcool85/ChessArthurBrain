project(Application
            VERSION 1.0
            LANGUAGES CXX
        )

include_directories(inc/)

set(SRCS
        main.cpp
        src/Board.cpp
        src/BoardHelper.cpp
        src/DebugEngineCLI.cpp
    )

set(HEADERS
        inc/Types.hpp
        inc/Board.hpp
        inc/BoardHelper.hpp
        inc/DebugEngineCLI.hpp
        inc/Unused.hpp
        inc/BitboardHelper.hpp
    )

add_executable(ChessArthurEngine ${SRCS} ${HEADERS})
