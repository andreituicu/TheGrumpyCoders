#include "stdafx.h"
#include "xBoardProtocol.h"
#include "fstream"
#include "regex"
#include "iostream"

#define XBOARD "xboard"
#define NEW_COMMAND "new"
#define FORCE "force"
#define GO "go"
#define WHITE "white"
#define BLACK "black"
#define QUIT "quit"
#define RESIGN "resign"
#define MOVE "move"

using namespace std;
xBoardProtocol::xBoardProtocol(){
	chessBoard = new ChessBoard();
}

xBoardProtocol::~xBoardProtocol(){
}

void xBoardProtocol::xBoard(){
	
}

int* xBoardProtocol::translateToInts(char* move){

	int* result = new int[4];
	int startX = move[1] - '0';
	int startY = move[0] - 'a' + 1;
	int endX = move[3] - '0';
	int endY = move[2] - 'a' + 1;

	result[0] = startX;
	result[1] = startY;
	result[2] = endX;
	result[3] = endY;
	return result;
}

string xBoardProtocol::translateToString(int* moveInts){
	char* result = new char[6];

	result[0] = moveInts[1] + 'a' - 1;
	result[1] = moveInts[0] + '0';
	result[2] = moveInts[3] + 'a' - 1;
	result[3] = moveInts[2] + '0';
	result[4] = '\n';
	result[5] = '\0';

	string superResult;
	superResult.assign(result);
	return superResult;
}

string xBoardProtocol::execute(char* command){
	if(strstr(command, XBOARD)) {
		// Engine-ul recunoaste ca s-a conectat la winboard. 
		// Initializarile se fac cand este primit new.
	}
	if(strstr(command, NEW_COMMAND)){

		chessBoard = new ChessBoard();
		chessBoard->setColor(1);
	}
	if(strstr(command, FORCE)){
		chessBoard->setForceMode(true);
	}
	if(strstr(command, GO)){
		chessBoard->setForceMode(false);
	}
	if(strstr(command, WHITE)){
		chessBoard->setColor(0);
	}
	if(strstr(command, BLACK)){
		chessBoard->setColor(1);
	}
	if(strstr(command, QUIT)){
		delete chessBoard;
		return "quit";
	}
	if(strstr(command,"Illegal move")) {
		delete chessBoard;
		return "resign";
	}

	std::tr1::cmatch res;
		std::tr1::regex rx("[a-i]{1}[1-9]{1}[a-i]{1}[1-9]{1}");
		string cmd;
		cmd.assign(command);
		std::tr1::regex_search(cmd.c_str(), res, rx);

	if ( std::regex_match ( cmd.begin(), cmd.end(), rx ) )	{		
		int* moveInts = translateToInts(command);		
		chessBoard->moveOponent(moveInts);	
		

		int* myMoveInts = chessBoard->moveMy();
		if(myMoveInts == NULL){
			return "resign";
		}
		string result;
		
		result =  this->translateToString(myMoveInts);
		delete[] moveInts;
		delete[] myMoveInts;
		return result;
	}

	return "";
}