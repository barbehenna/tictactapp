//
// Created by Alton Barbehenn (barbehenna) on July 25, 2019
//

#include "Board.h"

#include <iostream>
#include <algorithm> // for std::fill
#include <vector>


using namespace std;


// Constructors
Board::Board( void ) {
	board.resize(9);
	fill(board.begin(), board.end(), 0);

	_player1 = 1;
	_player2 = -1;
	turnPlayer = _player1;
}

Board::Board(int p1, int p2) {
	board.resize(9);
	fill(board.begin(), board.end(), 0);

	if (p1 != p2 && p1 != 0 && p2 != 0) {
		_player1 = p1;
		_player2 = p2;		
	}
	else {
		_player1 = 1;
		_player2 = -1;
	}

	turnPlayer = _player1;
}


// Setters
void Board::setTurnPlayer(int player) {
	turnPlayer = player;
}

void Board::setMove(int move) {
	board[move] = turnPlayer;
}

bool Board::addMove(int move) {
	// check move
	if (!checkMoveValid(move)) {
		return false;
	}
	else {
		// Set move and then change turn
		setMove(move);
		nextTurn();
		return true;
	}
}


// Helpers
bool Board::checkMoveValid(int move) {
	if (move < 0 || move > 8) {
		cout << "Move out of bounds" << endl;
		return false;
	}
	if (board[move] != 0) {
		cout << "Spot taken" << endl;
		return false;
	}

	return true;
}

void Board::nextTurn( void ) {
	if (turnPlayer == _player1) {
		setTurnPlayer(_player2);
	} 
	else {
		setTurnPlayer(_player1);
	}
}


// Getters

int Board::getTurnPlayer( void ) {
	return turnPlayer;
}

vector<int> Board::getBoard( void ) {
	return board;
}

vector<int> Board::getValidMoves( void ) {
	vector<int> validMoves;

	for (int i = 0; i < 9; i++) {
		if (checkMoveValid(i)) {
			validMoves.push_back(i);
		}
	}

	return validMoves;
}


// Food for Thought: rewrite to get valid moves, then see if the length is 0
bool Board::isBoardFull( void ) {
	bool isFull = true;

	for (int i = 0; i < 9; i++) {
		if (board[i] == 0) {
			isFull = false;
		}
	}

	return isFull;
}

int Board::whoWon( void ) {
	// Rows
	// Top
	if (board[0] == board[1] && board[1] == board[2] && board[2] != 0) {
		return board[0];
	}
	// Middle
	if (board[3] == board[4] && board[4] == board[5] && board[5] != 0) {
		return board[3];
	}
	// Bottom
	if (board[6] == board[7] && board[7] == board[8] && board[8] != 0) {
		return board[8];
	}

	// Columns
	// Left
	if (board[0] == board[3] && board[3] == board[6] && board[6] != 0) {
		return board[6];
	}
	// Middle
	if (board[1] == board[4] && board[4] == board[7] && board[7] != 0) {
		return board[7];
	}
	// Right
	if (board[2] == board[5] && board[5] == board[8] && board[8] != 0) {
		return board[8];
	}

	// Diagonals
	// major
	if (board[0] == board[4] && board[4] == board[8] && board[8] != 0) {
		return board[8];
	}
	// minor 
	if (board[6] == board[4] && board[4] == board[2] && board[2] != 0) {
		return board[2];
	}

	return 0;
}


// Printers
void Board::printBoard( void ) {
	cout << "----------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "|";
		for (int j = 0; j < 3; j++) {
			printf("%3d |", board[3*i + j]);
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
