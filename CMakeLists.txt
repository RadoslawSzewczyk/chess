cmake_minimum_required(VERSION 3.16.3)
project(chess)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES 
    src/pieces/Bishop.cpp
    src/Board.cpp
    src/ChessDatabase.cpp
    src/main.cpp
    src/computer.cpp
    src/pieces/King.cpp
    src/pieces/Knight.cpp
    src/moveFromPlayer.cpp
    src/pieces/Pawn.cpp
    src/pieces/Queen.cpp
    src/pieces/Rook.cpp
    src/twoHumans.cpp
)

set(HEADERS 
    src/Board.hpp
    src/gameMode.hpp
    src/moveFromPlayer.hpp
    src/pieces/Piece.hpp
    src/ChessDatabase.hpp
    src/common/systemCls.hpp
)

add_executable(chess ${SOURCES} ${HEADERS})

target_include_directories(chess PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_compile_options(chess PRIVATE -Wall -Wextra -Werror -Wunused-variable)
