#include "stdafx.h"
#include "Algorithm.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

int* Algorithm::chooseMove(AbstractChessPiece** pieces, AbstractChessPiece* chessBoard[10][10], int length){
	srand(time(0));
	int* result = new int[4];
	AbstractChessPiece* piece = pieces[0];
	vector<pair<int, int>*>* availableMoves;
	availableMoves = piece->availableMoves(chessBoard);	
	int index;
	/*bool* pawns = new bool[length+1];

	for(int i =0; i<length; i++) {
		pawns[i] = 0;
	}

	bool ok = 1;
	
	do{
		int sum = 0;
		index = rand() % (length + 1);
		pawns[index]= 1;
		piece = pieces[index];	
		availableMoves = piece->availableMoves(chessBoard);	
		for(int i=0; i <length; i++){			
			if(pawns[i]){
				sum++;
			}
		}
		if(sum == length){
			ok = 0;
		}
	} while(availableMoves->size() == 0 || !ok);
	
	delete[] pawns;

	if(!ok && !availableMoves->size()){
		return NULL;
	} */

	if(availableMoves->size() == 0){
		result = NULL;
	} else {
	index = rand() % availableMoves->size();
	pair<int, int>* myMovePair = availableMoves->at(index);

	result[0] = piece->x;
	result[1] = piece->y;
	result[2] = myMovePair->first;
	result[3] = myMovePair->second;

	vector<pair<int, int>*>::iterator i;
	for(i =availableMoves->begin(); i<availableMoves->end(); i++) {
		delete (*i);	
	}
	}
	delete availableMoves;

	return result;
}