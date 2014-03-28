#include "stdafx.h"
#include "AbstractChessPiece.h"

#ifndef ALGORITHM
#define ALGORITHM
class Algorithm{
public:
	int* chooseMove(AbstractChessPiece** pieces, AbstractChessPiece* chessBoard[10][10], int length);


};
#endif
