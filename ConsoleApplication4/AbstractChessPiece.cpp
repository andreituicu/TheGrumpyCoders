#include "stdafx.h"
#include "AbstractChessPiece.h"

AbstractChessPiece::AbstractChessPiece(int color, int x, int y, int vectorPosition){
	this->vectorPosition = vectorPosition;
	this->color = color;
	this->x = x;
	this->y = y;
}

vector<pair<int, int>*>* AbstractChessPiece::availableMoves(AbstractChessPiece* currentBoard[10][10]){ return NULL;}
vector<pair<int, int>*>* AbstractChessPiece::attackPositions(){ return NULL;}

vector<pair<int, int>*>* AbstractChessPiece::checkPositions(){ return NULL;}

vector<pair<int, int>*>* AbstractChessPiece::checkMatePositions(){ return NULL;}
