# include "piece.h"


rook::rook(int xC, int yC, bool colourC)
{
	x = xC;
	y = yC;
	colour = colourC;
	if (colourC)
	{
		nameSTR = "BR";
	}
	else
	{
		nameSTR = "WR";
	}
}

bool rook::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int whichT)
{
	bool isLegal = true;


	if (whichT == 99)
		isLegal = false;

	if (willX > 8 || willX < 1 || willY > 8 || willY < 1)
		isLegal = false;

	if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour)
		isLegal = false;


	std::string targetPiece = board1[willX][willY];

	if (targetPiece != "OO" && targetPiece != "XX" && (pieceColour == (targetPiece[0] == 'W'))) {
		isLegal = false;
	}

	if (wasX != willX && wasY != willY) {
		isLegal = false;
	}

	if (wasX == willX) {

		int start = std::min(wasY, willY) + 1;
		int end = std::max(wasY, willY);
		for (int y = start; y < end; ++y) {
			if (board1[wasX][y] != "OO" && board1[wasX][y] != "XX") {
				isLegal = false;
			}
		}
	}
	else {

		int start = std::min(wasX, willX) + 1;
		int end = std::max(wasX, willX);
		for (int x = start; x < end; ++x) {
			if (board1[x][wasY] != "OO" && board1[x][wasY] != "XX") {
				isLegal = false;
			}
		}
	}


	if (!isLegal)
	{
		std::cout << "That is illegal move" << std::endl;
		return 1;
	}
	else
		return 0;
}

void rook::move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector<std::shared_ptr<piece>>& pieceTab, int which)
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

rook::~rook()
{
}
