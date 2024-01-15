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
		goto STOPWASTINGMYTIME;
	}

	if (willX > 7 || willX < 0 || willY > 7 || willY < 0)
	{
		isLegal = false;
		goto STOPWASTINGMYTIME;
	}

	if (abs(wasX - willX) > 1)
	{
		isLegal = false;
		goto STOPWASTINGMYTIME;
	}

	if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour || board1[willX][willY][0] == whoToMoveC)
	{
		isLegal = false;
		goto STOPWASTINGMYTIME;
	}
	if(willX == wasX && willY == wasY)
	{
		isLegal = false;
		goto STOPWASTINGMYTIME;
	}


	//black
	if (whoToMove)
	{
		if (wasY - willY > 2)
		{
			isLegal = false;
			goto STOPWASTINGMYTIME;
		}
		if (willY - wasY == 1 && wasX == willX)
		{
			if (board1[willX][willY] != "OO" || board1[willX][willY] != "XX")
			{
				isLegal = false;
				moveType = 0;
				goto STOPWASTINGMYTIME;
			}
		}

		if (willY - wasY == 2 && isFirstMove && wasX == willX)
		{
			if (wasX != willX && (board1[wasX][wasY - 2] != "OO" || board1[wasX][wasY - 2] != "XX") && (board1[wasX][wasY - 1] != "OO" || board1[wasX][wasY - 1] != "XX"))
			{
				isLegal = false;
				goto STOPWASTINGMYTIME;
			}
			moveType = 0;
		}
		if (willY - wasY == 2 && isFirstMove == false)
		{
			isLegal = false;
			goto STOPWASTINGMYTIME;
		}
		if (willY - wasY == -2 && wasX != willX)
		{
			isLegal = false;
			goto STOPWASTINGMYTIME;
		}
	
		if (wasX != willX && willY - wasY == -1)
		{
			if (board1[willX][willY][0] == 'X' || board1[willX][willY][0] == 'O')
			{
				isLegal = false;
				goto STOPWASTINGMYTIME;
			}
		}
	}
	//white
	else
	{
		if (willY - wasY > 2)
		{
			isLegal = false;
			goto STOPWASTINGMYTIME;
		}
		if (willY - wasY == 1 && wasX == willX)
		{
			if (board1[willX][willY] != "OO" || board1[willX][willY] != "XX")
			{
				isLegal = false;
				goto STOPWASTINGMYTIME;
			}
			moveType = 0;
		}

		if (willY - wasY == 2 && isFirstMove && wasX == willX)
		{
			if (wasX != willX && (board1[wasX][wasY + 2] != "OO" || board1[wasX][wasY + 2] != "XX") && (board1[wasX][wasY + 1] != "OO" || board1[wasX][wasY + 1] != "XX"))
			{
				isLegal = false;
				goto STOPWASTINGMYTIME;
			}

			moveType = 0;
		}

		if (wasX != willX && willY - wasY == 1)
		{
			if (board1[willX][willY][0] == 'X' || board1[willX][willY][0] == 'O')
			{
				isLegal = false;
				goto STOPWASTINGMYTIME;
			}

		}
		if (willY - wasY == 2 && isFirstMove == false)
		{
			isLegal = false;
			goto STOPWASTINGMYTIME;
		}
		if (willY - wasY == -2 && abs(wasX - willX) != 0)
		{
			isLegal = false;
		}
	}

	STOPWASTINGMYTIME:
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