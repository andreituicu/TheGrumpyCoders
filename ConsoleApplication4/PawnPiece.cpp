#include "stdafx.h"
#include "AbstractChessPiece.h"
#include "PawnPiece.h"
#include "iostream"
#include "Colors.h"
using namespace std;
PawnPiece:: PawnPiece(int color, int x, int y, int vectorPosition) : AbstractChessPiece(color, x, y, vectorPosition){
}

vector<pair<int, int>*>* PawnPiece::availableMoves(AbstractChessPiece* currentBoard[10][10]){
	vector< pair<int, int>* >* result = new vector<pair<int, int>*>();
	int i = this->x,
		j = this->y;

	if(this->color == BLACK){
		if(!currentBoard[i-1][j]){
			result->push_back(new pair<int, int>(i-1,j));
		}

		if(currentBoard[i-1][j-1] && currentBoard[i-1][j-1] != (AbstractChessPiece* )1 && currentBoard[i-1][j-1]->color != this->color ){
			result->push_back(new pair<int, int>(i-1,j-1));
		}
		if(currentBoard[i-1][j+1] && currentBoard[i-1][j+1] != (AbstractChessPiece* )1 && currentBoard[i-1][j+1]->color != this->color ){
			result->push_back(new pair<int, int>(i-1, j+1));
		}

		if(i==7 && !currentBoard[i-2][j]){
			result->push_back(new pair<int, int>(i-2, j));
		}
	}
	else {
		if(!currentBoard[i+1][j]){
			result->push_back(new pair<int, int>(i+1,j));
		}

		if(currentBoard[i+1][j-1] && currentBoard[i+1][j-1] != (AbstractChessPiece* )1 && currentBoard[i+1][j-1]->color != this->color ){
			result->push_back(new pair<int, int>(i+1,j-1));
		}
		if(currentBoard[i+1][j+1] && currentBoard[i-1][j+1] != (AbstractChessPiece* )1 && currentBoard[i+1][j+1]->color != this->color ){
			result->push_back(new pair<int, int>(i+1, j+1));
		}

		if(i==2 && !currentBoard[i+2][j]){
			result->push_back(new pair<int, int>(i+2, j));
		}

	}
	return result;
}

PawnPiece:: ~PawnPiece(){
}