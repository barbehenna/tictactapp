//
// Created by Alton Barbehenn (barbehenna) on July 25, 2019
//

#ifndef BOARD
#define BOARD 

#include <iostream>
#include <algorithm> // for std::fill
#include <vector>
#include <boost/python/numpy.hpp>

namespace np = boost::python::numpy;


typedef std::vector<std::vector<int> > GameBoard;


// This class maintains the board state throughout the game.
class Board {
private:
	GameBoard board;
	int turn;

public:
	Board( void );
	bool checkMoveValid(int player, int move);
	int addMove(int player, int move);
	std::vector<int> getValidMoves( void );
	np::ndarray getValidMovesnp( void );
	void nextTurn( void );
	int getTurn( void );
	GameBoard getBoard( void );
	np::ndarray getBoardnp( void );
	int whoWon( void );
	bool isBoardFull( void );
	void printBoard( void );
	void printMoveMap( void );
};


#endif
