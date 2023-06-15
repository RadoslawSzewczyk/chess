# include "piece.h"

bishop::bishop(int xC, int yC, bool colourC)
{
	x = xC;
	y = yC;
	colour = colourC;
	if (colourC)
	{
		nameSTR = "BB";
	}
	else
	{
		nameSTR = "WB";
	}
}

bool isOpponentPiece(const std::string& piece, bool whoToMove) 
{
	if (whoToMove)
	{
		return (piece[0] == 'W');
	}
	else 
	{
		return (piece[0] == 'B'); 
	}
}

bool bishop::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int whichT)
{
	bool isLegal = true;

	if (whichT == 99)
	{
		isLegal = false;
	}

	if (willX > 8 || willX < 1 || willY > 8 || willY < 1)
		isLegal = false;

	if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour)
		isLegal = false;

	std::string targetPiece = board1[willX][willY];
	char temp = 'W';
	if (pieceColour == 1)
		temp = 'B';

	if (!(targetPiece == "OO" || targetPiece == "XX" || targetPiece[0] != temp))
	{
		isLegal = false;
	}


	if (abs(wasX - willX) != abs(wasY - willY)) {
		isLegal = false;
	}


	int dx = (willX > wasX) ? 1 : -1;
	int dy = (willY > wasY) ? 1 : -1;
	int x = wasX + dx;
	int y = wasY + dy;
	while (x != willX && y != willY) {
		if (board1[x][y] == "OO" || board1[x][y] == "XX") {
			isLegal = true;
		}
		else
			isLegal = false;
		x += dx;
		y += dy;
	}


	if (!isLegal)
	{
		std::cout << "That is illegal move" << std::endl;
		return 1;
	}
	else
		return 0;

}

void bishop::move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector<std::shared_ptr<piece>>& pieceTab, int which)
{
	if (moveType == 0)
	{
		pieceTab[which]->x = willX;
		pieceTab[which]->y = willY;
	}
	else if (moveType == 1)
	{
		int t;
		for (int i = 0; i < pieceTab.size(); i++)
		{
			if (pieceTab[i]->x == willX && pieceTab[i]->y == willY)
				t = i;
		}
		pieceTab[which]->x = willX;
		pieceTab[which]->y = willY;
		pieceTab.erase(next(begin(pieceTab), +t));
	}
}

bishop::~bishop()
{
}
