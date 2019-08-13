//
// Created by Alton Barbehenn (barbehenna) on July 25, 2019
//

#include "Board.h"

#include <iostream>
#include <algorithm> // for std::fill
#include <vector>


using namespace std;


// Constructor
Board::Board( void ) {
	board.resize(3, vector<int>(3));
	fill(board.begin(), board.end(), vector<int>(3, 0));

	turnPlayer = PLAYER_1;
}


// Setters
void Board::setTurnPlayer(int player) {
	turnPlayer = player;
}

void Board::setMove(int move) {
	int row = move / 3;
	int col = move % 3;

	board[row][col] = turnPlayer;
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
	int row = move / 3;
	int col = move % 3;

	if (move < 0 || move > 8) {
		cout << "Move out of bounds" << endl;
		return false;
	}
	if (board[row][col] != 0) {
		cout << "Spot taken" << endl;
		return false;
	}

	return true;
}

void Board::nextTurn( void ) {
	if (turnPlayer == PLAYER_1) {
		setTurnPlayer(PLAYER_2);
	} 
	else {
		setTurnPlayer(PLAYER_1);
	}
}


// Getters

int Board::getTurnPlayer( void ) {
	return turnPlayer;
}

GameBoard Board::getBoard( void ) {
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


// Printers
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
