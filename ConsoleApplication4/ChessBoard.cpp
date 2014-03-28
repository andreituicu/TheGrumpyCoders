#include "stdafx.h"
#include "ChessBoard.h"
#include "iostream"
#include "RookPiece.h"
#include "KingPiece.h"
#include "QueenPiece.h"
#include "PawnPiece.h"
#include "BishopPiece.h"
#include "KnightPiece.h"
#include "Algorithm.h"
#include "Colors.h"

using namespace std;
	ChessBoard::ChessBoard() {

		//comment after debug
		//moves.open("moves.txt", ios_base::out);
		//moves.clear();
		//

		for(int i =0; i<=9; i++){
			for(int j=0; j<=9; j++){
				chessBoard[i][j]=NULL;					
			}
		}

		algorithm = new Algorithm();
		for(int i = 0; i <=9; i++){
			chessBoard[0][i] = (AbstractChessPiece *) 1;
			chessBoard[9][i] = (AbstractChessPiece *) 1;
			chessBoard[i][0] = (AbstractChessPiece *) 1;
			chessBoard[i][9] = (AbstractChessPiece *) 1;
		}

		

		chessBoard[1][1] =(AbstractChessPiece*)  (new RookPiece( WHITE ,  1,1, 8));
		chessBoard[1][2] =(AbstractChessPiece*)  (new KnightPiece( WHITE ,  1, 2, 9));
		chessBoard[1][3] =(AbstractChessPiece*)  (new BishopPiece( WHITE ,  1, 3, 10));
		chessBoard[1][4] =(AbstractChessPiece*)  (new KingPiece( WHITE ,  1, 4, 11));
		chessBoard[1][5] =(AbstractChessPiece*)  (new QueenPiece( WHITE ,  1, 5, 12));
		chessBoard[1][6] =(AbstractChessPiece*)  (new BishopPiece( WHITE ,  1, 6, 13));
		chessBoard[1][7] =(AbstractChessPiece*)  (new KnightPiece( WHITE ,  1, 7, 14));
		chessBoard[1][8] =(AbstractChessPiece*)  (new RookPiece( WHITE ,  1, 8, 15));

		chessBoard[8][1] =(AbstractChessPiece*)  (new RookPiece(BLACK,  8, 1, 8));
		chessBoard[8][2] =(AbstractChessPiece*)  (new KnightPiece(BLACK,  8, 2, 9));
		chessBoard[8][3] =(AbstractChessPiece*)  (new BishopPiece(BLACK,  8, 3, 10));
		chessBoard[8][4] =(AbstractChessPiece*)  (new KingPiece(BLACK,  8, 4, 11));
		chessBoard[8][5] =(AbstractChessPiece*)  (new QueenPiece(BLACK,  8, 5, 12));
		chessBoard[8][6] =(AbstractChessPiece*)  (new BishopPiece(BLACK,  8, 6, 13));
		chessBoard[8][7] =(AbstractChessPiece*)  (new KnightPiece(BLACK,  8, 7, 14));
		chessBoard[8][8] =(AbstractChessPiece*)  (new RookPiece(BLACK,  8, 8, 15));
		
		for(int i=1; i <=8; i++){
				chessBoard[2][i] = (AbstractChessPiece*)  (new PawnPiece( WHITE ,  2, i, i-1));
				whitePieces[i-1] = chessBoard[2][i];

				chessBoard[7][i] = (AbstractChessPiece*)  (new PawnPiece(BLACK,  7, i, i-1));
				blackPieces[i-1] = chessBoard[7][i];
	

		}
		blackPiecesNr = 7;
		whitePiecesNr = 7;
		this->color = BLACK;

	}

	void ChessBoard::setColor(int color) {
		this->color = color;
	}
	
	void ChessBoard::setForceMode(bool set) {
		this->forceMode= set;
	}

	void ChessBoard::moveOponent(int* moveInts){
		AbstractChessPiece* piece;
		//comment after debug
		//moves<<"Oponent moves:"<<endl;
		//this->printMatrix();
		//

		if(this->color == BLACK){
			//if he takes my piece
			if( (piece = chessBoard[moveInts[2]][moveInts[3]]) ){
				//swap the removed piece with the last one
				blackPieces[blackPiecesNr]->vectorPosition = piece->vectorPosition;
				blackPieces[piece->vectorPosition] = blackPieces[blackPiecesNr];
				blackPieces[blackPiecesNr]=NULL;
				blackPiecesNr--;
			}
			
			piece = chessBoard[moveInts[0]][moveInts[1]];
			piece->x = moveInts[2];
			piece->y = moveInts[3];
			chessBoard[moveInts[2]][moveInts[3]]=chessBoard[moveInts[0]][moveInts[1]];
			chessBoard[moveInts[0]][moveInts[1]]=NULL;
		
			
		}
		else if(this->color == WHITE){
			if( (piece = chessBoard[moveInts[2]][moveInts[3]]) ){
				//swap the removed piece with the last one
				whitePieces[blackPiecesNr]->vectorPosition = piece->vectorPosition;
				whitePieces[piece->vectorPosition] = whitePieces[whitePiecesNr];
				whitePieces[whitePiecesNr]=NULL;
				whitePiecesNr--;
			}
			/*cout<<"Here2"<<endl;*/
			piece = chessBoard[moveInts[0]][moveInts[1]];
			piece->x = moveInts[2];
			piece->y = moveInts[3];
			chessBoard[moveInts[2]][moveInts[3]]=chessBoard[moveInts[0]][moveInts[1]];
			chessBoard[moveInts[0]][moveInts[1]]=NULL;
		}
		else{
			//TODO
		}

			//comment after debug
			//this->printMatrix();
			//
	}

	int* ChessBoard::moveMy(){
		AbstractChessPiece* piece;
		
		//comment after debug
		//moves<<"My move:"<<endl;		
		//this->printMatrix();
		//

		int* moveInts = NULL;
	
		if(this->color == BLACK){
			moveInts = algorithm->chooseMove(blackPieces, chessBoard, blackPiecesNr);
			if(moveInts == NULL){
				return NULL;
			}
			
			if((piece = chessBoard[moveInts[2]][moveInts[3]])){
				//swap the removed piece with the last one
				whitePieces[piece->vectorPosition] = whitePieces[whitePiecesNr];
				whitePieces[whitePiecesNr]=NULL;
				whitePiecesNr--;
			}

			piece = chessBoard[moveInts[0]][moveInts[1]];
			piece->x = moveInts[2];
			piece->y = moveInts[3];
			chessBoard[moveInts[2]][moveInts[3]]=chessBoard[moveInts[0]][moveInts[1]];
			chessBoard[moveInts[0]][moveInts[1]]=NULL;
		}
		else if (this->color == WHITE){
			moveInts = algorithm->chooseMove(whitePieces, chessBoard, whitePiecesNr);
			if(moveInts == NULL){
				return NULL;
			}

			if( (piece = chessBoard[moveInts[2]][moveInts[3]]) ){
				//swap the removed piece with the last one
				blackPieces[piece->vectorPosition] = blackPieces[blackPiecesNr];
				blackPieces[blackPiecesNr]=NULL;
				blackPiecesNr--;
			}

			piece = chessBoard[moveInts[0]][moveInts[1]];
			piece->x = moveInts[2];
			piece->y = moveInts[3];
			chessBoard[moveInts[2]][moveInts[3]]=chessBoard[moveInts[0]][moveInts[1]];
			chessBoard[moveInts[0]][moveInts[1]]=NULL;
		}
		else{
			//TODO
		}
			//comment after debugg
			//this->printMatrix();
			//
		
		return moveInts;
	}

	void ChessBoard::printMatrix(){
		for(int i = 9; i >=0; i--) { 
			for(int j=0; j <=9; j++){
				if(chessBoard[i][j] != NULL){
					moves<<"1"<<" ";
				}
				else {
					moves<<"0"<<" ";
				}
			}
			moves<<endl;
		}
		moves<<endl<<endl;
		moves.flush();
	}

	ChessBoard::~ChessBoard() {
		for(int i = 1; i <= 8; i++){
			for(int j =1; j<=8; j++){
				if(chessBoard[i][j]){
					delete chessBoard[i][j];
				}
			}
		}

		delete algorithm;
		moves.close();
	}