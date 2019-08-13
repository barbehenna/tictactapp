//
// Created by Alton Barbehenn (barbehenna) on July 25, 2019
//

#ifndef BOARD
#define BOARD 

// int used for each player. 
// pick any pair of ints so long as their different and not zero
#define PLAYER_1 1
#define PLAYER_2 -1

#include <iostream>
#include <algorithm> // for std::fill
#include <vector>


typedef std::vector<std::vector<int> > GameBoard;


// Helper function
// Converts 2d vectors to 1d vectors 
// Found on Stack Overflow
template<typename T>
std::vector<T> flatten(const std::vector<std::vector<T>> &orig) {
	std::vector<T> ret;
	for(const auto &v: orig)
		ret.insert(ret.end(), v.begin(), v.end());
	return ret;
} 


// This class maintains the board state throughout the game.
class Board {
private:
	GameBoard board;
	int turnPlayer;

	// Hide setters to prevent unchecked changes
	void setTurnPlayer(int player);
	void setMove(int move);

	// Helpers (no need to clutter public space)
	void nextTurn( void );
	bool checkMoveValid(int move);

public:
	// Constructor
	Board( void );

	// Getters
	int getTurnPlayer( void );
	GameBoard getBoard( void );
	std::vector<int> getValidMoves( void );
	bool isBoardFull( void );
	int whoWon( void );

	// public setter
	bool addMove(int move);

	// Printers
	void printBoard( void );
	void printMoveMap( void );
	void printPlayerValues( void );
};


#endif
