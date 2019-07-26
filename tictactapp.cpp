//
// Created by Alton Barbehenn (barbehenna) on July 25, 2019
//

#include <iostream>
#include <algorithm> // for std::fill
#include <vector>

using namespace std;

class Board {
private:
	vector<vector<int> > board;
	int turn;

public:
	Board( void );
	bool checkMoveValid(int, int, int);
	int addMove(int, int, int);
	void nextTurn( void );
	int getTurn( void );
	int whoWon( void );
	bool isBoardFull( void );
	void printBoard( void );
};

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


int main( void ) {
	Board boardState; 
	int x = -1;
	int y = -1;

	while (!boardState.isBoardFull() && !boardState.whoWon()) {
		cout << "Player " << boardState.getTurn() << "'s turn:" << endl;
		boardState.printBoard();

		do {
			cin >> x;
			cin >> y;
		} while (!boardState.checkMoveValid(boardState.getTurn(), x, y));

		boardState.addMove(boardState.getTurn(), x, y);

		boardState.nextTurn();
	}

	if (boardState.whoWon() != 0) {
		boardState.nextTurn();
		cout << "Player " << boardState.getTurn() << " won!!" << endl;
	}
	else if (boardState.isBoardFull() != 0) {
		cout << "Stalemate..." << endl;
	}

	cout << "Last board:" << endl;
	boardState.printBoard();

	return 0;
}