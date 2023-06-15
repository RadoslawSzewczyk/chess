# include "piece.h"

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

bool pawn::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int whichT)
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


	//black
	if (whoToMove)
	{

		if (!((wasY - willY != 1) ^ (isFirstMove && wasY - willY != 2)) || (abs(willX - wasX) == 1 && abs(wasY - willY) == 1))
			isLegal = false;

		if (wasY - willY == 1)
		{
			if (wasX != willX && (board1[wasX][wasY - 1] != "OO" ^ board1[wasX][wasY - 1] != "XX"))
			{
				isLegal = false;
				moveType = 0;
			}
		}

		if (wasY - willY == 2)
		{
			if (wasX != willX && (board1[wasX][wasY - 2] != "OO" ^ board1[wasX][wasY - 2] != "XX") && (board1[wasX][wasY - 1] != "OO" ^ board1[wasX][wasY - 1] != "XX"))
				isLegal = false;
			moveType = 0;
		}

		if ((board1[willX][willY][0] == 'W' || board1[willX][willY][0] == 'W') && (wasX + 1 == willX || wasX - 1 == willX))
		{
			isLegal = true;
			moveType = 1;
		}
	}
	//white
	else
	{
		if (!((willY - wasY != 1) ^ (isFirstMove && willY - wasY != 2)) || (abs(wasX - willX) == 1 && abs(wasY - willY) == 1))
			isLegal = false;

		if (willY - wasY == 1)
		{
			if (wasX != willX && (board1[wasX][wasY + 1] != "OO" ^ board1[wasX][wasY + 1] != "XX"))
				isLegal = false;
			moveType = 0;
		}

		if (willY - wasY == 2)
		{
			if (wasX != willX && (board1[wasX][wasY + 2] != "OO" ^ board1[wasX][wasY + 2] != "XX") && (board1[wasX][wasY + 1] != "OO" ^ board1[wasX][wasY + 1] != "XX"))
				isLegal = false;
			moveType = 0;
		}

		if ((board1[willX][willY][0] == 'B' || board1[willX][willY][0] == 'B') && (wasX + 1 == willX || wasX - 1 == willX))
		{
			isLegal = true;
			moveType = 1;
		}
	}


	if (!isLegal)
	{
		std::cout << "That is illegal move" << std::endl;
		return 1;
	}
	else
		return 0;

	isFirstMove = false;
}

void pawn::move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector<std::shared_ptr<piece>>& pieceTab, int which)
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

pawn::~pawn()
{
}