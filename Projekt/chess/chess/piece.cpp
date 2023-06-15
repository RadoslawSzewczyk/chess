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

int pawn::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8])
{
	bool isLegal = false;

	if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour)
		isLegal = false;

	////black
	//if (whoToMove)
	//{

	//	if (!(wasY - willY != 1 ^ (isFirstMove && wasY - willY != 2)) || (abs(wasX - willX) == 1 && abs(wasY + willY) == 1))
	//		isLegal = false;

	//	if (wasY - willY == 1)
	//	{
	//		if (wasX != willX && (board1[wasX][wasY - 1] != "OO" ^ board1[wasX][wasY - 1] != "XX"))
	//			isLegal = false;
	//		moveType = 0;
	//	}

	//	if (willY - wasY == 2)
	//	{
	//		if (wasX != willX && (board1[wasX][wasY - 2] != "OO" ^ board1[wasX][wasY - 2] != "XX") && (board1[wasX][wasY - 1] != "OO" ^ board1[wasX][wasY - 1] != "XX"))
	//			isLegal = false;
	//		moveType = 0;
	//	}

	//	if (abs(wasX - willX) == 1)
	//	{
	//		if (board1[wasX + 1][wasY - 1][0] != 'W' || board1[wasX - 1][wasY - 1][0] != 'W')
	//			isLegal = false;
	//		moveType = 1;
	//	}
	//}
	////white
	//else
	//{
	//	if (!((willY - wasY != 1) ^ (isFirstMove && willY - wasY != 2)) || (abs(wasX - willX) == 1 && abs(wasY - willY) == 1))
	//		isLegal = false;

	//	if (willY - wasY == 1)
	//	{
	//		if (wasX != willX && (board1[wasX][wasY + 1] != "OO" ^ board1[wasX][wasY + 1] != "XX"))
	//			isLegal = false;
	//		moveType = 0;
	//	}

	//	if (willY - wasY == 2)
	//	{
	//		if (wasX != willX && (board1[wasX][wasY + 2] != "OO" ^ board1[wasX][wasY + 2] != "XX") && (board1[wasX][wasY + 1] != "OO" ^ board1[wasX][wasY + 1] != "XX"))
	//			isLegal = false;
	//		moveType = 0;
	//	}

	//	if ((board1[willX][willY][0] != 'B' || board1[willX][willY][0] != 'B') && (wasX + 1 == willX || wasX - 1 == willX))
	//		isLegal = false;
	//	moveType = 1;
	//	
	//}


if (moveType == 0) {
		if (pieceColour == 0) {
			if (wasY == 1 && willY == 3 && (board1[willX][willY] == "XX" || board1[willX][willY] == "OO"))
			{
				isLegal =true;
			}
			else if (willY - wasY == 1 && abs(willX - wasX) == 1 && (board1[willX][willY] == "XX" || board1[willX][willY] == "OO")) {
				isLegal= true;
			}
			else if (willY - wasY == 1 && willX == wasX && (board1[willX][willY] == "XX" || board1[willX][willY] == "OO")) {
				isLegal= true;
			}
		}
		else {
			if (wasY == 6 && willY == 4 && (board1[willX][willY] == "XX" || board1[willX][willY] == "OO")) {
				isLegal= true;
			}
			else if (wasY - willY == 1 && abs(willX - wasX) == 1 && (board1[willX][willY] == "XX" || board1[willX][willY] == "OO")) {

				isLegal= true;
			}
			else if (wasY - willY == 1 && willX == wasX && (board1[willX][willY] == "XX" || board1[willX][willY] == "OO")) {
				isLegal= true;
			}
		}
	}
	else if (moveType == 1) {
		if (pieceColour == 0) {
			if (board1[willX + 1][willY + 1][0] == 'B') 
			{
				isLegal = true;
			}
			else if (board1[willX - 1][willY + 1][0] == 'B') 
			{
				isLegal = true;
			}
			isLegal = true;
		}
		else {
			if (board1[willX + 1][willY - 1][0] == 'W') {
				isLegal = true;
			}
			else if (board1[willX - 1][willY - 1][0] == 'W') {
				isLegal = true;
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
//int king::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8])
//{
//	bool isLegal = true;
//
//	if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour)
//		isLegal = false;
//	if (whoToMove)
//	{
//		return 0;
//	}
//	return 1;
//}

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

int bishop::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8])
{
	bool isLegal = true;

	if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour)
		isLegal = false;
	if (whoToMove)
	{
		if (wasX < 0 || wasX >= 8 || wasY < 0 || wasY >= 8 || willX < 0 || willX >= 8 || willY < 0 || willY >= 8) {
			return false;
		

		std::string piece = board1[wasX][wasY];
		if (pieceColour && piece[0] != 'W') {
			return false;
		}
		else if (!pieceColour && piece[0] != 'B') {
			return false;
		}

		std::string targetPiece = board1[willX][willY];
		if (targetPiece != "OO" && targetPiece != "XX" && (pieceColour == (targetPiece[0] == 'W'))) {
			return false;
		}

		if (abs(wasX - willX) != abs(wasY - willY)) {
			return false;
		}

		int dx = (willX > wasX) ? 1 : -1;
		int dy = (willY > wasY) ? 1 : -1;
		int x = wasX + dx;
		int y = wasY + dy;
		while (x != willX && y != willY) {
			if (board1[x][y] != "OO" && board1[x][y] != "XX") {
				return false;
			}
			x += dx;
			y += dy;
		}

		return true;
			}
		

	}
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
