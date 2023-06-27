# include "piece.h"

char knight::typeCharF()
{
    return typeChar = 'N';
}

knight::knight(int xC, int yC, bool colourC)
{
    x = xC;
    y = yC;
    colour = colourC;
    if (colourC)
    {
        nameSTR = "BN";
    }
    else
    {
        nameSTR = "WN";
    }
}



bool knight::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int whichT, bool print)
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
    char temp = 'W';
    if (pieceColour == 1)
        temp = 'B';
    if (targetPiece != "OO" && targetPiece != "XX" && targetPiece[0] == temp) {
        isLegal = false;
    }

    int dx = abs(wasX - willX);
    int dy = abs(wasY - willY);
    if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1)))
    {
        isLegal = false;
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


knight::~knight()
{
    ;
}