#include "stdafx.h"
#include "string"
#include "vector"

#ifndef ABSTRACTPIECE
#define ABSTRACTPIECE
using namespace std;
class AbstractChessPiece
{
public:
	int color;
	string name;
	
	int y, // litera coloana
		x, // cifra linie
		vectorPosition; // 
	
	AbstractChessPiece(int color, int y, int x, int vectorPosition);

	virtual vector<pair<int, int>*>* availableMoves(AbstractChessPiece* currentBoard[10][10]);

	virtual vector<pair<int, int>*>* attackPositions();

	virtual vector<pair<int, int>*>* checkPositions();

	virtual vector<pair<int, int>*>* checkMatePositions();


};
#endif
