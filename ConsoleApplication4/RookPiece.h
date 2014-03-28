#include "stdafx.h"
#include "AbstractChessPiece.h"

using namespace std;

class RookPiece : AbstractChessPiece {
public:
	RookPiece(int color, int x, int y, int vectorPosition);
	~RookPiece();
};