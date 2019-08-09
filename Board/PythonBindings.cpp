#include "Board.h"
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

using namespace boost::python;


// Define python module

BOOST_PYTHON_MODULE(Board)
{
    class_<GameBoard>("GameBoard")
        .def(vector_indexing_suite<GameBoard>() );
    
    class_<Board>("Board")
        .def("grcheckMoveValideet", &Board::checkMoveValid)
        .def("addMove", &Board::addMove)
        .def("nextTurn", &Board::nextTurn)
        .def("getTurn", &Board::getTurn)
        .def("getBoard", &Board::getBoard)
        .def("whoWon", &Board::whoWon)
        .def("isBoardFull", &Board::isBoardFull)
        .def("printBoard", &Board::printBoard)
    ;
}
