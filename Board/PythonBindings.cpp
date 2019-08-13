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
    np::initialize();

    class_<GameBoard>("GameBoard")
        .def(vector_indexing_suite<GameBoard>() );
    
    class_<Board>("Board")
        .def("checkMoveValid", &Board::checkMoveValid)
        .def("addMove", &Board::addMove)
        .def("nextTurn", &Board::nextTurn)
        .def("getTurn", &Board::getTurn)
        .def("getBoard", &Board::getBoard)
        .def("getBoardnp", &Board::getBoardnp)
        .def("whoWon", &Board::whoWon)
        .def("isBoardFull", &Board::isBoardFull)
        .def("printBoard", &Board::printBoard)
        .def("printMoveMap", &Board::printMoveMap)
    ;
}
