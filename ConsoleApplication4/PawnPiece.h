#include "stdafx.h"
#include "AbstractChessPiece.h"
#include "ChessBoard.h"
using namespace std;

class PawnPiece : AbstractChessPiece {
public:
	vector<pair<int, int>*>* availableMoves(AbstractChessPiece* currentPosition[10][10]);
	PawnPiece(int color, int x, int y, int vectorPosition);
	~PawnPiece();
};