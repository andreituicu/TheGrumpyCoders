#include "stdafx.h"
#include "AbstractChessPiece.h"

using namespace std;

class KnightPiece : AbstractChessPiece {
public:
	KnightPiece(int color, int x, int y, int vectorPosition);
	~KnightPiece();
};