# include "piece.h"

char queen::typeCharF()
{
    return typeChar = 'Q';
}

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



bool queen::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int whichT, bool print)
{
    char whoToMoveC;
    if (whoToMove)
        whoToMoveC = 'B';
    else
        whoToMoveC = 'W';
    bool isLegal = true;
    std::string targetPiece = board1[willX][willY];

    if (whichT == 99)
        isLegal = false;

    if (willX > 7 || willX < 0 || willY > 7 || willY < 0)
        isLegal = false;

    if (board1[wasX][wasY][0] == targetPiece[0]) {
        isLegal = false;
    }

    if (wasX != willX && wasY != willY && abs(wasX - willX) != abs(wasY - willY)) {
        isLegal = false;
    }

    else if (wasX == willX) {
        int start = std::min(wasY, willY) + 1;
        int end = std::max(wasY, willY);
        for (int y = start; y < end; ++y) {
            if (board1[wasX][y] != "OO" && board1[wasX][y] != "XX") {
                isLegal = false;
                break;
            }
        }
    }
    else if (wasY == willY) {
        int start = std::min(wasX, willX) + 1;
        int end = std::max(wasX, willX);
        for (int x = start; x < end; ++x) {
            if (board1[x][wasY] != "OO" && board1[x][wasY] != "XX") {
                isLegal = false;
                break;
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
                isLegal = false;
                break;
            }
            x += dx;
            y += dy;
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




queen::~queen()
{
    ;
}