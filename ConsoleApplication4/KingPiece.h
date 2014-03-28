#include "stdafx.h"
#include "AbstractChessPiece.h"

using namespace std;

class KingPiece : AbstractChessPiece {
public:
	KingPiece(int color, int x, int y, int vectorPosition);
	~KingPiece();
};