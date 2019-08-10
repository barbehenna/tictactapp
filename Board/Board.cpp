//
// Created by Alton Barbehenn (barbehenna) on July 25, 2019
//

#include "Board.h"

#include <iostream>
#include <algorithm> // for std::fill
#include <vector>

#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
namespace p = boost::python;
namespace np = boost::python::numpy;

using namespace std;


template<typename T>
std::vector<T> flatten(const std::vector<std::vector<T>> &orig)
{   
	std::vector<T> ret;
	for(const auto &v: orig)
		ret.insert(ret.end(), v.begin(), v.end());                                                                                         
	return ret;
} 


Board::Board( void ) {
	board.resize(3, vector<int>(3));
	fill(board.begin(), board.end(), vector<int>(3, 0));
	turn = 1;
}

bool Board::checkMoveValid(int player, int row, int col) {
	if (row >= 3 || row < 0) {
		cout << "Move out of bounds" << endl;
		return false;
	}
	if (col >= 3 || col < 0) {
		cout << "Move out of bounds" << endl;
		return false;
	}
	if (board[row][col] != 0) {
		cout << "Spot taken" << endl;
		return false;
	}
	return true;
}

int Board::addMove(int player, int row, int col) {
	board[row][col] = player;
	return player;
}

void Board::nextTurn( void ) {
	if (turn == 1) {
		turn = 2;
	}
	else {
		turn = 1;
	}
}

int Board::getTurn( void ) {
	return turn;
}

GameBoard Board::getBoard( void ) {
	return board;
}

np::ndarray Board::getBoardnp( void ) {
	vector<int> resvec(flatten(board));
	// cout << "resvec vector has size: " << resvec.size() << endl;
	int* data = &resvec[0];

	// np::dtype dt = np::dtype::get_builtin<int>();
	// p::tuple shape = p::make_tuple(9);
	// p::tuple stride = p::make_tuple(9);
	// p::object own;
	// np::ndarray data_np = np::from_data(data,dt,shape,stride,own);

	p::tuple outshape = p::make_tuple(3, 3);
	// np::dtype dtype = np::dtype::get_builtin<int>();
	// np::ndarray a =  np::zeros(shape, dtype);


	Py_intptr_t shape[1] = { static_cast<Py_intptr_t>(resvec.size()) };
	np::ndarray resnp = np::zeros(1, shape, np::dtype::get_builtin<double>());
	copy(resvec.begin(), resvec.end(), reinterpret_cast<double*>(resnp.get_data()));
	
	return resnp.reshape(outshape);
	// return a;
}

bool Board::isBoardFull( void ) {
	bool isFull = true;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 0) {
				isFull = false;
			}
		}
	}

	return isFull;
}

int Board::whoWon( void ) {
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
		if (board[0][0] != 0) {
			return board[0][0];
		}
	}

	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
		if (board[1][0] != 0) {
			return board[1][0];
		}
	}

	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
		if (board[2][0] != 0) {
			return board[2][0];
		}
	}

	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
		if (board[0][0] != 0) {
			return board[0][0];
		}
	}

	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
		if (board[0][1] != 0) {
			return board[0][1];
		}
	}

	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
		if (board[0][2] != 0) {
			return board[0][2];
		}
	}

	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if (board[0][0] != 0) {
			return board[0][0];
		}
	}

	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if (board[0][2] != 0) {
			return board[0][2];
		}
	}

	return 0;
}

void Board::printBoard( void ) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

