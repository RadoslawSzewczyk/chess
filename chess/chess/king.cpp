# include "piece.h"


char king::typeCharF()
{
    return typeChar = 'K';
}

king::king(int xC, int yC, bool colourC)
{
	x = xC;
	y = yC;
	colour = colourC;
	if (colourC)
	{
		nameSTR = "BK";
	}
	else
	{
		nameSTR = "WK";
	}
}


bool king::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which, bool print)
{
	char whoToMoveC;
	if (whoToMove)
		whoToMoveC = 'B';
	else
		whoToMoveC = 'W';
	bool isLegal = true;
	if (willX > 7 || willX < 0 || willY > 7 || willY < 0)
		isLegal = false;

	std::string targetPiece = board1[willX][willY];
	if (targetPiece != "OO" && targetPiece != "XX" || board1[willX][willY][0] == whoToMoveC) {
		isLegal = false;
	}

	int dx = abs(wasX - willX);
	int dy = abs(wasY - willY);

	if (!((dx == 1 && dy == 0) || (dx == 0 && dy == 1) || (dx == 1 && dy == 1)))
		isLegal = false;

	if (!isLegal)
	{
		if (print)
		{
			std::cout << "That is illegal move" << std::endl;
		}
		return 1;
	}
	else
		return 0;
}


king::~king(){}