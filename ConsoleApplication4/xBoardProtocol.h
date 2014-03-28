#include "ChessBoard.h"
class xBoardProtocol{
private:
	ChessBoard * chessBoard;
public:
	xBoardProtocol();

	~xBoardProtocol();

	void xBoard();

	string execute(char* command);

	int* translateToInts(char* stringMove);
	string translateToString(int* moveInts);



};