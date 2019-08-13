#include "Board.h"
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

using namespace boost::python;


// Define python module

BOOST_PYTHON_MODULE(Board)
{
    // This prevents dtype from causing segfault 11's (memory?)
    // probably helps more too.
    // May be needed in the future:
    // Py_Initialize();
    // np::initialize();

    class_<GameBoard>("GameBoard")
        .def(vector_indexing_suite<GameBoard>() );
    
    class_<Board>("Board")
        // Getters
        .def("getTurnPlayer", &Board::getTurnPlayer)
        .def("getBoard", &Board::getBoard)
        .def("getValidMoves", &Board::getValidMoves)
        .def("isBoardFull", &Board::isBoardFull)
        .def("whoWon", &Board::whoWon)

        // Setter
        .def("addMove", &Board::addMove)

        // Printers
        .def("printBoard", &Board::printBoard)
        .def("printMoveMap", &Board::printMoveMap)
    ;
}
