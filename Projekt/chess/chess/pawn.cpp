# include "piece.h"

char pawn::typeCharF()
{
	return typeChar = 'P';
}

pawn::pawn(int xC, int yC, bool colourC)
{
	x = xC;
	y = yC;
	colour = colourC;
	if (colourC)
	{
		nameSTR = "BP";
	}
	else
	{
		nameSTR = "WP";
	}
}

bool pawn::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int whichT, bool print)
{
	bool isLegal = true;

	char whoToMoveC;
	if (whoToMove)
		whoToMoveC = 'B';
	else
		whoToMoveC = 'W';

	if (whichT == 99)
	{
		isLegal = false;
	}

	if (willX > 7 || willX < 0 || willY > 7 || willY < 0)
		isLegal = false;


	if (abs(wasX - willX) > 1)
		isLegal = false;

	if (abs(wasY - willY) > 2)
		isLegal = false;

	if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour || board1[willX][willY][0] == whoToMoveC)
	{
		isLegal = false;
	}


	//black
	if (whoToMove)
	{

		if (willY - wasY == 1 && wasX == willX)
		{
			if (wasX != willX && (board1[wasX][wasY - 1] != "OO" ^ board1[wasX][wasY - 1] != "XX"))
			{
				isLegal = false;
				moveType = 0;
			}
		}

		else if (willY - wasY == 2 && isFirstMove && wasX == willX)
		{
			if (wasX != willX && (board1[wasX][wasY - 2] != "OO" ^ board1[wasX][wasY - 2] != "XX") && (board1[wasX][wasY - 1] != "OO" ^ board1[wasX][wasY - 1] != "XX"))
				isLegal = false;
			moveType = 0;
		}
	
		else if (abs(wasX - willX) == 1 && willY - wasY == -1)
		{
			if (board1[willX][willY][0] == 'B' && willY - wasY != -1)
				isLegal = false;
		}
	}
	//white
	else
	{
		if (willY - wasY == 1 && wasX == willX)
		{
			if (wasX != willX && (board1[wasX][wasY + 1] != "OO" ^ board1[wasX][wasY + 1] != "XX"))
				isLegal = false;
			moveType = 0;
		}

		else if (willY - wasY == 2 && isFirstMove && wasX == willX)
		{
			if (wasX != willX && (board1[wasX][wasY + 2] != "OO" ^ board1[wasX][wasY + 2] != "XX") && (board1[wasX][wasY + 1] != "OO" ^ board1[wasX][wasY + 1] != "XX"))
				isLegal = false;
			moveType = 0;
		}

		else if (abs(wasX - willX) == 1 && willY - wasY == 1)
		{
			if (board1[willX][willY][0] == 'W' && willY - wasY != 1)
				isLegal = false;
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

	isFirstMove = false;
}


pawn::~pawn()
{
}