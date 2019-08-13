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

bool Board::checkMoveValid(int player, int move) {
	int row = move / 3;
	int col = move % 3;

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

int Board::addMove(int player, int move) {
	int row = move / 3;
	int col = move % 3;

	board[row][col] = player;
	return player;
}

void Board::nextTurn( void ) {
	if (turn == 1) {
		turn = -1;
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

// Slightly round-about way to copy game board into numpy array:
// flatten -> copy -> reshape 
np::ndarray Board::getBoardnp( void ) {
	// apparently vectors are stored in sequential memory like arrays now
	// flatten board 
	vector<int> resvec(flatten(board));
	int* data = &resvec[0];

	// copy board into numpy array
	Py_intptr_t shape[1] = { static_cast<Py_intptr_t>(resvec.size()) };
	np::ndarray resnp = np::zeros(1, shape, np::dtype::get_builtin<int>());
	copy(resvec.begin(), resvec.end(), reinterpret_cast<int*>(resnp.get_data()));
	
	// reshape numpy array
	p::tuple outshape = p::make_tuple(3, 3);
	return resnp.reshape(outshape);
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
	cout << "----------------" << endl;
	for (int i = 0; i < board.size(); i++) {
		cout << "|";
		for (int j = 0; j < board[i].size(); j++) {
			printf("%3d |", board[i][j]);
		}
		cout << endl;
		cout << "----------------" << endl;
	}
}

void Board::printMoveMap( void ) {
	cout << "Here are the possible move entries:" << endl;

	cout << "----------------" << endl;
	cout << "|  0 |  1 |  2 |" << endl;
	cout << "----------------" << endl;
	cout << "|  3 |  4 |  5 |" << endl;
	cout << "----------------" << endl;
	cout << "|  6 |  7 |  8 |" << endl;
	cout << "----------------" << endl;
	
	cout << "Good luck!" << endl;
}

