//
// Created by Alton Barbehenn (barbehenna) on July 25, 2019
//

#include "Board/Board.h"
#include <iostream>

using namespace std;


int main( void ) {
	Board boardState; 
	int move=10;

	boardState.printMoveMap();

	while (!boardState.isBoardFull() && !boardState.whoWon()) {
		cout << "Player " << boardState.getTurnPlayer() << "'s turn:" << endl;
		boardState.printBoard();

		do {
			cin >> move;
		} while (!boardState.addMove(move));
	}

	if (boardState.whoWon() != 0) {
		cout << "Player " << boardState.whoWon() << " won!!" << endl;
	}
	else if (boardState.isBoardFull()) {
		cout << "Stalemate..." << endl;
	}
	else {
		cout << "ERROR: uncaught win condition" << endl;
	}

	cout << "Last board:" << endl;
	boardState.printBoard();

	return 0;
}
