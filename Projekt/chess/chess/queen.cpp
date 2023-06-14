# include "piece.h"

queen::queen(int xC, int yC, bool colourC)
{
	x = xC;
	y = yC;
	colour = colourC;
	if (colourC)
	{
		nameSTR = "BQ";
	}
	else
	{
		nameSTR = "WQ";
	}
}



bool queen::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int whichT)
{



	if (whichT == 99)
        return false;

	if (willX > 8 || willX < 1 || willY > 8 || willY < 1)
        return false;

	if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour)
        return false;


    std::string targetPiece = board1[willX][willY];
    if (targetPiece != "OO" && targetPiece != "XX" && (pieceColour == (targetPiece[0] == 'W'))) {
        return false;
    }

    if (wasX != willX && wasY != willY && abs(wasX - willX) != abs(wasY - willY)) {
        return false;
    }

    if (wasX == willX) {
        int start = std::min(wasY, willY) + 1;
        int end = std::max(wasY, willY);
        for (int y = start; y < end; ++y) {
            if (board1[wasX][y] != "OO" && board1[wasX][y] != "XX") {
                return false;
            }
        }
    }
    else if (wasY == willY) {
        int start = std::min(wasX, willX) + 1;
        int end = std::max(wasX, willX);
        for (int x = start; x < end; ++x) {
            if (board1[x][wasY] != "OO" && board1[x][wasY] != "XX") {
                return false;
            }
        }
    }
    else {
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
    }
    return true;
}

void queen::move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector<std::shared_ptr<piece>>& pieceTab, int which)
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

queen::~queen()
{
    ;
}