cmake_minimum_required(VERSION 3.13)
project(tictactapp)

set(CMAKE_CXX_STANDARD 14)


#### Build ####


set(BOARD_FILES
		Board/Board.cpp
		Board/Board.h)

add_library(tictac_app SHARED ${BOARD_FILES})
add_executable(tictactapp tictactapp.cpp)
target_link_libraries(tictactapp tictac_app)
