# include "piece.h"

char bishop::typeCharF()
{
	return typeChar = 'B';
}

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


bool bishop::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int whichT)
{
    char whoToMoveC;
    if (whoToMove)
        whoToMoveC = 'B';
    else
        whoToMoveC = 'W';
    bool isLegal = true;

    if (whichT == 99)
    {
        isLegal = false;
    }

    if (willX > 8 || willX < 1 || willY > 8 || willY < 1)
        isLegal = false;

    if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour || board1[willX][willY][0] == whoToMoveC)
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
        if (board1[x][y] != "OO" && board1[x][y] != "XX") {
            isLegal = false;
            break;
        }
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


bishop::~bishop()
{
}
