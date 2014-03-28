#include "stdafx.h"
#include "AbstractChessPiece.h"

using namespace std;

class QueenPiece : AbstractChessPiece {
public:
	QueenPiece(int color, int x, int y, int vectorPosition);
	~QueenPiece();
};