//
// Created by Alton Barbehenn (barbehenna) on July 25, 2019
//

#ifndef BOARD
#define BOARD 

#include <iostream>
#include <algorithm> // for std::fill
#include <vector>

#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
namespace p = boost::python;
namespace np = boost::python::numpy;


// This class maintains the board state throughout the game.
class Board {
private:
	std::vector<int> board;
	int _player1;
	int _player2;
	int turnPlayer;

	// Hide setters to prevent unchecked changes
	void setTurnPlayer(int player);
	void setMove(int move);

	// Helpers (no need to clutter public space)
	void nextTurn( void );
	bool checkMoveValid(int move);
	np::ndarray vecToNumpy(std::vector<int> input);

public:
	// Constructors
	Board( void );
	Board(int p1, int p2); // set player integers

	// Getters
	int getTurnPlayer( void );
	std::vector<int> getBoard( void );
	std::vector<int> getValidMoves( void );
	bool isBoardFull( void );
	int whoWon( void );

	// Numpy versions of vector getters
	np::ndarray getBoardNumpy( void );
	np::ndarray getValidMovesNumpy( void );

	// public setter
	bool addMove(int move);

	// Printers
	void printBoard( void );
	void printMoveMap( void );
	void printPlayerValues( void );
};


#endif
