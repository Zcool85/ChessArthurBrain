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
        src/Uci.cpp
    )

set(HEADERS
        inc/Types.hpp
        inc/Board.hpp
        inc/BoardHelper.hpp
        inc/DebugEngineCLI.hpp
        inc/Unused.hpp
        inc/BitboardHelper.hpp
        inc/Game.hpp
        inc/Misc.hpp
        inc/Move.hpp
        inc/Position.hpp
        inc/Uci.hpp
    )

add_executable(ChessArthurEngine ${SRCS} ${HEADERS})

target_link_libraries(ChessArthurEngine
                           PRIVATE
                                Boost::system
                      )