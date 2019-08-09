project(tictactapp)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)


#### Find Libraries ####


set(PY_VERSION, 3.7)
find_package(PythonLibs ${PY_VERSION} REQUIRED)

set(BOOST_VERSION 1.70.0)
find_package(Boost ${BOOST_VERSION} REQUIRED COMPONENTS 
	system 
	python37)

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})


#### Output Locations ####

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_MODULE_PREFIX "")


#### Build ####


set(BOARD_FILES
		Board/Board.cpp
		Board/Board.h)

# add_library(tictac_app SHARED ${BOARD_FILES})
# target_link_libraries(tictactapp_game tictac_app)

# add_library(Board SHARED Board/PythonBindings.cpp ${BOARD_FILES})
# target_link_libraries(Board ${Boost_LIBRARIES} ${PROJECT_NAME})

# Build Python Board library
# Set up the libraries and header search paths for this target
add_library(Board MODULE ${BOARD_FILES} Board/PythonBindings.cpp)

target_link_libraries(Board ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(Board PRIVATE ${PYTHON_INCLUDE_DIRS})

add_executable(tictac_app ${BOARD_FILES} main_game.cpp)

target_link_libraries(tictac_app ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(tictac_app PRIVATE ${PYTHON_INCLUDE_DIRS})

