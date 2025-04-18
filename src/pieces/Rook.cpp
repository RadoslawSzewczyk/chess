# include "Piece.hpp"


char Rook::typeCharF()
{
	return typeChar = 'R';
}

Rook::Rook(int xC, int yC, bool colourC)
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

bool Rook::validateMove(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, std::string board1[8][8], int whichT, bool print)
{
	char whoToMoveC;
	if (whoToMove)
		whoToMoveC = 'B';
	else
		whoToMoveC = 'W';
	bool isLegal = true;


	if (whichT == 99)
		isLegal = false;
	if (willX > 7 || willX < 0 || willY > 7 || willY < 0)
		isLegal = false;


	if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour || board1[willX][willY][0] == whoToMoveC)
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
		if (print)
		{
			std::cout << "That is illegal move" << std::endl;
		}
		return 1;
	}
	else
		return 0;
}

Rook::~Rook()
{
}
