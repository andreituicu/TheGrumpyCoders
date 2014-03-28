#include "stdafx.h"
#include "AbstractChessPiece.h"

using namespace std;

class BishopPiece : AbstractChessPiece {
public:
	BishopPiece(int color, int x, int y, int vectorPosition);
	~BishopPiece();
};