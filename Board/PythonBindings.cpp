#include "Board.h"
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(Board)
{
    class_<Board>("Board")
        .def("grcheckMoveValideet", &Board::checkMoveValid)
        .def("addMove", &Board::addMove)
        .def("nextTurn", &Board::nextTurn)
        .def("getTurn", &Board::getTurn)
        .def("whoWon", &Board::whoWon)
        .def("isBoardFull", &Board::isBoardFull)
        .def("printBoard", &Board::printBoard)
    ;
}
