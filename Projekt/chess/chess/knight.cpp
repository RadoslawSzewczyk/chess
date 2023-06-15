# include "piece.h"

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



bool knight::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int whichT)
{
    bool isLegal = true;
    if (whichT == 99)
        isLegal = false;
    if (willX > 8 || willX < 1 || willY > 8 || willY < 1)
        isLegal = false;
    if (board1[wasX][wasY] == "OO" || board1[wasX][wasY] == "XX" || whoToMove != pieceColour)
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
    if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) {
        isLegal = true;
    }
    else {
        isLegal = false;
    }

    if (!isLegal)
    {
        std::cout << "That is illegal move" << std::endl;
        return 1;
    }
    else
        return 0;
}

void knight::move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector<std::shared_ptr<piece>>& pieceTab, int which)
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

knight::~knight()
{
    ;
}