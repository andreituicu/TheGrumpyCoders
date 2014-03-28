#include "stdafx.h"

#include "AbstractChessPiece.h"
#include "Algorithm.h"
#include <fstream>
using namespace std;

#ifndef CHESSBOARD
#define CHESSBOARD

class ChessBoard {
public:
	AbstractChessPiece* chessBoard[10][10];
	AbstractChessPiece* whitePieces[16];
	AbstractChessPiece* blackPieces[16];
	Algorithm* algorithm;
	fstream moves;

	int whitePiecesNr;
	int blackPiecesNr;
	int color;
	bool forceMode;

	ChessBoard();
	~ChessBoard();
	void setColor(int);
	void setForceMode(bool);
	void moveOponent(int* moveInts);
	int* moveMy();

	//debug stuff
	void printMatrix();

};

#endif