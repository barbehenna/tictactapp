//
// Created by Alton Barbehenn (barbehenna) on July 25, 2019
//

#include "Board/Board.h"
#include <iostream>

using namespace std;


int main( void ) {
	Board boardState; 
	int move = -1;

	boardState.printMoveMap();

	while (!boardState.isBoardFull() && !boardState.whoWon()) {
		cout << "Player " << boardState.getTurn() << "'s turn:" << endl;
		boardState.printBoard();

		do {
			cin >> move;
		} while (!boardState.checkMoveValid(boardState.getTurn(), move));

		boardState.addMove(boardState.getTurn(), move);

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
