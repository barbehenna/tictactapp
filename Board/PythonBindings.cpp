#include "Board.h"
#include <vector>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>

using namespace boost::python;
namespace np = boost::python::numpy;


// Define python module

BOOST_PYTHON_MODULE(Board)
{
    // This prevents dtype from causing segfault 11's (memory?)
    // probably helps more too.
    // May be needed in the future:
    // Py_Initialize();
    np::initialize();
    
    class_<Board>("Board")
        // Additional Constructor
        .def(init<int, int>())

        // Getters
        .def("getTurnPlayer", &Board::getTurnPlayer)
        .def("getBoard", &Board::getBoardNumpy)
        .def("getValidMoves", &Board::getValidMovesNumpy)
        .def("isBoardFull", &Board::isBoardFull)
        .def("whoWon", &Board::whoWon)

        // Setter
        .def("addMove", &Board::addMove)

        // Printers
        .def("printBoard", &Board::printBoard)
        .def("printMoveMap", &Board::printMoveMap)
    ;
}
